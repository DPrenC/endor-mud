/***************************************************************************************
 ARCHIVO:	c_pes_trucha.c
 AUTOR:		[z] Zomax
 FECHA:		28-10-2001
 COMENTARIOS:	Una trucha cruda.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit FOOD;

int fcocinar(string str)
{
	if (str=="trucha")
	{
		write("Cocinas la trucha con lo que tienes a mano...\n");
		SetFoodMsgs("Te comes un poco de trucha. Um... que buena está.\n");
		SetFoodStuff(30);
 		SetFoodHeal(50);
 		SetShort("una trucha cocinada");
 		SetLong("Una trucha cocinada, limpita y sin espinas.\n");
		return 1;
	}
}

create () {
 ::create();

 SetFoodKind("food");
 SetFoodMsgs("Te comes un poco de trucha cruda... ¡jj jj  jjj  argg!, ¡una espina!.\n");
 SetFoodStuff(10);
 SetFoodHeal(20);
 SetShort("una trucha cruda");
 SetLong(W(
 "Es una trucha, un pescado de algo menos de dos palmos de color plateado con algunas "
 "rayas más oscuras. Está cruda.\n"));
 SetIds(({"trucha"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 Set(P_SIZE,P_SIZE_GENERIC);
 SetWeight(500);
 SetValue(800);
}

init(){
 ::init();

 add_action("fcocinar","cocinar");
}
