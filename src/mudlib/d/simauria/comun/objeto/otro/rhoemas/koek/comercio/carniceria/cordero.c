/***************************************************************************************
 ARCHIVO:	c_car_cordero.c
 AUTOR:		[z] Zomax
 FECHA:		27-10-2001
 COMENTARIOS:	Una chuleta de cordero.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;

int fcocinar(string str)
{
	if ((str=="chuleta") || (str=="cordero") || (str=="chuleta de cordero") || (str=="chuleta de cordero cruda"))
	{
		write("Cocinas la chuleta con lo que tienes a mano...\n");
		SetFoodMsgs("Te comes un poco de la chuleta de cordero. Está mejor cocinada.\n");
		SetFoodStuff(10);
 		SetFoodHeal(75);
 		SetShort("una chuleta de cordero cocinada");
 		SetLong("Una chuleta de cordero... ya la ves más comestible...\n");
		return 1;
	}
}

create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes una chuleta de cordero cruda... Piensas que eres muy muy raro.\n");
 SetFoodStuff(20);
 SetFoodHeal(30);
 SetShort("una chuleta de cordero cruda");
 SetLong(W(
 "Es un trozo de lo que una vez fue un corderillo curioso que seguro que se perdió más "
 "de una vez en el campo... empiezas a sentir remordimientos...\n"));
 SetIds(({"chuleta","chuleta de cordero","cordero"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(1500);
}

init(){
 ::init();

 add_action("fcocinar","cocinar");
}
