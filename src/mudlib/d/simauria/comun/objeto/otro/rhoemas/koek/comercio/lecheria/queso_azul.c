/***************************************************************************************
 ARCHIVO:	c_lec_queso_azul.c
 AUTOR:		[z] Zomax
 FECHA:		27-10-2001
 COMENTARIOS:	Un queso azul.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un poco de queso azul.\n");
 SetFoodStuff(20);
 SetFoodHeal(40);
 SetShort("un queso azul");
 SetLong(W(
 "Es un queso blanco pero lleno de puntos azules y que huele a rayos... si llevas "
 "esto mucho tiempo no se te irá el olor en la vida... pero parece estar bueno.\n"));
 AddSubDetail(({"puntos","puntos azules"}),"No sabes lo que es, pero huele a muerto.\n");
 SetSmell("Dios, es insoportable.\n");
 SetIds(({"queso","queso azul"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(150);
 SetValue(275);
}