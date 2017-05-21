/***************************************************************************************
 ARCHIVO:	c_fru_melocoton.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Un melocotón.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un melocotón.\n");
 SetFoodStuff(5);
 SetFoodHeal(25);
 SetShort("un melocotón");
 SetLong(W("Un melocotón, una fruta de lo más aromática de color naranja "
 	"pálido que te invita a que le pegues un buen mordisco.\n"));
 SetIds(({"melocoton","melocotón"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(100);
 SetValue(75);
}