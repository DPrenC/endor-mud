/* Guardias de EL FEO.
   Izet@simauria.
   Gorthem
   [Woo] Modificado, y otra vez
*/
#include "path.h"
#include <guild.h>
#include <properties.h>
#include <combat.h>
#define KILLS 20

inherit GBASE;

num() {
return TP->QueryAttribute("asesino");
}
create() {
       ::create();
  SetStandard("el guardián de la Puerta","enano",([GC_LUCHADOR: 30]),GENDER_MALE);
  SetShort("el guardian de la Puerta");
  SetLong(
"Ves a un guardia jorobado que se encarga de la apertura de la Puerta a la ciudadela.\n"
"Vigila quien entra o quien sale, siempre ojo avizor.\n"
"Tiene poder para ello, lleva un galon que indica algun rango.\n");
  SetAlign(200);
  SetIds(({"guardián","guardian","guarda","guardia"}));
   SetAds(({"un","el"}));
   SetHands( ({ ({"mano derecha",0,2}),({"mano izquierda",0,1}) }) );
   SetAC(1);
  SetGoChance(0);
  SetWhimpy(20);
  AddQuestion(({"puerta","puertas"}),
    "El guardia dice: Soy el encargadao de abrir y cerrar las puertas.\n");
  InitChats(7,({
    "El guardia dice: Los orcos no deben entrar en Kha-annu.\n",
      "El guardia dice: Circule por favor.\n",
      "El guardia dice: No te quedes aqui parado. Entras o sales?\n"}));
  AddItem("/std/weapon",REFRESH_REMOVE,
    ([P_SHORT:"un martillo",
        P_LONG:"Es un martillo normal, fabricado en piedra y con mango de madera.\n",
       P_WEIGHT:7000,
       P_WC:2,
       P_NUMBER_HANDS:2,
       P_VALUE:10,
      P_SIZE:P_SIZE_MEDIUM,
      P_RESET_QUALITY: 100,
      P_IDS:({"martillo","martillo de guerra"}),
      P_WEAPON_TYPE: WT_MAZA,
       P_DAM_TYPE: DT_BLUDGEON]), SF(wieldme));
  AddItem("/std/armour",REFRESH_REMOVE,
    ([P_SHORT:"una cota de malla",
      P_LONG:
"Es una cota de malla normal, aunque lo suficientemente buena como para\n"
"salvar al que se la ponga de mas de un golpe mortal.\n",
      P_IDS:({"cota","cota malla","malla","cota de malla"}),
      P_VALUE:30,
      P_WEIGHT:2000,
      P_AC:4,
      P_SIZE:P_SIZE_MEDIUM,
      P_RESET_QUALITY: 100,
      P_GENDER:GENDER_FEMALE,
      P_ARMOUR_TYPE:AT_MAIL]),SF(wearme));
}

init() {
   ::init();
   if (TP->QueryInvis() != 1) {
      if (TP->QueryAttribute("asesino") <= KILLS &&
          TP->QueryAttribute("asesino") > 0) {
        say("El guardian dice: "+
capitalize(getuid(TP))+", cuida tus acciones. El asesinato se castiga en esta ciudadela.\n");
        return 1;
      }
      if (TP->QueryAttribute("asesino") > KILLS) {
       call_out("Atacar",2);
      }
   }
}
Atacar() {
        tell_room(environment(TO),
"El guardia dice: Eh tu! "+capitalize(getuid(TP))+"! Reconozco ese rostro vil y "
"El guardian dice: Aja! Te he atrapado "+capitalize(getuid(TP))+"!!! AHORA PAGARAS!\n"
"                  Has asesinado a "+num()+" habitantes de la ciudadela!\n"
 "                   Tu cabeza sera recompensa suficiente como venganza!!!\n");
     call_out("Ataque",4);
     return 1;
}

Ataque() {
         TO->Kill(TP);
         return 1;
}
public varargs void Die(mixed silent) {
  tell_room(environment(TO),
    "El guardian tose y clava una mirada de fuego en tus ojos.\n");
    TP->SetAttribute("asesino",TP->QueryAttribute("asesino")+1);
  ::Die(silent);
}
