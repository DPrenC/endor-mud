/***************************************************************************************
 ARCHIVO:	armeria.c
 AUTOR:		[z] Zomax
 FECHA:		10-01-2002
 COMENTARIOS:	Armeria del templo
 ***************************************************************************************/

#include "path.h"

inherit "/room/herreria";

create () {
 ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, planta baja");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntSmell("Huele a incienso y otras hierbas que se queman en ofrendas por todo el templo.\n");
  SetIntShort("la armeria");
  SetIntLong(W("Esta es la armer�a del templo, donde se guardan las armas que se "
  	"usan en los entrenamientos e incluso se reparan gustosamente si se tiene"
  	"dinero para pagar por ello. Hay un enorme yunque con un martillo "
  	"encadenado a �l donde reparan las armas. Tambi�n puedes ver varios aparejos "
  	"para lijar y cortar madera, quiz�s para reparar las varas que usan los "
  	"aprendices.\n"));
  AddDetail(({"yunque"}),W("Es enorme, y est� hecho de hierro puro. Mejor no lo tocas "
  	"mucho no sea que se te caiga en un pi�.\n"));
  AddDetail(({"martillo"}),"Es un gran martillo para reparar. Est� encadenado al yunque.\n");
  AddDetail(({"aparejo","aparejos",}),W("Puedes ver varios aparejos para reparar piezas "
  	"de madera.\n"));
  AddDetail(({"suelo"}),"El suelo es como el de todo el templo, de roca gris.\n");
  AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy "
  	"sencillas, sin ning�n tipo de decoraci�n.\n"));
  AddDetail(({"techo"}),"Un techo de lo m�s normal.\n");
  RemoveDustbin(1);
  SetNoShop(1);
  SetSmithy(1);
  SetShopkeeper(RHOEPNJ("seri/armero"),REFRESH_DESTRUCT);
  AddExit("este",RHOEHAB("seri/piso00/centro/pasillo_04"));
  AddRoomCmd("coger","fcoger");
}

int fcoger(string str)
{
	if (str=="yunque")
	{
		write(W("El yunque pesa m�s de lo que a simple vista parece, que "
			"ya es demasiado. Mejor lo dejas donde est�.\n"));
		return 1;
	}
	else if (str=="martillo")
	{
		write(W("El martillo est� fuertemente encadenado al yunque, que "
			"pesa lo indecible, as� que no lo coges.\n"));
		return 1;
	}
	else if (str=="aparejo" || str=="aparejos")
	{
		write(W("�No le har�s el feo a los aprendices de tener que afilar "
			"sus varas con los dientes, no?. A ti no te sirven para "
			"nada, mejor no los coges.\n"));
		return 1;
	}
}
