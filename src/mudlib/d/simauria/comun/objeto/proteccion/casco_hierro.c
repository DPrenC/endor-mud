/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 23-02-99                |
 |               Ultima Modificacion.. 23-02-99                |
 |                                                             |
 *=============================================================*/

#include <combat.h>
#include <properties.h>
#include "path.h"

inherit ARMOUR;

create()
{
 ::create();
 SetStandard(AT_HELMET,1,P_SIZE_MEDIUM,M_HIERRO);
 SetWeight(1500);
 SetShort("un casco de hierro");
 SetIds(({"casco","casco de hierro"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetLong("Es un casco bastante de hierro bastante sucio.\n");
}

