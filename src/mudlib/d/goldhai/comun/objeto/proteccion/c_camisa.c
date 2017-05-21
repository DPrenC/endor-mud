/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 07-10-98                |
 |               Ultima Modificacion.. 21-02-99                |
 *=============================================================*/

#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>


inherit ARMOUR;

create() {
  ::create();
  SetStandard(AT_CLOAK,0,P_SIZE_MEDIUM,M_TELA); // Una camisa es una cloak
  SetIds(({"camisa"}));
  SetShort("una camisa");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetLong(
"Una simple camisa de tela.\n");
  SetWeight(250);
  SetValue(100);
}
