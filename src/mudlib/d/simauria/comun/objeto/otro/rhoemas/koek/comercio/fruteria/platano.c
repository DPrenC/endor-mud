/***************************************************************************************
 ARCHIVO:	c_fru_platano.c
 AUTOR:		[z] Zomax
 FECHA:		25-10-2001
 COMENTARIOS:	Un pl�tano.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un pl�tano.\n");
 SetFoodStuff(5);
 SetFoodHeal(40);
 SetShort("un pl�tano");
 SetLong(W("Es un pl�tano, una fruta algo ex�tica que traen de lejos y de aspecto "
 	"algo inusual. Es alargado, de color amarillo intenso y con algunas motas "
 	"negras.\n"));
 AddSubDetail(({"mota","motas"}),W("Est� lleno de unas motas negras que le hacen "
 	"bastante apetitoso.\n"));
 SetIds(({"platano","pl�tano"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(100);
 SetValue(75);
}