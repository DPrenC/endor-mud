/* Guardias de Kha-annu.
   Izet@simauria.
   [Woo] Modificado
   [Nemesis] Insertadas obs y obduras tal y como deben ser.
             Cambiada el hacha por algo un poco más coherente.
*/
#include "path.h"
#include <guild.h>
#include <combat.h>
#include <moving.h>
#define KILLS 20

inherit GBASE;


num() {
return TP->QueryAttribute("asesino");
}
create() {
object ob;

       ::create();
 SetStandard("un Guardia Real","enano",([GC_LUCHADOR: 40]),GENDER_MALE);
  SetShort("un Guardia Real");
  SetLong(
"Es uno de los guardias personales de Belthain, rey de Kha-annu y Señor de los\n"
"enanos. Está totalmente firme, y sus barbas están bien peinadas.\n");
  SetWeight(70000);
  SetAlign(200);
  SetIds(({"guardia real"}));
  SetAds(({"un"}));
  SetWhimpy(0);
  AddQuestion(({"espada","rey","Belthain","preocupacion","preocupación","belthain"}),
    "El oficial dice: ¿Buscas también la espada de nuestro señor Belthain?\n"
    "            Todos la buscan por la recompensa.\n");

  AddItem("/obj/money",REFRESH_REMOVE,
 (["Money": (["oro": random(5), "cobre": random(10) ]) ]) );

 ob=clone_object("/std/weapon");
 ob->SetStandard(WT_HACHA, 8, P_SIZE_MEDIUM, M_ACERO);
 ob->SetShort("un hacha de batalla");
 ob->SetLong("Es un hacha de batalla de manufactura enana, lo que se nota\n"
               "en su afilada hoja y en las elaboradas filigranas que rodean\n"
               "su mango.\n");
  AddItem(ob,REFRESH_REMOVE,SF(wieldme));

 ob=clone_object("/std/armour");
 ob->SetStandard(AT_CORAZA, 5, P_SIZE_MEDIUM, M_ACERO);
 ob->SetShort("una cota de malla");
 ob->SetLong("Una cota de malla hecha de acero. Parece bastante buena, aunque\n"
              "no tanto como una coraza.\n");
 AddItem(ob,REFRESH_REMOVE,SF(wearme));

 ob=clone_object("/std/armour");
 ob->SetStandard(AT_ESCUDO, 4, P_SIZE_MEDIUM, M_ACERO);
 ob->SetShort("un escudo rectangular");
 ob->SetLong("Es un escudo de manufactura enana, lo que se nota en su\n"
              "bruñida superficie. El emblema de Kha-Annu brilla ligeramente\n"
              "en su centro.\n");
}

init() {
   ::init();
      if (TP->QueryAttribute("asesino") <= KILLS &&
          TP->QueryAttribute("asesino") > 0) {
        say("El guardia dice: "+
capitalize(getuid(TP))+", los asesinatos se castigan en Kha-annu.\n");
        return 1;
      }
      if (TP->QueryAttribute("asesino") > KILLS) {
       call_out("Atacar",2);
      }
}
Atacar() {
        tell_room(environment(TO),
"El guardia dice: Eh tu! "+capitalize(getuid(TP))+"! Reconozco ese rostro vil y "
"despiadado!\n"
"                   Has asesinado a "+num()+" habitantes de la ciudad!\n"
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
    "El oficial dice: ¡Argh! ¡Muero! ¡Pero no escaparás de la ciudad con vida!\n");
    TP->SetAttribute("asesino",TP->QueryAttribute("asesino")+1);
  ::Die(silent);
}

move(dest,method,stuff) // No puede salir de Kha-annu
{
 if(method==M_GO && dest->QueryLocate()!="Kha-annu")
    return ME_NO_ENTER;
        return ::move(dest,method,stuff);
        }

