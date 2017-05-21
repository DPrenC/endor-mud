/* SIMAURIA '/guilds/conjuradores/obj/piel_piedra.c'
   =================================================
   [w] Woo@simauria
   [m] maler@simauria

   25-11-99 [w] Usado por el conjuro 'piel de piedra'.
   14-11-00 [m] Mango a saco de nuevo
*/

#include <properties.h>
#include <colours.h>
#include <skills.h>
#include <combat.h>
#include <moving.h>

inherit "/std/thing";

object owner;

create() {
  ::create();
  SetIds(({"conjuro_campo_fuerza"}));
  SetShort(0);
  SetLong(0);
  SetWeight(0);
  Set(P_NODROP,1);
  Set(P_NOGET,1);
  Set(P_NOGIVE,1);
  call_out("remove",10);
}

int Endurecer(object jug, int tiempo) {
  while(remove_call_out("remove")!=-1);
  while(remove_call_out("Restablecer")!=-1);
  TO->move(jug);
  owner=jug;
  owner->SetArmours(owner->QueryArmours()+(({TO})));
  call_out("Restablecer", tiempo, jug);
  return 1; // [Nyh] Para evitar el warning de no return
}

int Restablecer(object jug) {
  while(remove_call_out("Restablecer")!=-1);
  if (jug)
  {
    tell_object(jug,"El campo de fuerza parpadea y desaparece.\n");
    owner->SetArmours(owner->QueryArmours()-(({TO})));
  }
  remove();
  return 1;
}

int Defend(object enemy, int damage, int damage_type) {

  if (damage<3) return 0;

  if (random(2)) {
    tell_room(environment(owner),"El campo de fuerza de"+capitalize(owner->QueryName())+" absorbe daño",(({owner})));
    tell_object(owner, TC_RED+"El campo de fuerza absorbe daño"+TC_NORMAL);
    return damage>>1; // division rapida entre dos
  }

  return 0;
}
