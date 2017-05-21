/* Guardias de Kha-annu.
   Izet@simauria.
   Modificaciones por Gorthem para hacer guardias un pelin
   mas flojos para ponerlos por las calles :-))
   Retocados para que no acusen a una persona invisible. [Y] Yandros.
   IZet@Simauria, 4-Nov-1998.
      Los hice mucho mas flojos porke estaban demasiao bestias a mi parecer.
   Gorthem@Simauria 9-nov-98
      Poniendo el set locate pa que no se vayan en un viaje del inserso.
             ( A kentor)
   [Woo] Modificado
   [Nemesis] Insertadas las obs de la manera correcta.
*/
#define KILLS 20
#include "path.h"
#include <guild.h>
#include <moving.h>
#include <combat.h>


inherit GBASE;

num() {
  return TP->QueryAttribute("asesino");
}
create()
{
    object ob;
    ::create();

  SetStandard("un guardia","enano",([GC_LUCHADOR: 30]),GENDER_MALE);
  SetShort("un Soldado de la Guardia");
  SetLong(
"Es un soldado vestido con el uniforme de la guardia de Kha-annu.\n"
"No parece tener ningún rango.\n");
  SetAlign(200);
  SetIds(({"guardia","soldado","soldado de la guardia"}));
  SetAds(({"un"}));
  SetGoChance(0);
  SetWhimpy(30);
  AddQuestion(({"seguridad","ciudad","preocupacion"}),
    "El soldado dice: Espero que no hayan problemas hoy...\n"
    "            Hay que tener cuidado con los maleantes.\n");
  InitChats(4,({
    "El soldado dice: Parece todo tranquilo...\n",
    "El soldado dice: Circule por favor.\n",
    "El soldado dice: Me preocupa la seguridad de la ciudad.\n"}));

  ob=clone_object("/std/weapon");
  ob->SetStandard(WT_HACHA, 2+random(4), P_SIZE_MEDIUM, M_HIERRO);
  ob->SetShort("un hacha de mano");
  ob->SetLong("Un hacha de mano normal, hecha de hierro.\n");
  AddItem(ob,REFRESH_REMOVE,SF(wieldme));

  ob=clone_object("/std/armour");
  ob->SetStandard(AT_CORAZA, 4, P_SIZE_MEDIUM, M_CUERO);
  ob->SetShort("una cota de cuero");
  ob->SetLong("Una cota de cuero normal, que sin embargo te salvará de heridas\n"
               "superficiales.\n");
  AddItem(ob,REFRESH_REMOVE,SF(wearme));
}

init() {
   ::init();
   if (TP->QueryInvis() != 1) {
      if (TP->QueryAttribute("asesino") <= KILLS &&
          TP->QueryAttribute("asesino") > 0) {
        say("El soldado dice: "+
capitalize(getuid(TP))+", los asesinatos se castigan en Kha-annu.\n");
        return 1;
      }
      if (TP->QueryAttribute("asesino") > KILLS) {
       call_out("Atacar",2);
    }
  }
}
Atacar() {
        tell_room(environment(TO),
"El soldado dice: Eh tu! "+capitalize(getuid(TP))+"! Reconozco ese rostro vil y "
"despiadado!\n"
"                   Has asesinado a "+num()+" habitantes de la ciudad!\n"
"                   Pagarás con tu vida las de ellos!!!\n");
     call_out("Ataque",4);
     return 1;
}

Ataque() {
         TO->Kill(TP);
         return 1;
}
public varargs void Die(mixed silent) {
  tell_room(environment(TO),
    "El soldado dice: ¡Argh! ¡Muero! ¡Pero no escaparás de la ciudad con vida!\n");
    TP->SetAttribute("asesino",TP->QueryAttribute("asesino")+1);
  ::Die(silent);
}
move(dest,method,stuff) // No puede salir de Kha-annu
{
 if(method==M_GO && dest->QueryLocate()!="Kha-annu")
   return ME_NO_ENTER;
    return ::move(dest,method,stuff);
}


