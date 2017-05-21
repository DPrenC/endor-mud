/***************************************************************************************
 ARCHIVO:	panaderia_sotano.c
 AUTOR:		[z] Zomax
 FECHA:		20-10-2001
 COMENTARIOS:	Panaderia, s�tano.
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

create () {
 ::create();

  SetIndoors(1);
  SetIntBright(40);
  SetLocate("Koek");
  SetIntShort("la panader�a");
  SetIntSmell("El pan reci�n hecho se huele por todas partes.\n");
  SetIntNoise("Oyes los ruidos de la le�a al arder.\n");
  SetIntLong(W("Este es el s�tano de la panaderia, donde hacen el pan y lo "
  	"hornean. Al fondo de la habitaci�n puedes ver un gran horno de piedra "
  	"con montones de le�a ardiendo debajo. A los lados puedes ver unas mesas "
  	"con el pan sin cocer y unos capazos de mimbre con �l ya cocido. El suelo "
  	"est� lleno de harina que ha ido cayendo al hacer la masa. Tambi�n puedes "
  	"ver varios sacos de harina y unos cubos con agua que utilizan para elaborar "
  	"el pan. Adem�s en otra esquina hay un gran mont�n de le�a. Hay una peque�a "
  	"escalera de madera que sube hacia arriba.\n"));
  AddDetail(({"horno","gran horno"}),W("Es un gran horno de piedra que utilizan "
  	"para hornear el pan y que est� lleno de le�a ardiendo debajo de �l.\n"));
  AddDetail(({"le�a","le�o","le�os","mont�n de le�a","monton de le�a"}),W("Hay "
  	"un mont�n de le�a en un rinc�n esperando para ser quemado. Adem�s tambi�n "
  	"hay varios le�os ardiendo bajo el horno en este momento.\n"));
  AddDetail(({"ceniza","cenizas"}),W("Por donde arde la le�a hay un poco de "
  	"cenizas de cada vez que utilizan el horno.\n"));
  AddDetail(({"mesa","mesas"}),W("Hay unas improvisadas mesas muy sencillas de "
  	"madera donde amasan el pan y lo dejan preparado para su cocci�n.\n"));
  AddDetail(({"capazo","capazo de mimbre","capazos","capazos de mimbre"}),W("Unos "
  	"cuantos capazos se amontonan en un rinc�n. Algunos tienen unas hogazas de "
  	"pan dentro, pero otros est�n vac�os.\n"));
  AddDetail(({"suelo"}),W("Es un suelo muy r�stico, de piedra gris, que estar�a "
  	"bastante limpio de no ser porque la harina que usan para hacer el pan lo "
  	"ha te�ido de blanco.\n"));
  AddDetail(({"masa","masas"}),W("La masa que resulta de la harina y el agua est� "
  	"ordenada por formas sobre la mesa para hornearla muy pronto.\n"));
  AddDetail(({"pan","panes","hogaza","hogazas","hogaza de pan","hogazas de pan"}),W(
  	"El pan ya horneado lo depositan en capazos de mimbre para subirlos a la "
  	"panader�a y venderlos al pueblo.\n"));
  AddDetail(({"saco","sacos","saco de harina","sacos de harina"}),W("Hay varios "
  	"sacos de harina tra�da del molino del pueblo para hacer el pan. Est�n en "
  	"un rinc�n dispuestos a ser utilizados.\n"));
  AddDetail(({"cubo","cubos","cubo con agua","cubos con agua"}),W("Unos simples "
  	"cubos de madera llenos de agua est�n en un rinc�n para poder hacer el pan "
 	"cuando sea necesario.\n"));
  AddDetail(({"escalera"}),W("Una peque�a escalera de madera embadurnada de harina "
  	"sube hacia donde venden el pan.\n"));
  AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy sencillas, "
  	"sin ning�n tipo de decoraci�n. Tampoco ves ninguna ventana.\n"));
  AddDetail(({"techo"}),W("El techo es un simple conjunto de tablones de madera "
  	"que sirven como suelo al piso de arriba.\n"));
  AddDetail(({"decoraci�n"}),"No ves ning�n tipo de decoraci�n en ning�n sitio.\n");
  AddDetail(({"rincon","rinc�n"}),W("En uno de los rincones de este lugar hay unos "
  	"sacos de harina, unos cubos con agua y algo de le�a.\n"));
  AddExit("arriba",RHOEHAB("koek/tiendas/panaderia"));
  AddItem(RHOEPNJ("koek/tiendas/jens"),1);
  carcel=(RHOEHAB("koek/tiendas/panaderia"));
  AddRoomCmd("matar","fmatar");
  AddRoomCmd("robar","frobar");
  AddRoomCmd("confesar","fconfesar");
  AddRoomCmd("entregarse","fentregarse");
}

int QueryEntrarPatrullero()
{
	return 1;
}

