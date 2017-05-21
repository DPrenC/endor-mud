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
  SetStandard(AT_TUNICA,0,P_SIZE_MEDIUM,M_TELA); // Una camisa es cloak
  SetIds(({"camisa"}));
  SetShort("una camisa");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetLong(
"Es una maravillosa camisa de color verde oscuro llena de adornos de plata\n\
y oro en las mangas. Los botones son de un metal dorado y brillante.\n");
  SetWeight(450);
  SetValue(1500);
}
