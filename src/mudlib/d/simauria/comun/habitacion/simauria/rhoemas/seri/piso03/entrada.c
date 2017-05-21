/***************************************************************************************
 ARCHIVO:	entrada.c
 AUTOR:		[z] Zomax
 FECHA:		14-01-2002
 COMENTARIOS:	Entrada a la habitación del Adalid
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, tercer piso");
  SetIntShort("una sala");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntLong(W("Estás en una pequeña sala a las puertas de la habitación del adalid, "
  	"Kaleband. Este sitio está muy bien cuidado y tiene alfombras, tapices y todo "
  	"tipo de decoración por todos lados. Después de recorrerte todo el templo "
  	"te parece estar en otro lugar. Desde aquí puedes ver la entrada a la habitación "
  	"donde descansa y medita Kaleband.\n"));
  
  AddDetail(({"alfombra","alfombras","tapiz","tapices","decoracion","decoración"}),W("Por "
  	"si solo no hace gran cosa, pero en su conjunto queda de lo más espectacular.\n"));
  AddRoomCmd("coger","fcoger");
  AddExit("entrar",RHOEHAB("seri/piso03/centro"));
  AddExit("sur",RHOEHAB("seri/piso03/pasillo_06"));
}

int fcoger(string str)
{
	if (str=="alfombra" || str=="alfombras" || str=="tapiz" || str=="tapices" || str=="decoracion" || str=="decoración")
	{
		write(W("Por tu bien espero que no empieces a saquear el templo porque sí. "
			"Puede ser letal.\n"));
		return 1;
	}
}
