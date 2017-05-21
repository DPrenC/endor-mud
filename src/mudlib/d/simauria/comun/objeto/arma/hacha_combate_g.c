/*
DESCRIPCION  : Hacha de combate de Woo. Version Grande.
FICHERO      : hacha_combate_g.c
CREACION     : 10-11-01 [Bomber]
MODIFICACION :
*/

#include <combat.h>
#include <properties.h>
#include "path.h"

inherit WEAPON;
create()
{
 if (!clonep(TO)) return;
 ::create();
 SetStandard(WT_HACHA,8,P_SIZE_LARGE,M_HIERRO);
 SetWeight(5000*2); // Aumentado el peso
 SetShort("un hacha de combate");
 SetIds(({"hacha","hacha de combate"}));
 SetValue(3000*3);
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(1);
 SetLong("\
Es un hacha de combate forjada de tal forma que dificilmente una armadura\
es capaz de parar totalmente su impacto. Con una doble hoja afilada puede\
llegar a ser un arma mortifera para aquel que sepa y pueda llevarla.\n");
}
