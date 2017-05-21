/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 26-12-97                |
 |               Ultima Modificacion.. 21-02-99                |
 |                                                             |
 *=============================================================*/

#include <combat.h>
#include "path.h"
#include <materials.h>
#include <properties.h>

inherit WEAPON;

create()
{
 if (!clonep(TO)) return 1;
 ::create();
 SetStandard(WT_CUCHILLO,3,P_SIZE_LARGE,M_ACERO);
 SetWeight(460);
 SetShort("un cuchillo de cocina");
 SetIds(({"cuchillo","cuchillo de cocina"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetLong("Es un cuchillo de cocina muy afilado.\n");

}
