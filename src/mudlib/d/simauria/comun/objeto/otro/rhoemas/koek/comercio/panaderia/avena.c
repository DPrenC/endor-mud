/***************************************************************************************
 ARCHIVO:	c_pan_avena.c
 AUTOR:		[z] Zomax
 FECHA:		23-10-2001
 COMENTARIOS:	Un pan de avena.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un poco de pan de avena y tienes menos hambre.\n");
 SetFoodStuff(20);
 SetFoodHeal(30);
 SetShort("un pan de avena");
 SetLong(W(
 "Es un pan de avena hecho por Jens, el panadero de Koek. Puedes ver como hay pequeños "
 "trocitos de cereales, principalmente avena, dentro del pan. Se ve muy bueno.\n"));
 AddSubDetail(({"trocitos"}),"Son pequeños trocitos de avena.\n");
 SetIds(({"pan","hogaza","pan de avena"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(50);
 SetValue(75);
}