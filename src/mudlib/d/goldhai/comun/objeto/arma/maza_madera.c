/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 02-12-99                |
 |               Ultima Modificacion.. 02-12-99                |
 |                                                             |
 *=============================================================*/

#include <combat.h>
#include <materials.h>
#include <properties.h>
#include "path.h"

inherit WEAPON;

create()
{
 if (!clonep(TO)) return 1;
 ::create();
 SetStandard(WT_MAZA,2,P_SIZE_LARGE,M_MADERA);
 SetWeight(3000);
 SetShort("una maza de madera");
 SetIds(({"maza","maza de madera"}));
 SetValue(2500);
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("Una maza de madera util para barbaros del combate e inexpertos en el arte\n"+"de la lucha con espada.\n");
}

