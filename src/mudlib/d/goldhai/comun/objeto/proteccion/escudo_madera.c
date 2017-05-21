/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 02-12-99                |
 |               Ultima Modificacion.. 02-12-99                |
 *=============================================================*/

#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>



inherit ARMOUR;

create() {
  ::create();
  SetStandard(AT_ESCUDO,2,P_SIZE_MEDIUM,M_MADERA);
  SetIds(({"escudo","escudo de madera"}));
  SetShort("un escudo de madera");
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetWeight(2000);
  SetLong(
"Es un peque�o escudo fabricado de madera que te permitir� para los golpes\n\
de tus adversarios durante el combate.\n");
}
