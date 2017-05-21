/***************************************************************************************
 ARCHIVO:	c_car_pollo.c
 AUTOR:		[z] Zomax
 FECHA:		27-10-2001
 COMENTARIOS:	Un pollo crudo.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;

int fcocinar(string str)
{
	if (str=="pollo")
	{
		write("Cocinas el pollo con lo que tienes a mano...\n");
		SetFoodMsgs("Te comes un poco de pollo. Está mejor que crudo.\n");
		SetFoodStuff(40);
 		SetFoodHeal(100);
 		SetShort("un pollo cocinado");
 		SetLong("Un pollo asado... ya lo ves más comestible...\n");
		return 1;
	}
}

create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un poco de pollo crudo... alimenta... ¡pero que asco!.\n");
 SetFoodStuff(20);
 SetFoodHeal(30);
 SetShort("un pollo crudo");
 SetLong(W("Es un pollo la mar de mono... con sus patitas... su piquito... snif... "
 	"está muerto y muy muy crudo.\n"));
 AddSubDetail(({"patita","patitas","pata","patas"}),"Muy finas, muy tiesas y muy muertas.\n");
 AddSubDetail(({"pico","piquito"}),"Me temo que ya no volverá a decir ni pio.\n");
 SetIds(({"pollo"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(1500);
}

init(){
 ::init();

 add_action("fcocinar","cocinar");
}
