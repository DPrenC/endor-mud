/***************************************************************************************
 ARCHIVO:	habitacion_05.c
 AUTOR:		[z] Zomax
 FECHA:		28-12-2001
 COMENTARIOS:	Habitación este 05
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, planta baja, ala este");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntSmell(W("Huele a incienso y otras hierbas que se queman en ofrendas por "
  	"todo el templo.\n"));
  SetIntShort("una habitación");
  SetIntLong(W("Estás en la habitación de uno de los aprendices. Hay una vieja cama "
  	"de madera de aspecto bastante cómodo y una pequeña mesita al lado para dejar "
  	"pequeños enseres. Como el resto de las habitaciones, esta es algo triste y "
  	"simple, pero un colorido tapiz colgado en la pared da algo de vida al lugar.\n"));
  AddDetail(({"cama"}),W("Hay una cama de madera con un colchón hecho de paja en "
  	"una esquina. Parece muy cómoda.\n"));
  AddDetail(({"tapiz"}),W("Es un tapiz de varios colores que recuerda las doctrinas "
  	"que cualquier aprendiz debe aprender. Es bastante bonito y en este triste "
  	"lugar su vista se agradece.\n"));
  AddDetail(({"mesa","mesita"}),W("Al lado de la cama hay una pequeña mesa para dejar "
  	"encima enseres personales. Ahora no hay nada encima. No ves que tenga cajones "
  	"ni nada parecido.\n"));
  AddDetail(({"suelo"}),"El suelo es de roca gris. Está muy limpio y algo frío.\n");
  AddDetail(({"techo"}),W("El techo está hecho del mismo tipo de roca que el suelo, "
  	"una gris no muy atractiva, pero sin duda resistente.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes están hechas de roca gris. Hay un "
  	"pequeño tapiz colgado en una de ellas.\n"));
  AddRoomCmd("coger","fcoger");
  AddExit("sur",RHOEHAB("seri/piso00/este/pasillo_02"));
  if (!random(2)) AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1);
}

int fcoger(string str)
{
	if (str=="tapiz")
	{
		write(W("¿No querrás quitarle su única alegría al inquilino de esta "
			"habitación, no? Este sitio sin el tapiz sería poco más que "
			"una prisión.\n"));
		return 1;
	}
	else if (str=="cama")
	{
		write(W("No puedes coger la cama, aún siendo bastante simple es demasiado "
			"pesada para llevarla.\n"));
		return 1;
	}
}
