/***************************************************************************************
 ARCHIVO:	c_fru_naranja.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Una naranja.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes una naranja.\n");
 SetFoodStuff(5);
 SetFoodHeal(35);
 SetShort("una naranja");
 SetLong(W("Es una naranja, una fruta redonda de color naranja (quizás de ahí el "
 	"nombre) que resulta de lo más refrescante.\n"));
 SetIds(({"naranja"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(100);
 SetValue(75);
}