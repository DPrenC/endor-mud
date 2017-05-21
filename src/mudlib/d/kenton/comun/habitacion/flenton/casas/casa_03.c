/***************************************************************************************
 ARCHIVO:	casa_03.c
 AUTOR:		[k] Korsario
 FECHA:		28-02-1998
 COMENTARIOS:	Casa de un kender
 ***************************************************************************************/

#include "path.h"

inherit ROOM;

create(){
  ::create();

  SetIndoors(1);
  SetIntBright(80);
  SetLocate("flenton");
  SetIntNoise("Escuchas el rumor de la calle.\n");
  SetIntSmell("¡Aquí huele que apesta! huele a humedad y a cerrado.\n");

  SetIntShort("una casa de la Calle del Jefe");
  SetIntLong("Estás dentro de la casa. Las paredes están cubiertas de mugre "
  	"y moho, y la casa está bastante desordenada. A ambos lados de la puerta "
  	"hay ventanas con cortinas. En el centro hay una mesa y una silla. Al "
  	"fondo hay una cama.\n");

  AddDetail(({"pared"}),"Esta cubierta de mugre y moho, e incluso alguna que otra "
  	"tela de araña.\n");
  AddDetail(({"ventana"}),"Es una ventana de madera, está cubierta por una cortina.\n");
  AddDetail(({"cortina"}),"está hecha de tela, pero está toda rota y hecha girones.\n");
  AddDetail(({"mesa"}),"Es una mesa de tamaño medio. Encima hay un plato y un vaso.\n");
  AddDetail(({"silla"}),"Es una silla pequeña de madera.\n");
  AddDetail(({"cama"}),"Es una cama pequeña y está sin hacer.\n");
  AddDetail(({"plato"}),"Es un simple plato de madera. Aún tiene restos de comida.\n");
  AddDetail(({"vaso"}),"Es un simple vaso de madera, está medio lleno.\n");
  AddDetail(({"tela de araña"}),"Es una tela de araña abandonada.\n");

  AddExit("norte",FLENHAB+"calles/jefe_00");
}