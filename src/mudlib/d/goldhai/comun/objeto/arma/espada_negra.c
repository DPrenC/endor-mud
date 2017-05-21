/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 26-12-97                |
 |               Ultima Modificacion.. 22-10-98                |
 |               Modificado por: Nemesis                       |
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
 SetStandard(WT_ESPADA,12,P_SIZE_LARGE,M_ACERO);
 SetWeight(10000); // Un poco mas de peso
 SetShort("una espada larga negra");
 SetIds(({"espada","espada larga","espada negra","espada larga negra"}));
 SetValue(4500);
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(2);
 SetLong("\
Es una gran espada cuya principal caracteristica es su filo negro. Está\n\
forjada en las fundiciones del norte de la isla.\n");
}
