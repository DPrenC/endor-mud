/***************************************************************************************
 ARCHIVO:	c_car_cerdo.c
 AUTOR:		[z] Zomax
 FECHA:		27-10-2001
 COMENTARIOS:	Una chuleta de cerdo.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;

int fcocinar(string str)
{
	if ((str=="chuleta") ||(str=="cerdo") || (str=="chuleta de cerdo") || (str=="chuleta de cerdo cruda"))
	{
		write("Cocinas la chuleta con lo que tienes a mano...\n");
		SetFoodMsgs("Te comes un poco de la chuleta de cerdo. Está mejor cocinada.\n");
		SetFoodStuff(10);
 		SetFoodHeal(75);
 		SetShort("una chuleta de cerdo cocinada");
 		SetLong("Una chuleta de cerdo... ya la ves más comestible...\n");
		return 1;
	}
}

create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes una chuleta de cerdo cruda... ¡pero que caníbal!.\n");
 SetFoodStuff(20);
 SetFoodHeal(30);
 SetShort("una chuleta de cerdo cruda");
 SetLong("Es un trozo de lo que una vez fue un cerdito muy travieso que lo pagó con su vida. Lástima.\n");
 SetIds(({"chuleta","chuleta de cerdo","cerdo"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(1500);
}

init(){
 ::init();

 add_action("fcocinar","cocinar");
}
