/***************************************************************************************
 ARCHIVO:	c_ver_tomate.c
 AUTOR:		[z] Zomax
 FECHA:		27-10-2001
 COMENTARIOS:	Un tomate.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un tomate.\n");
 SetFoodStuff(5);
 SetFoodHeal(25);
 SetShort("un tomate");
 SetLong(W(
 "Un tomate rojo como la sangre que tanto has visto por Simauria.\n"));
 SetIds(({"tomate"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(50);
 SetValue(250);
}