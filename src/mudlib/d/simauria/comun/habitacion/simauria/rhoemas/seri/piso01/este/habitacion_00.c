/***************************************************************************************
 ARCHIVO:	habitacion_00.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Habitación este 00
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
  SetIntShort("una habitación");
  SetIntLong(W("Estás en los aposentos de uno de los discípulos. Puedes ver "
  	"que en está habitación los detalles están algo más cuidados, siempre "
  	"dentro de la austeridad predominante de los discípulos. Hay unos bonitos "
  	"tapices colgados en las paredes, y una cama muy bien conservada en "
  	"el centro de la habitación, con la cabecera pegada a la pared.\n"));
  AddDetail(({"cabecera","cama","colchón","colchon"}),W("Hay una cama algo más "
  	"grande de lo normal hecha de madera, con una gran cabecera tallada muy "
  	"bonita, con inscripciones que parecen algún tipo de verso de protección "
  	"para su ocupante.\n"));
  AddReadMsg(({"inscripciones","inscripcion","inscripción"}),W("Lees una inscripción, "
  	"pero no la entiendes. Sin embargo te resulta familiar, es algo así como una "
  	"bendición sobre el ocupante de la cama.\n"));
  AddDetail(({"inscripciones","inscripcion","inscripción"}),W("Hay unas bonitas inscripciones "
  	"talladas en la cabecera de madera de la cama.\n"));
  AddDetail(({"suelo"}),"El suelo es de roca gris. Está muy limpio y algo frío.\n");
  AddDetail(({"techo"}),W("El techo está hecho del mismo tipo de roca que el suelo, "
  	"una gris no muy atractiva, pero sin duda resistente.\n"));
  AddDetail(({"tapiz","tapices"}),W("Son unos tapices muy bonitos típicos de la región. "
  	"Están tejidos en lana.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes están hechas de roca gris. Hay varios "
  	"tapices que les dan algo de vida.\n"));
  AddRoomCmd("coger","fcoger");
  AddExit("este",RHOEHAB("seri/piso01/este/pasillo_08"));
  if (!random(2)) AddItem(RHOEPNJ("seri/discipulo"),REFRESH_DESTRUCT,1);
}

int fcoger(string str)
{
	if (str=="tapiz" || str=="tapices")
	{
		write(W("No puedes coger los tapices, están colgados demasiado alto "
			"y no llegas.\n"));
		return 1;
	}
	else if (str=="cama")
	{
		write(W("La cama es muy pesada, está hecha de madera maciza, así que "
			"es imposible que puedas cogerla.\n"));
		return 1;
	}
}
