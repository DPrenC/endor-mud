/*********************************************************************/
/* Creado por Nemesis@Simauria.                                      */
/* Modificado por Izet@simauria, para usarlo en el quest de Kha-annu */
/* [Woo] Modificado                                                  */
/*********************************************************************/

#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
#include <colours.h>
#define KILLS 30
#define NAME capitalize(getuid(TP))
inherit KBASE;
num()
{
    return TP->QueryAttribute("asesino");
}

string informa()
{
    if (TP->QueryAttribute("sabepiedra")) return "Belthain sonríe malvadamente, se inclina hacia ti y te "
            "dice: Así que tú eres otro de esos aventureros ambiciosos "
            "que buscan riqueza fácil, ¿eh? Pues te aseguro que esta vez "
            "te has equivocado. Sí, tuvimos una mina de gemas en los dominios de Sherek, y "
            "esos estúpidos clérigos nunca se enteraron. Los humanos no son demasiado agudos "
            "para esas cosas. Claro que aún no se habían establecido allí, ellos llegaron "
            "mucho después, cuando la guerra de..., pero bueno, eso no importa. Ahora sólo han "
            "oído hablar de ellas, como todos. Siéntate un momento, te contaré la historia... "
            "¿No quieres sentarte? Da igual. Escucha:\nComo te digo, teníamos una mina en "
            "aquella montaña, una mina de topacios, ¿sabes?, muy rica, se encontraban vetas "
            "enormes y productivas, y los nuestros se enriquecían y prosperaban.\nPero el "
            "esplendor que alcanzaban fué el principio del fin. Un día apareció por aquellos "
            "territorios una tribu de demonios. Ellos no son ni fueron nunca buenos mineros, "
            "pero venían en manadas, saqueaban los almacenes y asesinaban a los nuestros para "
            "robarles.\nPor aquel entonces había en el dominio de Simauria un grupo de hombres "
            "muy sabios, grandes magos y conocedores del pasado, el presente y el futuro, y "
            "finalmente, tras años de dura lucha, con miles de muertos por ambas partes, "
            "decidimos acudir a ellos y pedirles ayuda.\nY vinieron. Con su ciencia mágica y "
            "su habilidad en la lucha unida a la nuestra, conseguimos vencer y casi exterminar "
            "a los demonios.\nPero aquellos hombres eran muy buenos, altamente espirituales y "
            "sensibles, amantes de la vida y el universo. No soportaron aquella horrible "
            "masacre. Dijeron: 'Esto es culpa de la avaricia de los mortales. Jamás volverá a "
            "producirse un acto tan vil en este lugar.'\nY maldijeron la montaña que se volvió "
            "estéril, jamás aparecerá una veta de gemas allí. Luego nos pidieron que selláramos "
            "la entrada, y con su poder mágico hundieron la franja de tierra que permitía "
            "acceder a la mina, junto al río que pasa cerca, y pusieron un escudo mágico a "
            "toda la montaña, de forma que ni por la fuerza ni por la magia es ni será posible "
            "entrar en ella.\nPero, y esto tal vez sea leyenda, se dice que algunos demonios "
            "supervivientes fueron dejados allí, condenados a ser guardianes de lo poco que "
            "quedara, y tal vez, algunos descendientes de aquellos sobrevivan allí, "
            "manteniéndose de ratas y murciélagos...\nEl caso es que ahora esa montaña está en "
            "los dominios de los monjes de Sherek, que en principio fueron hombres buenos como "
            "aquellos otros, pero... En fin, ellos también estuvieron algún tiempo buscando la "
            "mina, y sin embargo... ¡Ji, ji, ji! Los muy idiotas la tienen bajo sus narices..., "
            "o bajo sus pies.\n¿Sabes lo gracioso? Están sacando bloques de piedra justo "
            "encima. ¡Los muy torpes han abierto una cantera en la montaña!\Seguro que no han "
            "visto la entrada, estaba bien protegida...\n";
    return "El rey te mira sospechoso, y apuntándote con el dedo te advierte: "
        "¿Minas? Ni se te ocurra ir a saquear nuestras minas, o te aseguro "
        "que lo pagarás.\n";
}

