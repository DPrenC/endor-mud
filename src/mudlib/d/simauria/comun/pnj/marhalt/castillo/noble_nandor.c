/****************************************************************************
Fichero: noble_nandor.c
Autor: Ratwor
Fecha: 19/08/2006
Descripción: el noble de la villa de Nandor.
Comentarios:
mira todo lo que está a su alrededor aleatoria y personalmente.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
inherit NPC;
inherit GUARD;
public string f_mira();
int ayuda;
create()
{
    "*"::create();

    SetStandard("Rocher", "humano", ([GC_LUCHADOR:70]), GENDER_MALE);
    AddId(({"noble", "tirano", "señor", "Rocher", "rocher"}));
    SetShort("rocher Dhes-Bláin, el Señor de Nandor");
    SetLong("Se trata de un humano de imponente estampa. Su cuerpo de una gran altura y "
    "tremenda corpulencia, la cual no ha menguado a pesar del transcurrir de los años, "
    "está coronado por un pétreo rostro de prominentes pómulos y mandívula, que "
    "está adornado por unas sonrosadas megillas y presidido por un gran bigote que cuelga "
    "luengo hasta su mentón, contrastando con una leonina cabellera azabache matizada "
    "de plata sobre las sienes.\n   El aspecto general destaca sobremanera con unos "
    "undidos y diminutos ojillos que se mueven vidriosos de manera excrutadora.\n");
    SetSmell("Huele a sudor que echa para atrás.\n");
    SetStr(QueryStr()+5);
    SetCitizenship("nandor");
    SetWeight(90000);
    Set(P_CANT_LURE,1);
    InitChats(4, ({"El noble respira profundamente.\n",
        "Rocher te dice: ¿Qué vienes a pedirme?\n",
        "Rocher mira ligeramente a su alrededor con aires de superioridad.\n",
        "Rocher refunfuña: este maldito cocinero está tardando mucho.\n",
        "El noble se acaricia el bigote con elegancia y satisfacción.\n",
        "EL noble tiene una mirada muy segura de sí mismo.\n", SF(f_mira)}));
    InitAChats(15, ({"Rocher grita: ¡te voy a destrozar plebeyo!.\n",
        "El noble grita: ¡¿Cómo te atreves a mirarme si quiera?!\n",
        "El noble grita: ¡Guardias, guardias!\n",
        "Rocher grita: ¡tú no eres nadie y te voy a reventar!\n"}));

    AddQuestion(({"villa", "castillo", "nandor"}), "Rocher dice: todo es mío, soy el "
        "señor de la villa de Nandor, castillo y alrededores.\n A mi antepasado, el gran"
        " guerrero Cónor Dhes-Bláin,    Como recompensa a sus meritórios actos, se le "
        "concedió el título de Señor de las tierras de nandor.\n Y por tanto, con el paso "
        "de los años, ha llegado a mí como heredero directo.\n");
    AddQuestion(({"antepasado", "gran guerrero", "Cónor Dhes-Bláin", "cónor dhes-bláin",
         "cónor", "Cónor"}), "Rocher dice: Durante las largas guerras que enfrentaron "
         "a humanos con los moustros del mal, mi antepasado destacó en las batallas "
         "libradas en las montañas del noroeste de simauria, su nombre era Cónor Dhes-Bláin.\n"
         " Como recompensa a sus meritórios actos se le concedió el título de Señor de "
         "las tierras de nandor. Al oeste de las cuales construyó este robusto castillo "
         "para defender sus tierras de futuras invasiones.\n A pesar del objetivo "
         "defensivo del castillo Cónor dotó al mismo de lujos suficientes para que su "
         "familia pudiera vivir confortáblemente.\n");

    AddQuestion(({"su hija", "hija", "sherilin"}), "Rocher te dice: ¿Qué demonios "
        "quieres de mi hija?, déjala en paz u ordeno que te apresen en los calabozos.\n",1);
    AddQuestion(({"impuestos", "impuesto", "tasas", "tasa"}), "El noble dice: nada"
        ", poca cosa, no me gusta apretar mucho a la burguesía.\n");

    AddItem(PROTNANDOR("armadura_noble"),REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("yelmo_noble"),REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("botas_noble"),REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("grebas_noble"),REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("guanteletes_noble"),REFRESH_REMOVE, SF(wearme));
    AddItem(ARMANANDOR("espada_noble"), REFRESH_REMOVE, SF(wieldme));
    AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["oro":d10(2)])]));
    if (d4()==1)
          AddItem(PROTNANDOR("anillo_noble"),REFRESH_REMOVE, SF(wearme));
}

public string f_mira()
{
    string *gestos =
        ({"inquisidoramente", "con mala cara", "con superioridad", "con la cabeza levantada",
        "fijamente", "con desprecio", "con dureza"});

    object *a_mirar = filter(all_inventory(environment()) - ({TO}), (:living($1):));
    object elegido = a_mirar[random(sizeof(a_mirar))];
    tell_room(environment(), "Rocher mira " + gestos[random(sizeof(gestos))] + " a " + elegido->QueryShort() +
        ".\n", ({elegido}));
    tell_object(elegido, "Rocher te mira " + gestos[random(sizeof(gestos))] + ".\n");
    return "";
}

public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras)
{
    object guardias;
    int i;
    int cantidad=d3(2);
    if(!ayuda){
        ayuda=1;
        tell_room(environment(TO), QueryName()+" grita eufóricamente:\n "
        "¡Guardias!, ¡nos atacan!\n Junto a un gran estruendo de choques de armas y "
        "armaduras, acuden "+cantidad+" hombres de armas en auxilio a su señor.\n");
        for (i = 0;i<cantidad;i++) { 
            guardias= clone_object(PNJ("marhalt/castillo/hombre_armas"));
            guardias->move(environment(TO));
        }
    }
    return ::Defend(dam, dam_type, flags, &xtras);  
}
        