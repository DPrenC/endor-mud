/***************************************************************************************
 ARCHIVO:	carniceria_sotano.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Carnicer�a, s�tano.
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

create () {
 ::create();

  SetIndoors(1);
  SetIntBright(40);
  SetLocate("Koek");
  SetIntShort("la carnicer�a");
  SetIntSmell("Huele a sangre...\n");
  SetIntNoise("No oyes nada especial.\n");
  SetIntLong(W("Este es el s�tano de la carnicer�a, donde Galonor descuartiza "
  	"las piezas de carne y las prepara para venderlas. Hay una mesa donde "
  	"suelen apoyar la carne, toda manchada de sangre, y poco m�s. En una esquina "
  	"ves una cuna. Parece algo imposible en un sitio as�.\n"));
  AddDetail(({"mesa"}),"Es una mesa de madera manchada de sangre.\n");
  AddDetail(({"sangre"}),W("La sangre est� casi por todas partes. Esperas que sea de "
  	"animales s�lo.\n"));
  AddDetail(({"cuna"}),W("Es la cuna donde los carniceros tienen a su hijo cuando "
  	"atienden la tienda. No logras comprender como son capaces de tener a un ni�o "
  	"aqu�, pero quiz�s sea as� como le ense�an a apreciar el negocio.\n"));
  AddDetail(({"suelo"}),"Es un suelo muy r�stico y completamente ba�ado en sangre.\n");
  AddDetail(({"escalera"}),W("Una peque�a escalera de madera con alguna mancha de sangre "
  	"sube hacia la tienda.\n"));
  AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy sencillas, "
  	"sin ning�n tipo de decoraci�n. Tampoco ves ninguna ventana.\n"));
  AddDetail(({"techo"}),W("El techo es un simple conjunto de tablones de madera "
  	"que sirven como suelo al piso de arriba.\n"));
  AddDetail(({"decoraci�n"}),"No ves ning�n tipo de decoraci�n en ning�n sitio.\n");
  AddExit("arriba",RHOEHAB("koek/tiendas/carniceria"));
  AddItem(RHOEPNJ("koek/tiendas/galonor"),1);
  AddItem(RHOEPNJ("koek/tiendas/broe"),1);
  carcel=(RHOEHAB("koek/tiendas/carniceria"));
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
}

int QueryEntrarPatrullero()
{
	return 1;
}

