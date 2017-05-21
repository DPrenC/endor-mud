/* Guardias de Kha-annu.
   Izet@simauria.
   Gorthem para su mazmorra. 4-6-98
   [Woo] Modificado
*/
#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
#define KILLS 10
inherit GBASE;

num() {
return TP->QueryAttribute("asesino");
}
create() {
 ::create();
  SetStandard("un guardia","enano",([ GC_LUCHADOR: 35]),GENDER_MALE);
  SetShort("el vigilante de la mazmorra");
  SetLong(
"Este es el mazguar de las mazmorras. Se encarga de vigilar que los prisioneros\n"
"no armen jaleos en sus celdas, y evita toda posible fuga.\n");
  SetAlign(200);
  SetIds(({"mazguar","vigilante"}));
   SetAds(({"un","el"}));
  SetGoChance(0);
  SetWhimpy(0);
  AddQuestion(({"espada","rey","Belthain","preocupacion","preocupación"}),
    "El vigilante te observa escrupulosamente.\n"
     );
  InitChats(7,({
   "El vigilante dice: Puedes dar una vuelta por las mazmorras... a ver que haces.\n",
   "El vigilante observa cada uno de tus movimientos.\n",
     "El vigilante dice: Venga, largo de aqui...\n",
     "El vigilante frunce el ceño.\n",
     "El vigilante te otorga una falsa sonrisa.\n",
    }));
  AddItem("/obj/money",REFRESH_REMOVE,
(["Money": (["oro":15, "plata":random(10), "cobre":random(30) ]) ]) );
  AddItem("/std/weapon",REFRESH_REMOVE,
    ([P_SHORT:"un hacha de mano",
      P_LONG:"Es un hacha de mano normal, hecha de hierro.\n",
       P_WEIGHT:1000,
       P_WC:4,
      P_VALUE:5,
      P_SIZE:P_SIZE_MEDIUM,
      P_RESET_QUALITY: 100,
      P_IDS:({"hacha","hacha de mano","hacha mano"}),
      P_WEAPON_TYPE:WT_HACHA,
      P_DAM_TYPE:DT_SLASH]),SF(wieldme));
  AddItem("/std/armour",REFRESH_REMOVE,
    ([P_SHORT:"una cota de malla",
      P_LONG:
"Es una cota de malla normal, aunque lo suficientemente buena como para salvar\n"
"al que se la ponga de más de un golpe mortal.\n",
      P_IDS:({"cota","cota malla","malla","cota de malla"}),
      P_VALUE:30,
      P_WEIGHT:2000,
     P_AC:4,
      P_SIZE:P_SIZE_MEDIUM,
      P_RESET_QUALITY: 100,
      P_ARMOUR_TYPE:AT_MAIL]),SF(wearme));
}

init() {
   ::init();
      if (TP->QueryAttribute("asesino") > KILLS) {
       call_out("Atacar",2);
      }
}
Atacar() {
        tell_room(environment(TO),
"El guardia dice: ¡Eh tu "+capitalize(getuid(TP))+"! Reconozco ese rostro vil y "
"despiadado!\n"
"                   ¡Has asesinado a "+num()+" habitantes de la ciudad!\n"
"                   ¡¡¡Pagarás con tu vida las de ellos!!!\n");
     call_out("Ataque",4);
     return 1;
}

Ataque() {
         TO->Kill(TP);
         return 1;
}
public varargs void Die(mixed silent) {
  tell_room(environment(TO),
    "El oficial dice: Argh! Muero! Pero no escaparas de la ciudad con vida!\n");
    TP->SetAttribute("asesino",TP->QueryAttribute("asesino")+1);
  ::Die(silent);
}
