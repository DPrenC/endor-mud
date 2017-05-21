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
  SetStandard(AT_CORAZA,8,P_SIZE_MEDIUM,M_ACERO);
  SetIds(({"cota","cota de mallas"}));
  SetShort("una cota de mallas");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetLong(
"Es una cota de mallas que cubre el pecho por completo y sujetada con unas\n\
tiras de cuero por la espalda.\n");
}
