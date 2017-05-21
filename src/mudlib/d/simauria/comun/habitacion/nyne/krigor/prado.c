/*
DESCRIPCION  : Habitacion base de los prados
FICHERO      : prado.c
MODIFICACION : [Chaos] Creacion
*/

#include "path.h"

inherit SIM_ROOM;



string Desc()
{
string s;
s="";

//Descripcion general delsendero
	switch(random(3)){
		case 0:
		   s+="Te encuentras en medio de una pradera a las puertas "
		   "de una casa donde ves a algun niño jugar con el perro.\n";
		break;
		case 1:
	  	   s+="Estas cerca de una casa y ves por los alrededores algun "+
	  	   "animal domestico.\n";
	  	break;
	  	case 2:
	  	   s+="Estas rodeados de prados de hierba verde en las proximidades "+
	  	   "de una casa donde habitan algunos pastores.\n";
	  	break;
	}
return s;
}

create()
{
	::create();

	SetIntShort("los prados de Krigor");
	SetIntLong(W(Desc()));

	SetIntNoise("Oyes risas de niños .\n");
	SetIntSmell("Huele a fresco.\n");
	SetLocate("Krigor");
	//AddItem(PNJKRIG("krigoriano"),REFRESH_DESTRUCT,1)
	SetIndoors(0);
	AddItem(PNJKRIG("vaca"),REFRESH_DESTRUCT,random(2)+1);
	}
