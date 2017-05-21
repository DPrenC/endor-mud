/****************************************************************************
Fichero: guardia_noble.c
Autor: Ratwor
Fecha: 08/12/2007
Descripci�n: la guardia ersonal del noble.
****************************************************************************/
#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <skills.h>
inherit NPC;
inherit GUARD;
create()
{
    "*"::create();
    SetStandard("un guardia", "humano", ([GC_LUCHADOR:50+d4()]),  GENDER_MALE);
    SetShort("Un guardia");
    SetLong("�ste guardia es uno de los hombres de confianza de Rocher Dhes-Bl�in, "
    "sirvi�ndole como emisario y escolta. Al mirarlo detenidamente, notas en sus rasgos "
    "un cierto parecido con su se�or, lo que puede dar a entender que por sus venas "
    "corre la misma sangre, algo bastante probable, teniendo en cuenta que los "
    "Dhes-Bl�in no solo son conocidos por sus haza�as y su f�rreo gobierno, si no "
    "tambi�n por la multitud de descendientes bastardos que han tenido a lo largo "
    "de los a�os.\n");
    AddId(({"guardia", "hombre", "humano"}));
    SetWeight(84100);
    SetAlign(80);
    SetWhimpy(5);
    InitChats(3, ({"El guardia apresta su espada mientras te mira con gesto serio, al "
        "parecer no le inspiras confianza.\n",
        "El guardia se ajusta el casco.\n",
        "El guardia se mantiene erguido y alerta.\n",
        "El guardia examina complacido su larga espada.\n",
        "El guardia te dice: No te quedes ah� plantado, exp�n a mi se�or el motivo de "
        "tu visita o l�rgate!\n �Y m�s vale que lo trates con respeto, o tu cabeza "
        "clavada en una lanza adornar� las almenas.\n",
        "El guardia se ajusta el gran escudo al brazo.\n"}));
    InitAChats(12, ({"El guardia alza su gran escudo para defenderse.\n",
        "El guardia se adelanta cubri�ndose con el escudo mientras lanza una serie de "
        "precisos tajos con su espada.\n",
        "El guardia grita: �Aqu� soldados! �Se est� vertiendo sangre en la misma sala "
        "de nuestro se�or! �Por Rocher Dhes-Bl�in!\n",
        "El guardia se abalanza hacia adelante enarbolando su espada sobre la "
        "cabeza para a continuaci�n dejarla caer con todas sus fuerzas.\n",
        "El guardia lanza un ataque con la parte inferior del escudo.\n",
        "El guardia grita: �Tu cabeza adornar� las murallas como advertencia para los "
        "enemigos del reino!\n"}));
    SetSmell("Huele a sudor rancio, grasilla capilar, y ropa que no ha visto un buen "
    "lavado en mucho tiempo.\n");
    SetCitizenship("nandor");
    Set(P_CANT_LURE,1);
    SetGuardDefendMsg("Inmediatamente  el guardia  desenvaina su espada con gran "
    "presteza mientras grita con voz tonante:\n �Maldito asesino, no hay perd�n "
    "para los que derraman sangre en �ste castillo!\n  �Disp�nte a morir, villano!");
    AddSkill(HAB_ESCUDO, 90, P_DEX);
    SetDex(QueryDex()+5);
    AddQuestion(({"hija", "Sherilin", "sherilin"}), "El guardia se sobresalta mirando de reojo a Rocher.\n"
    "El guardia exclama r�pidamente: S�, Sherilin. Ese es el nombre de la hija de mi "
    "se�or, por lo cual se le debe un respeto,  y si tu irrespetuosa lengua no se est� "
    "quieta, te quedar�s sin ella y recibir�s una docena de latigazos de propina, as� "
    "que, !d�jame en paz, y no me preguntes mas!\n");
    AddQuestion(({"su se�or", "se�or", "rocher", "Rocher"}), "el hombre adopta una postura "
    "marcial mientras dice: Mi se�or Rocher Dhes-Bl�in es un gran guerrero y un hombre "
    "justo, digan lo que digan esos campesinos. Cuando yo era j�ven me eligi� de entre "
    "los aldeanos por mi fuerza y valor para servirlo, y gracias a �l llevo la vida de "
    "un hombre de armas, en vez de estar segando trigo como un esclavo sin hombr�a.\n"
    "Es heredero de una larga l�nea de guerreros, y si no fuera por su defensa de la "
    "frontera norte de nuestro reino, tiempo ha que los malhechores de Cored y las "
    "criaturas de las monta�as habr�an devastado �stas tierras y avanzado hasta Ihstria.\n");
    AddQuestion(({"Cored", "bandidos", "malhechores", "guarida"}), "El hombre te dice: \n"
    "Al nordeste de aqu� se encuentra un espeso bosque. No son buenas tierras de cultivo "
    "as� que  a nadie se le ocurri� desbrozarlo y se mantuvo como reserva de caza para "
    "los Dhes-Bl�in. Sin embargo, a medida que el reino se fue recuperando de las "
    "guerras, se comenz� a dar caza a todos aquellos que se saltaban las leyes: "
    "ladrones, bandidos, mercenarios, y gentuza de toda cala�a que hall� en �ste bosque "
    "un refugio seguro. Entonces, nadie sabe de donde, apareci� el peor de todos.\n"
    "Se hac�a llamar Cored y en poco tiempo se erigi� en cabecilla supremo, "
    "reconstruy� una antigua fortaleza abandonada siglos atr�s convirti�ndola en su "
    "guarida, y estableci� una fuerte disciplina en la banda, eligiendo a sus capitanes "
    "entre los mas h�biles de sus secuaces.\n"
    "Desde entonces no ha dejado de lanzar incursiones desde Enalel hasta Nandor, y en "
    "no pocas ocasiones hemos trabado batalla con sus hombres, aunque no tiene "
    "escr�pulos en incorporar orcos en sus filas.\n");
    SetShrugMsg("El guardia se inclina y dice con tono amenazante: �De manera que osas "
    "presentarte ante mi se�or con el exclusivo objetivo de hacer preguntas rid�culas?\n"
    "El guardia se iergue s�bitamente mientras grita:\n"
    "Fuera de aqu� vagabundo, �antes de que ordene que te azoten por tama�a osad�a.\n");
    AddItem(PROTNANDOR("botas_viejas"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("casco_ligero"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("cota_malla"), REFRESH_REMOVE, SF(wearme));
    AddItem(PROTNANDOR("gran_escudo"), REFRESH_REMOVE, SF(wearme));
    AddItem(ARMANANDOR("espada_larga"), REFRESH_REMOVE, SF(wieldme));

    AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["plata":d4(),"oro":d3()])]));
}
