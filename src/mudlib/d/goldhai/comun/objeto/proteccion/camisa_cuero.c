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
  SetStandard(AT_TUNICA,2,P_SIZE_MEDIUM,M_CUERO);
  SetIds(({"camisa","camisa de cuero"}));
  SetShort("una camisa de cuero");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetLong(
"Es una camisa hecha por completo de cuero, bastante resistente y muy\n\
flexible, ideal para las personas que viajan mucho.\n");
}
