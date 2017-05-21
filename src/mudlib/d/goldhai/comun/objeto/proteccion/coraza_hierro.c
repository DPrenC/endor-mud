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
  SetStandard(AT_CORAZA,13,P_SIZE_LARGE,M_HIERRO);
  SetIds(({"coraza","coraza de hierro"}));
  SetShort("una coraza de hierro");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetLong(
"Es una coraza toda hecha de hierro y que debe pesar una barbaridad.\n");
}
