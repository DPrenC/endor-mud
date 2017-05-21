/* SIMAURIA '/obj/flecha.c'
   ========================
   [w] Woo@simauria

   21-10-99 [w] Es una simple flecha.. de momento.
*/

#include <properties.h>
#include <combat.h>
inherit "/std/weapon";

create() {
 ::create();
 SetStandard(WT_VARA,0,P_SIZE_SMALL,M_MADERA);
 SetShort("una flecha");
 SetLong("Una flecha de madera.\n");
 AddId("flecha");
 SetValue(50);
 SetWeight(400);
 SetValue(50);
 Set(P_GENDER,GENDER_FEMALE);
}

public int QueryIsArrow()
{
 return 1;
}

public varargs mixed ChkEquip(object wielder, object weapon, int flags)
{
  if (weapon != TO) return EQ_OK;
  return "No creo que hicieras mucho daño con "+weapon->QueryShort()+".\n";
}
