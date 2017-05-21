/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 26-12-97                |
 |               Ultima Modificacion.. 23-02-99                |
 |                                                             |
 *=============================================================*/

#include <combat.h>
#include <properties.h>
#include <materials.h>
#include "path.h"

inherit WEAPON;

create()
{
 if (!clonep(TO)) return 1;
 ::create();
 SetStandard(WT_VARA,1,P_SIZE_GENERIC,M_MADERA);
 SetWeight(300);
 SetShort("un vulgar palo de madera");
 SetIds(({"palo","palo de madera","vulgar palo","vulgar palo de madera"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("Un vulgar palo de madera.\n");
}
