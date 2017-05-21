/***************************************************************************************
 ARCHIVO:	c_lec_queso_agujeros.c
 AUTOR:		[z] Zomax
 FECHA:		27-10-2001
 COMENTARIOS:	Un queso lleno de agujeros.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;


create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un poco de queso.\n");
 SetFoodStuff(10);
 SetFoodHeal(10);
 SetShort("un queso con agujeros");
 SetLong(W(
 "Más que un queso con agujeros parece una reunión de agujeros... rodeados por queso. "
 "Empiezas a pensar que te han timado... pero luego recuerdas que ya habías oído hablar "
 "de este tipo de queso y que parecía estar muy bueno.\n"));
 AddSubDetail(({"agujero","agujeros"}),"Miras los agujeros. Muy bonitos y muy vacíos.\n");
 SetIds(({"queso","queso con agujeros"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(50);
 SetValue(100);
}