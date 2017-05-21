/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 23-02-99                |
 |               Ultima Modificacion.. 23-02-99                |
 |                                                             |
 *=============================================================*/

#include <combat.h>
#include <properties.h>
#include <materials.h>
#include "path.h"

//inherit WEAPON;
inherit WEAPON;

create()
{
 if (!clonep(TO)) return 1;
 ::create();
 SetStandard(WT_ESPADA,3,P_SIZE_MEDIUM,M_HIERRO);
 SetShort("una espada corta");
 SetIds(({"espada","espada corta","espada corta de hierro","espada de hierro"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("Es una espada corta de hierro.\n");

}

