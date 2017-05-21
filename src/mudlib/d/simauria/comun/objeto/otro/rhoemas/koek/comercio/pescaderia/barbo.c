/***************************************************************************************
 ARCHIVO:	c_pes_barbo.c
 AUTOR:		[z] Zomax
 FECHA:		28-10-2001
 COMENTARIOS:	Un barbo crudo.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;

int fcocinar(string str)
{
	if (str=="barbo")
	{
		write("Cocinas el barbo con lo que tienes a mano...\n");
		SetFoodMsgs("Te comes un poco de barbo. Ahora está justo en su punto.\n");
		SetFoodStuff(30);
 		SetFoodHeal(45);
 		SetShort("un barbo cocinado");
 		SetLong("Un barbo cocinado, perfectamente limpio, sin espinas y la mar de sabroso.\n");
		return 1;
	}
}

create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un poco de barbo crudo... ¡jj jj  jjj  argg!, ¡una espina!.\n");
 SetFoodStuff(10);
 SetFoodHeal(20);
 SetShort("un barbo crudo");
 SetLong(W(
 "Es un barbo, un pescado de tamaño medio, plateado y de aspecto muy sabroso. Está crudo.\n"));
 SetIds(({"barbo"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(500);
 SetValue(1200);
}

init(){
 ::init();

 add_action("fcocinar","cocinar");
}
