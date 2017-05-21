/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 26-12-97                |
 |               Ultima Modificacion.. 21-02-99                |
 |               [neme] He cambiado el create() a void.        |
 |                   Sé que lo que da es un warning, pero      |
 |		     me ha dado mal rollo que a Tessio le      |
 |                   haya desaparecido precisamente esta       |
 |                   daga. Que igual ha sido por otra cosa,    |
 |                   vaya usted a saber...                     |
 *=============================================================*/

#include <combat.h>
#include "path.h"
#include <materials.h>
#include <properties.h>

inherit WEAPON;

create()
{
 if (!clonep(TO)) return;
 ::create();
 SetStandard(WT_CUCHILLO,1,P_SIZE_MEDIUM,M_ACERO);
 SetWeight(320);
 SetShort("una daga");
 SetIds(({"daga"}));
 SetValue(200);
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("Se trata de una simple daga con la empuñadura de madera.\n");
}
