/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 26-12-97                |
 |               Ultima Modificacion.. 21-02-99                |
 |                                                             |
 |               16-May-00 [Nem] El Setweight no hace lo que   |
 |                               debe, asi que lo comento...   |
 *=============================================================*/

#include "path.h"
#include <combat.h>
#include <materials.h>
#include <properties.h>

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
Es una enorme maza fabricada de hierro y que atemoriza a los enemigos solo\
de verla.\n");
}
