/*
DESCRIPCION  : Habitacion base de los senderos
FICHERO      : sendero.c
MODIFICACION : [Chaos] Creacion
*/

#include "path.h"

inherit SIM_ROOM;



string Desc()
{
string s;
s="";

//Descripcion general del sendero
	switch(random(4)){
		case 0:
		   s+="Te encuentras en el sendero que va hacia el pueblo de Krigor.\n";
		break;
		case 1:
	  	   s+="Estas en el sendero que cruza los prados desde el bosque hacia Krigor.\n";
	  	break;
	  	case 2:
	  	   s+="Estas en medio de un sendero hecho por el paso de las carretas hacia krigor.\n";
	  	break;
	  	case 3:
	  	   s+="Discurres por un sendero que se ha producido por el paso del ganado hacia Krigor.\n";
	  	break;
	}
return s;
}

create()
{
	::create();

	SetIntShort("el sendero de Krigor");
	SetIntLong(W(Desc()));

	SetIntNoise("Oyes algun balido .\n");
	SetIntSmell("Huele a fresco.\n");
	SetLocate("Krigor");
	SetIndoors(0);

}
