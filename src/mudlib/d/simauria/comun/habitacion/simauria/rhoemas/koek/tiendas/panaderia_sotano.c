/***************************************************************************************
 ARCHIVO:	panaderia_sotano.c
 AUTOR:		[z] Zomax
 FECHA:		20-10-2001
 COMENTARIOS:	Panaderia, sótano.
 ***************************************************************************************/

#include "path.h"

inherit SIM_ROOM;
#include RHOEPRESO

create () {
 ::create();

  SetIndoors(1);
  SetIntBright(40);
  SetLocate("Koek");
  SetIntShort("la panadería");
  SetIntSmell("El pan recién hecho se huele por todas partes.\n");
  SetIntNoise("Oyes los ruidos de la leña al arder.\n");
  SetIntLong(W("Este es el sótano de la panaderia, donde hacen el pan y lo "
  	"hornean. Al fondo de la habitación puedes ver un gran horno de piedra "
  	"con montones de leña ardiendo debajo. A los lados puedes ver unas mesas "
  	"con el pan sin cocer y unos capazos de mimbre con él ya cocido. El suelo "
  	"está lleno de harina que ha ido cayendo al hacer la masa. También puedes "
  	"ver varios sacos de harina y unos cubos con agua que utilizan para elaborar "
  	"el pan. Además en otra esquina hay un gran montón de leña. Hay una pequeña "
  	"escalera de madera que sube hacia arriba.\n"));
  AddDetail(({"horno","gran horno"}),W("Es un gran horno de piedra que utilizan "
  	"para hornear el pan y que está lleno de leña ardiendo debajo de él.\n"));
  AddDetail(({"leña","leño","leños","montón de leña","monton de leña"}),W("Hay "
  	"un montón de leña en un rincón esperando para ser quemado. Además también "
  	"hay varios leños ardiendo bajo el horno en este momento.\n"));
  AddDetail(({"ceniza","cenizas"}),W("Por donde arde la leña hay un poco de "
  	"cenizas de cada vez que utilizan el horno.\n"));
  AddDetail(({"mesa","mesas"}),W("Hay unas improvisadas mesas muy sencillas de "
  	"madera donde amasan el pan y lo dejan preparado para su cocción.\n"));
  AddDetail(({"capazo","capazo de mimbre","capazos","capazos de mimbre"}),W("Unos "
  	"cuantos capazos se amontonan en un rincón. Algunos tienen unas hogazas de "
  	"pan dentro, pero otros están vacíos.\n"));
  AddDetail(({"suelo"}),W("Es un suelo muy rústico, de piedra gris, que estaría "
  	"bastante limpio de no ser porque la harina que usan para hacer el pan lo "
  	"ha teñido de blanco.\n"));
  AddDetail(({"masa","masas"}),W("La masa que resulta de la harina y el agua está "
  	"ordenada por formas sobre la mesa para hornearla muy pronto.\n"));
  AddDetail(({"pan","panes","hogaza","hogazas","hogaza de pan","hogazas de pan"}),W(
  	"El pan ya horneado lo depositan en capazos de mimbre para subirlos a la "
  	"panadería y venderlos al pueblo.\n"));
  AddDetail(({"saco","sacos","saco de harina","sacos de harina"}),W("Hay varios "
  	"sacos de harina traída del molino del pueblo para hacer el pan. Están en "
  	"un rincón dispuestos a ser utilizados.\n"));
  AddDetail(({"cubo","cubos","cubo con agua","cubos con agua"}),W("Unos simples "
  	"cubos de madera llenos de agua están en un rincón para poder hacer el pan "
 	"cuando sea necesario.\n"));
  AddDetail(({"escalera"}),W("Una pequeña escalera de madera embadurnada de harina "
  	"sube hacia donde venden el pan.\n"));
  AddDetail(({"pared","paredes"}),W("Este lugar tiene unas paredes muy sencillas, "
  	"sin ningún tipo de decoración. Tampoco ves ninguna ventana.\n"));
  AddDetail(({"techo"}),W("El techo es un simple conjunto de tablones de madera "
  	"que sirven como suelo al piso de arriba.\n"));
  AddDetail(({"decoración"}),"No ves ningún tipo de decoración en ningún sitio.\n");
  AddDetail(({"rincon","rincón"}),W("En uno de los rincones de este lugar hay unos "
  	"sacos de harina, unos cubos con agua y algo de leña.\n"));
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

