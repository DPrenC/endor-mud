/***************************************************************************************
 ARCHIVO:	trigo.c
 AUTOR:		[z] Zomax
 FECHA:		24-12-2001	¡Feliz Nochebuena!
 COMENTARIOS:	Un puñado de trigo
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes algo de trigo. Tienes la boca pastosa.\n");
 SetFoodStuff(10);
 SetFoodHeal(5);
 SetShort("un puñado de trigo");
 SetLong(W("Son unos granos de trigo de buena calidad. Tienen un color dorado muy "
 	"bonito.\n"));
 SetIds(({"trigo","punyado de trigo","puñado de trigo","grano","granos de trigo"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(250);
}