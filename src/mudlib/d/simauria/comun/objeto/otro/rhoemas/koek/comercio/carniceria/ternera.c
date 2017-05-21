/***************************************************************************************
 ARCHIVO:	c_car_ternera.c
 AUTOR:		[z] Zomax
 FECHA:		27-10-2001
 COMENTARIOS:	Una chuleta de ternera.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;

int fcocinar(string str)
{
	if ((str=="chuleta") ||(str=="ternera") || (str=="chuleta de ternera") || (str=="chuleta de ternera cruda"))
	{
		write("Cocinas la chuleta con lo que tienes a mano...\n");
		SetFoodMsgs("Te comes un poco de la chuleta de ternera. Está mejor cocinada.\n");
		SetFoodStuff(10);
 		SetFoodHeal(100);
 		SetShort("una chuleta de ternera cocinada");
 		SetLong("Una chuleta de ternera... ya la ves más comestible...\n");
		return 1;
	}
}

create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes una chuleta de ternera cruda... Te notas algo raro... como si estuvieras desvariando por momentos...\n");
 SetFoodStuff(20);
 SetFoodHeal(30);
 SetShort("una chuleta de ternera cruda");
 SetLong(W("Es un trozo de lo que una vez fue una vaca que campaba feliz por los "
 	"pastos... pero llegó un forastero a la ciudad, pido ternera y la tuvieron "
 	"que matar para poder vendersela.\n"));
 SetIds(({"chuleta","chuleta de ternera","ternera"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(1500);
}

init(){
 ::init();

 add_action("fcocinar","cocinar");
}
