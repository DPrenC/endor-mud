/***************************************************************************************
 ARCHIVO:	habitacion_03.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Habitaci�n oeste 03
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create () {
  ::create();

  SetIndoors(1);
  SetIntBright(60);
  SetLocate("Seri-Solderteg, segundo piso, ala oeste");
  SetIntNoise("Hay un silencio absoluto.\n");
  SetIntSmell(W("Huele a incienso y otras hierbas que se queman en ofrendas por "
  	"todo el templo.\n"));
  SetIntShort("una habitaci�n");
  SetIntLong(W("Est�s en la habitaci�n de uno de los maestros. Hay una vieja cama "
  	"de madera de aspecto bastante c�modo y una peque�a mesita al lado para dejar "
  	"peque�os enseres. Como el resto de las habitaciones, esta es algo triste y "
  	"simple, pero un colorido tapiz colgado en la pared da algo de vida al lugar. "
  	"Quiz�s se trate de la habitaci�n de un maestro reci�n nombrado que no le "
  	"ha dado tiempo a acomodarla.\n"));
  AddDetail(({"cama"}),W("Hay una cama de madera con un colch�n hecho de paja en "
  	"una esquina. Parece muy c�moda.\n"));
  AddDetail(({"tapiz"}),W("Es un tapiz de varios colores que recuerda las doctrinas "
  	"que cualquier aprendiz debe aprender. Es bastante bonito y en este triste "
  	"lugar su vista se agradece.\n"));
  AddDetail(({"mesa","mesita"}),W("Al lado de la cama hay una peque�a mesa para dejar "
  	"encima enseres personales. Ahora no hay nada encima. No ves que tenga cajones "
  	"ni nada parecido.\n"));
  AddDetail(({"suelo"}),"El suelo es de roca gris. Est� muy limpio y algo fr�o.\n");
  AddDetail(({"techo"}),W("El techo est� hecho del mismo tipo de roca que el suelo, "
  	"una gris no muy atractiva, pero sin duda resistente.\n"));
  AddDetail(({"pared","paredes"}),W("Las paredes est�n hechas de roca gris. Hay un "
  	"peque�o tapiz colgado en una de ellas.\n"));
  AddRoomCmd("coger","fcoger");
  AddExit("sur",RHOEHAB("seri/piso02/oeste/pasillo_04"));
  if (!random(2)) AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,1);
}

int fcoger(string str)
{
	if (str=="tapiz")
	{
		write(W("�No querr�s quitarle su �nica alegr�a al inquilino de esta "
			"habitaci�n, no? Este sitio sin el tapiz ser�a poco m�s que "
			"una prisi�n.\n"));
		return 1;
	}
	else if (str=="cama")
	{
		write(W("No puedes coger la cama, a�n siendo bastante simple es demasiado "
			"pesada para llevarla.\n"));
		return 1;
	}
}
