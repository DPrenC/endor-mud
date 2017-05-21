/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 02-12-99                |
 |               Ultima Modificacion.. 02-12-99                |
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
 SetStandard(WT_VARA,7,P_SIZE_GENERIC,M_ACERO);
 SetWeight(1100);
 SetShort("una vara de acero");
 SetIds(({"vara"}));
 AddAdjective("acero");
 AddAdjective("de acero");
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(2);
 SetLong("\
Ves una larga vara de acero con una cuerda atada en el centro para que puedas\n\
sujetarla mejor en el combate.\n");
}
