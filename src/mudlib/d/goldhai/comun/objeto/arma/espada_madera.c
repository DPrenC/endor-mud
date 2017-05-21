/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 26-12-97                |
 |               Ultima Modificacion.. 23-02-99                |
 |                                                             |
 *=============================================================*/

#include <combat.h>#include <materials.h>
#include <properties.h>

#include "path.h"

inherit WEAPON;

create()
{
 if (!clonep(TO)) return 1;
 ::create();
 SetStandard(WT_ESPADA,1,P_SIZE_MEDIUM,M_MADERA);
 SetWeight(550);
 SetShort("una espada de madera");
 SetIds(({"espada","espada de madera"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("\
Es una pequeña espada hecha de madera para que los niños puedan jugar.\n");
}

