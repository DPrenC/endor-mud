/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 26-12-97                |
 |               Ultima Modificacion.. 21-02-99                |
 |                                                             |
 *=============================================================*/

#include <combat.h>
#include "path.h"
#include <properties.h>
#include <materials.h>

inherit WEAPON;

create()
{
 if (!clonep(TO)) return 1;
 ::create();
 SetStandard(WT_CUCHILLO,2,P_SIZE_MEDIUM,M_ACERO);
 SetWeight(460);
 SetShort("un cuchillo");
 SetIds(({"cuchillo"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetLong("\
Es un pequeño cuchillo con el filo muy afilado y facil de ocultar.\n");
}
