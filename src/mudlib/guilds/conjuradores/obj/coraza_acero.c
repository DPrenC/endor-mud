/* SIMAURIA '/guilds/conjuradores/obj/coraza_acero.c'
   ==================================================
   [w] Woo@simauria

   26-11-99 [w] Esta coraza solo se puede crear mediante el conjuro
            'coraza ligera'.
*/

#include <properties.h>
#include <combat.h>

inherit "/std/magia/m_armour";

void create()
{
  ::create();
  SetStandard(AT_CORAZA,6,TP->QuerySize(),M_ACERO);
  SetShort("una coraza de acero mágica");
  AddId("coraza de acero");
  AddId("coraza de acero magica");
  AddId("coraza de acero mágica");
  SetLong(
"Es una reluciente coraza de acero sin apenas adornos.\n");
  AddAdjective("acero");
  SetWeight(3000); // Pesa poco.. es mágica.
  SetAPperQP(0); // No se degrada.
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
}

public int QueryCorazaLigera() { return 1; }

