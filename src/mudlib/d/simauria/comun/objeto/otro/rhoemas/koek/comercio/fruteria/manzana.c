/***************************************************************************************
 ARCHIVO:	c_fru_manzana.c
 AUTOR:		[z] Zomax
 FECHA:		23-10-2001
 COMENTARIOS:	Una manzana.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes una manzana.\n");
 SetFoodStuff(5);
 SetFoodHeal(30);
 SetShort("una manzana");
 SetLong(W("Es una gran manzana roja y brillante de lo más apetecible. Parece "
 	"que está justo en su punto. Te resulta de lo mas TENTADORA.\n"));
 SetIds(({"manzana"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(100);
 SetValue(75);
}