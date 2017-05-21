/***************************************************************************************
 ARCHIVO:	c_pan_leche.c
 AUTOR:		[z] Zomax
 FECHA:		23-10-2001
 COMENTARIOS:	Un panecillo de leche.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un panecillo de leche y tienes menos hambre.\n");
 SetFoodStuff(5);
 SetFoodHeal(5);
 SetShort("un panecillo de leche");
 SetLong(W(
 "Es un pequeño panecillo de leche de la panadería de Jens en Koek. Está muy tierno y "
 "tiene un color muy blanco por dentro y algo tostado por fuera. Es pequeño, pero parece "
 "estar muy bueno.\n"));
 SetIds(({"panecillo","panecillo de leche"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(50);
 SetValue(10);
}