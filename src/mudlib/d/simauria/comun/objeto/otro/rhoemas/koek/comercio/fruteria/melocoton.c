/***************************************************************************************
 ARCHIVO:	c_fru_melocoton.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Un melocot�n.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un melocot�n.\n");
 SetFoodStuff(5);
 SetFoodHeal(25);
 SetShort("un melocot�n");
 SetLong(W("Un melocot�n, una fruta de lo m�s arom�tica de color naranja "
 	"p�lido que te invita a que le pegues un buen mordisco.\n"));
 SetIds(({"melocoton","melocot�n"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(100);
 SetValue(75);
}