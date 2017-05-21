/***************************************************************************************
 ARCHIVO:	habitacion_00.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Habitaci�n este 00
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, primer piso, ala este");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntSmell(W("Huele a incienso y otras hierbas que se queman en ofrendas por "
  	"todo el templo.\n"));
  SetIntShort("una habitaci�n");
  SetIntLong(W("Est�s en los aposentos de uno de los disc�pulos. Puedes ver "
  	"que en est� habitaci�n los detalles est�n algo m�s cuidados, siempre "
  	"dentro de la austeridad predominante de los disc�pulos. Hay unos bonitos "
  	"tapices colgados en las paredes, y una cama muy bien conservada en "
  	"el centro de la habitaci�n, con la cabecera pegada a la pared.\n"));
  AddDetail(({"cabecera","cama","colch�n","colchon"}),W("Hay una cama algo m�s "
  	"grande de lo normal hecha de madera, con una gran cabecera tallada muy "
  	"bonita, con inscripciones que parecen alg�n tipo de verso de protecci�n "
  	"para su ocupante.\n"));
  AddReadMsg(({"inscripciones","inscripcion","inscripci�n"}),W("Lees una inscripci�n, "
  	"pero no la entiendes. Sin embargo te resulta familiar, es algo as� como una "
  	"bendici�n sobre el ocupante de la cama.\n"));
  AddDetail(({"inscripciones","inscripcion","inscripci�n"}),W("Hay unas bonitas inscripciones "
  	"talladas en la cabecera de madera de la cama.\n"));
  AddDetail(({"suelo"}),"El suelo es de roca gris. Est� muy limpio y algo fr�o.\n");
  AddDetail(({"techo"}),W("El techo est� hecho del mismo tipo de roca que el suelo, "
  	"una gris no muy atractiva, pero sin duda resistente.\n"));
  AddDetail(({"tapiz","tapices"}),W("Son unos tapices muy bonitos t�picos de la regi�n. "
  	"Est�n tejidos en lana.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes est�n hechas de roca gris. Hay varios "
  	"tapices que les dan algo de vida.\n"));
  AddRoomCmd("coger","fcoger");
  AddExit("este",RHOEHAB("seri/piso01/este/pasillo_08"));
  if (!random(2)) AddItem(RHOEPNJ("seri/discipulo"),REFRESH_DESTRUCT,1);
}

int fcoger(string str)
{
	if (str=="tapiz" || str=="tapices")
	{
		write(W("No puedes coger los tapices, est�n colgados demasiado alto "
			"y no llegas.\n"));
		return 1;
	}
	else if (str=="cama")
	{
		write(W("La cama es muy pesada, est� hecha de madera maciza, as� que "
			"es imposible que puedas cogerla.\n"));
		return 1;
	}
}
