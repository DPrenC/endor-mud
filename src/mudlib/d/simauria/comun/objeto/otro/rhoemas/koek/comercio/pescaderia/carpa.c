/***************************************************************************************
 ARCHIVO:	c_pes_carpa.c
 AUTOR:		[z] Zomax
 FECHA:		28-10-2001
 COMENTARIOS:	Una carpa cruda.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;

int fcocinar(string str)
{
	if (str=="carpa")
	{
		write("Cocinas la carpa con lo que tienes a mano...\n");
		SetFoodMsgs("Te comes un poco de carpa. Está muy buena.\n");
		SetFoodStuff(30);
 		SetFoodHeal(50);
 		SetShort("una carpa cocinada");
 		SetLong("Una carpa cocinada, limpita y sin espinas.\n");
		return 1;
	}
}

create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un poco de carpa cruda... ¡jj jj  jjj  argg!, ¡una espina!.\n");
 SetFoodStuff(10);
 SetFoodHeal(20);
 SetShort("una carpa cruda");
 SetLong(W(
 "Es una carpa, un pescado de tamaño medio, plateada y de aspecto muy sabroso. Está cruda.\n"));
 SetIds(({"carpa"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(500);
 SetValue(700);
}

init(){
 ::init();

 add_action("fcocinar","cocinar");
}
