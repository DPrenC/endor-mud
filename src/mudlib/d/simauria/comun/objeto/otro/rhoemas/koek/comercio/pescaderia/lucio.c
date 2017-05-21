/***************************************************************************************
 ARCHIVO:	c_pes_lucio.c
 AUTOR:		[z] Zomax
 FECHA:		28-10-2001
 COMENTARIOS:	Un lucio crudo.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;

int fcocinar(string str)
{
	if (str=="lucio")
	{
		write("Cocinas el lucio con lo que tienes a mano...\n");
		SetFoodMsgs("Te comes un poco de lucio. Ahora si que puedes comértelo agusto.\n");
		SetFoodStuff(30);
 		SetFoodHeal(60);
 		SetShort("un lucio cocinado");
 		SetLong("Un lucio cocinado, perfectamente limpio, sin espinas y la mar de sabroso.\n");
		return 1;
	}
}

create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un poco de lucio crudo... ¡jj jj  jjj  argg!, ¡una espina!.\n");
 SetFoodStuff(10);
 SetFoodHeal(20);
 SetShort("un lucio crudo");
 SetLong(W(
 "Es un lucio, un pescado de tamaño medio, plateado y de aspecto muy sabroso. Está crudo.\n"));
 SetIds(({"lucio"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(500);
 SetValue(1500);
}

init(){
 ::init();

 add_action("fcocinar","cocinar");
}
