/* SIMAURIA '/guilds/conjuradores/obj/espada_sagrada.c'
   ====================================================
   [w] Woo@simauria

   06-03-00 [w] Esta espada solo se puede crear mediante el conjuro
            'espada sagrada'.
*/

#include <properties.h>
#include <combat.h>

inherit "/std/magia/m_weapon";

void create()
{
  ::create();
  SetStandard(WT_ESPADA,9,TP->QuerySize(),M_ACERO);
  SetShort("la espada sagrada");
  SetLong(
"Es una espada sagrada hecha de acero y que tiene más efecto contra los seres\n"
"de alineamiento negativo.\n");
  AddId(({"espada","espada sagrada","daga"}));
  AddAdjective("sagrada");
  SetWPperQP(0);
  SetNumberHands(1);
}

int CalcDamage(object enemy)
{
  int damage;

  damage = ::CalcDamage(enemy);
  if (enemy && (enemy->QueryAlign()<0))
    damage += damage/4;
  else damage -= damage/4;
  return damage;
}
