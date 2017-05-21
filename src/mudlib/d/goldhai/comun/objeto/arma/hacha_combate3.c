/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 05-10-98                |
 |               Ultima Modificacion.. 21-02-99                |
 |               Revisada por: Nemesis                         |
 *=============================================================*/

#include <combat.h>
#include <properties.h>
#include "path.h"
#include <materials.h>

inherit WEAPON;

create()
{
 if (!clonep(TO)) return;
 ::create();
 SetStandard(WT_HACHA,8,P_SIZE_LARGE,M_HIERRO);
 SetWeight(5000); // Aumentado el peso
 SetShort("un hacha de combate");
 SetIds(({"hacha","hacha de combate"}));
 SetValue(3000);
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("\
Es un hacha de combate forjada de tal forma que dificilmente una armadura\n\
es capaz de parar totalmente su impacto. Con una doble hoja afilada puede\n\
llegar a ser un arma mortifera para aquel que sepa y pueda llevarla.\n");
}
