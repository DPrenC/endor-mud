/* SIMAURIA '/guilds/conjuradores/obj/maza_infernal.c'
   ===================================================
   [w] Woo@simauria

   17-10-99 [w] Esta maza solo se puede crear mediante el conjuro
            'maza del infierno.
*/

#include <properties.h>
#include <combat.h>

inherit "/std/magia/m_weapon";

void create()
{
  ::create();
  SetStandard(WT_MAZA,7,TP->QuerySize(),M_MADERA);
  SetShort("la Maza del Infierno");
  SetLong(
"Ves la poderosa Maza del Infierno fabricada de una extraña madera y con\n"
"algunas inscripciones que hacen referencia a los señores de las tinieblas.\n");
  AddId(({"maza","maza del infierno"}));
  AddAdjective("infierno");
  SetWPperQP(0);
  SetNumberHands(1);
}

int CalcDamage(object enemy)
{
  int damage;

  damage = ::CalcDamage(enemy);
  if (enemy && (enemy->QueryAlign()>0))
    damage += random(10);
  return damage;
}
