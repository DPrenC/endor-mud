/***************************************************************************************
 ARCHIVO:	c_ver_lechuga.c
 AUTOR:		[z] Zomax
 FECHA:		27-10-2001
 COMENTARIOS:	Una lechuga.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes una lechuga.\n");
 SetFoodStuff(5);
 SetFoodHeal(10);
 SetShort("una lechuga");
 SetLong(W(
 "Una lechuga verde y normal. O eso parece a simple vista. No parece tener 'proteinas' de "
 "más... no ves bichos... la deben haber limpiado bien.\n"));
 SetIds(({"lechuga"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(50);
 SetValue(100);
}