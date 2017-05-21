/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 23-02-99                |
 |               Ultima Modificacion.. 23-02-99                |
 *=============================================================*/

#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>



inherit ARMOUR;

create() {
  ::create();
  SetStandard(AT_TUNICA,0,P_SIZE_SMALL,M_TELA);
  SetIds(({"camisa"}));
  SetShort("una camisa");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetLong("Una camisa de tela roja agujereada.\n");
}
