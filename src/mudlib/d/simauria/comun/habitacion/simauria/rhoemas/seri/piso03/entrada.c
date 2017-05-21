/***************************************************************************************
 ARCHIVO:	entrada.c
 AUTOR:		[z] Zomax
 FECHA:		14-01-2002
 COMENTARIOS:	Entrada a la habitaci�n del Adalid
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
  SetIntLong(W("Est�s en una peque�a sala a las puertas de la habitaci�n del adalid, "
  	"Kaleband. Este sitio est� muy bien cuidado y tiene alfombras, tapices y todo "
  	"tipo de decoraci�n por todos lados. Despu�s de recorrerte todo el templo "
  	"te parece estar en otro lugar. Desde aqu� puedes ver la entrada a la habitaci�n "
  	"donde descansa y medita Kaleband.\n"));
  
  AddDetail(({"alfombra","alfombras","tapiz","tapices","decoracion","decoraci�n"}),W("Por "
  	"si solo no hace gran cosa, pero en su conjunto queda de lo m�s espectacular.\n"));
  AddRoomCmd("coger","fcoger");
  AddExit("entrar",RHOEHAB("seri/piso03/centro"));
  AddExit("sur",RHOEHAB("seri/piso03/pasillo_06"));
}

int fcoger(string str)
{
	if (str=="alfombra" || str=="alfombras" || str=="tapiz" || str=="tapices" || str=="decoracion" || str=="decoraci�n")
	{
		write(W("Por tu bien espero que no empieces a saquear el templo porque s�. "
			"Puede ser letal.\n"));
		return 1;
	}
}
