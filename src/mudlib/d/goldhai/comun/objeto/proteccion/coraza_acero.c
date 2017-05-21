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
  SetStandard(AT_CORAZA,9,P_SIZE_MEDIUM,M_ACERO);
  SetIds(({"coraza","coraza de acero"}));
  SetShort("una coraza de acero");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetLong(
"Es una coraza de acero que cubre el pecho por completo y sujetada con unas\n\
tiras de cuero por la espalda.\n");
}
