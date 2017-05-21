/* Guildmaster del gremio de guerreros.
   Izet@simauria.
*/
#define KILLS 100
#include "path.h"
#include <guild.h>
#include <properties.h>
#define NAME capitalize(getuid(TP))

inherit KBASE;

num() {
return TP->QueryAttribute("asesino");
}
create() {
      ::create();
  SetStandard("Thualin","enano",([ GC_GUERRERO: 80]),GENDER_MALE);
  SetShort("Thualin, el antiguo Avatar de Kholiak");
  SetLong(
"Ves a Thualin, maestro en el gremio de los guerreros y antiguo Avatar del\n"
"dios Kholiak en las vetustas guerras contra el reino de los orcos, Akallab.\n"
"Su cara esta marcada con cicatrices y un parche cubre su ojo derecho.\n"
"Es un enano bastante viejo, y de sus rizadas barbas cuelgan falanges de\n"
"los dedos de los orcos que una vez sucumbieron bajo su hacha.\n");
  SetAlign(1000);
  SetIds(({"thualin","avatar"}));
  SetHands( ({ ({"mano derecha",0,4}),({"mano izquierda",0,4}) }) );
  SetAC(3);
  SetWhimpy(0);
  InitAChats(4,({
"Thualin se abalanza sobre ti, y hunde su hacha en medio de tu pecho.\n"}) );
/*  AddItem("/std/weapon",REFRESH_REMOVE,
    ([P_SHORT:"un hacha a dos manos",
      P_LONG:
"Esta es el hacha de Thualin. Esta fabricada en un ligero metal, que los elfos llaman\n"
"mithril, y sus afiladas hojas han sido pulidas a conciencia.\n",
       P_WEIGHT:5000,
        P_WC:7,
       P_VALUE:10000,
       P_SIZE:P_SIZE_MEDIUM,
       P_RESET_QUALITY: 100,
       P_IDS:({"hacha","hacha a dos manos"}),
       P_GENDER:GENDER_FEMALE,
       P_NUMBER_HANDS:2,
       P_MATERIAL:M_MITHRIL,
       P_WEAPON_TYPE:WT_ESPADA,
       P_DAM_TYPE:DT_SLASH]),SF(wieldme));
  AddItem("/std/armour",REFRESH_REMOVE,
    ([P_SHORT:"una armadura de placas",
      P_LONG:
"Es una imponente armadura de placas. Ha sido pulida concienzudamente\n"
"hasta armatener un brillo espectacular en su superficie. Es muy ligera para\n"
"ser una armadura de placas, seguramente debido al metal con el que ha sido\n"
"fabricada.\n",
      P_IDS:({"armadura","placa","placas","armadura placas","armadura de placas"}),
      P_VALUE:3000,
      P_WEIGHT:10000,
      P_AC:5,
      P_SIZE:P_SIZE_MEDIUM,
      P_RESET_QUALITY:100,
      P_GENDER:GENDER_FEMALE,
      P_MATERIAL:M_MITHRIL,
      P_ARMOUR_TYPE:AT_MAIL]),SF(wearme)); */
}

init() {
   ::init();
/*
       call_out("Atacar",2);
*/
}
Atacar() {
     if (TP->QueryAttribute("asesino") > KILLS) {
        tell_room(environment(TO),
"Thualin dice: Eh tu! "+NAME+"! Reconozco ese rostro vil y despiadado!\n"
"                Has asesinado a "+num()+" habitantes de la ciudad!\n"
"                Pagaras con tu vida las de todos ellos!!!\n");
         TO->Kill(TP);
         return 1;
      }
}
public varargs void Die(mixed silent) {
  tell_room(environment(TO),
    "Thualin dice: Argh! Muero! Pero no escaparas de la ciudad con vida!\n");
    TP->SetAttribute("asesino",TP->QueryAttribute("asesino")+1);
    ::Die(silent);
}
