/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 02-03-00                |
 |               Ultima Modificacion.. 02-02-00                |
 *=============================================================*/

#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>



inherit ARMOUR;

create() {
  ::create();
  SetStandard(AT_ESCUDO,3,P_SIZE_LARGE,M_ACERO);
  SetIds(({"escudo"}));
  AddAdjective("acero");
  AddAdjective("pesado");
  SetShort("un escudo de acero");
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetLong(
"Es un escudo redondo de acero.\n");
}


