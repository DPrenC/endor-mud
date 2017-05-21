/***************************************************************************************
 ARCHIVO:	c_ver_pepino.c
 AUTOR:		[z] Zomax
 FECHA:		27-10-2001
 COMENTARIOS:	Un pepino.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un pepino.\n");
 SetFoodStuff(5);
 SetFoodHeal(20);
 SetShort("un pepino");
 SetLong(W(
 "Un pepino... es un vegetal alargado y verde oscuro de lo más raro.\n"));
 SetIds(({"pepino"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(50);
 SetValue(150);
}