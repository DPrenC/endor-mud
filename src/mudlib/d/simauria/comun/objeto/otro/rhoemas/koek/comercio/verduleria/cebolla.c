/***************************************************************************************
 ARCHIVO:	c_ver_cebolla.c
 AUTOR:		[z] Zomax
 FECHA:		27-10-2001
 COMENTARIOS:	Una cebolla.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes una cebolla.\n");
 SetFoodStuff(5);
 SetFoodHeal(10);
 SetShort("una cebolla");
 SetLong(W(
 "La miras... y debes pensar en toda la gente que muere en este mundo, porque no "
 "paras de llorar...\n"));
 SetIds(({"cebolla"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(50);
 SetValue(150);
}