create()
{
    ::create();
   enable_commands();
    SetStandard("Belthain","enano",([GC_LUCHADOR: 50]),GENERO_MASCULINO);
    SetShort("Belthain, Señor de los Enanos");
    SetLong("Este es Belthain, el señor de los Enanos. Va vestido con ricos "
        "ropajes bordados en oro. En su cabeza ves una enorme corona de "
        "mithril, y sus dedos están llenos de anillos de toda clase de "
        "metales y piedras preciosas.\n");
    SetAlign(1000);
    SetIds(({"belthain","senyor","rey"}));
    SetWhimpy(0);
    InitAChats(4,({
        "Belthain intenta clavar su espada en tu pecho, pero solo llega a rozarte.\n"}));
    AddItem("/obj/money",REFRESH_REMOVE,
        (["Money": (["oro":random(5)]) ]) );
    AddItem("/std/weapon",REFRESH_REMOVE,
        ([P_SHORT:"una espada larga",
        P_LONG:"Es la espada larga de Thualin. La espada está hecha de un "
                "ligero metal, y su afilada hoja reluce brillantemente.\n",
        P_WEIGHT:2000,
        P_WC:6,
        P_VALUE:500,
        P_SIZE:P_SIZE_MEDIUM,
        P_RESET_QUALITY: 100,
        P_IDS:({"espada","espada larga"}),
        P_WEAPON_TYPE:WT_ESPADA,
        P_MATERIAL:M_MITHRIL,
        P_DAM_TYPE:DT_SLASH]),SF(wieldme));
    AddItem("/std/armour",REFRESH_REMOVE,
        ([P_SHORT:"una armadura de placas",
        P_LONG:"Es una imponente armadura de placas. Ha sido pulida "
                "concienzudamente hasta obtener un brillo espectacular en su "
                "superficie.\nEs muy ligera para ser una armadura de placas, "
                "seguramente debido al metal con el que ha sido fabricada.\n",
        P_IDS:({"armadura","placa","placas","armadura placas","armadura de placas"}),
        P_VALUE:1000,
        P_WEIGHT:10000,
        P_AC:12,
        P_SIZE:P_SIZE_MEDIUM,
        P_RESET_QUALITY:250,
        P_MATERIAL:M_MITHRIL,
        P_ARMOUR_TYPE:AT_MAIL]),SF(wearme));
    AddQuestion(({"mina","minas"}),SF(informa),1);
    AddQuestion(({"espada","sabandija","caos","hombre lagarto"}),"Belthain "
        "dice: ¿También te interesa recuperar mi espada? ¡Está bien!\n"
        "Ofrezco una cuantiosa recompensa de 10 monedas de mithril al que "
        "recupere la espada de mi familia. Un hombre-lagarto adorador de "
        "demonios la robó hace años. Ahora sabemos que se escondió en las "
        "antiguas cloacas de la ciudad. Quizá encuentres un plano de ellas "
        "en la biblioteca. ¡Si recuperas la espada, la recompensa será tuya!\n");
}

init()
{
    ::init();
    call_out("Atacar",2);
    call_out("HacerQuest",1);
}

Atacar()
{
    if ((QUESTMASTER->QueryQuestSolved("find_sword",TP)) || ((TP->QueryAttribute("sabepiedra")) && (!TP->QueryAttribute("sabeminas"))))
    {
        return 1;
    }
    if (TP->QueryAttribute("asesino") > KILLS) {
        tell_room(environment(TO),"Belthain dice: ¡Eh tú! "+NAME+" ¡Mis "
            "guardias estaban tras tus huellas!\n¡¡¡Has asesinado a "+num()+
            " habitantes de mi ciudadela!!!\n¡¡¡Tu sangre apagará la sed de "
            "venganza de mi pueblo!!!\n");
        TO->Kill(TP);
        return 1;
    }
}

public varargs void Die(mixed silent)
{
    tell_room(environment(TO),"Belthain dice: Se me escapa la vida... ATJO, "
        "ATJO... ¡pero TU morirás!\n");
    TP->SetAttribute("asesino",TP->QueryAttribute("asesino")+1);
    ::Die(silent);
}



HacerQuest() {

object p;


p=present("espada_de_belthain",TP);

if (p) {
 if (QUESTMASTER->QueryQuestSolved("find_sword", TP)) {
  tell_object(TP,
"Belthain te mira.\n"
"Belthain dice: Ya has recuperado mi espada! Te estoy muy agradecido, y\n"
"               tus crimenes seran perdonados.\n");
   write_file (QUEST+"SWORDFINDERS",ctime(time())+TP->QueryRealName()+" ["+
            TP->QueryLevel()+"]   Ha devuelto de nuevo su espada a Belthain.\n");
  p->remove();
  return 1;
 }
 tell_object(TP,
"Belthain se levanta de su sillon exclamando:\n"
"'Oh, muchisimas gracias! Has recuperado mi espada!!! La recompensa es\n"
"toda tuya! Tus delitos en Kha-annu seran perdonados'\n");
 QUESTMASTER->qshout(TC_BOLD TC_GREEN"[QUEST]"TC_NORMAL+" "+
 TP->QueryName()+" ha recuperado la espada de Belthain.\n");
 p->remove();
 QUESTMASTER->SetPlayerQuest("find_sword",TP);
 TP->SetAttribute("asesino",0);
 tell_object(TP,"Has resuelto el quest de la espada de Belthain. FELICIDADES.\n");
 write_file (QUEST+"SWORDFINDERS",ctime(time())+" "+TP->QueryRealName()+" ["+
 TP->QueryLevel()+"]   Ha encontrado la espada de Belthain.\n");
 (TP->QueryGender()==GENDER_FEMALE?SetTitle("la amiga del Senyor de los Enanos"):SetTitle("el amigo del Senyor de los Enanos"));
 write_file (QUEST+"SWORDFINDERS",ctime(time())+" "+TP->QueryRealName()+" ["+
            TP->QueryLevel()+"]   Ha encontrado la espada de Belthain.\n");
 return 1;
}
}
