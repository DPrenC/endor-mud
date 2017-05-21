/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 26-12-97                |
 |               Ultima Modificacion.. 21-02-99                |
 |                                                             |
 *=============================================================*/

#include <combat.h>
#include <properties.h>
#include <materials.h>
#include "path.h"

inherit WEAPON;

create()
{
 if (!clonep(TO)) return;
 ::create();
 SetStandard(WT_MAZA,10,P_SIZE_LARGE,M_HIERRO);
 SetWeight(12000);
 SetShort("una maza de hierro");
 SetIds(({"maza","maza de hierro"}));
 SetValue(2500);
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(2);
 SetLong("\
Es una enorme maza fabricada de hierro y que atemoriza a los enemigos solo\n\
de verla. Si tienes suficiente fuerza no tendrás problema en llevarla con\n\
una sola mano pero sino tendrás que usar las dos.\n");
}
