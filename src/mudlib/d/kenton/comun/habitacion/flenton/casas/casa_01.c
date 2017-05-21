/***************************************************************************************
 ARCHIVO:	casa_01.c
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
  SetIntSmell("Hueles el aroma de las flores en primavera.\n");

  SetIntShort("una casa de la Calle del Jefe");
  SetIntLong("Estás dentro de la casa. Las paredes están decoradas con "
  	"flores silvestres y y piedras de colores. La casa está bastante "
  	"limpia y ordenada. En el centro de la estáncia hay una mesa y dos "
  	"sillas. Al fondo hay un baúl y una cama. A ambos lados de la puerta "
  	"hay ventanas con cortinas.\n");

  AddDetail(({"pared"}),"Las paredes están decoradas con flores silvestres "
  	"y piedras de colores.\n");
  AddDetail(({"flores"}),"Son flores silvestres, algunas están algo secas, "
  	"otras parecen frescas.\n");
  AddDetail(({"piedras","piedras de colores"}),"Son piedras de muy diversos "
  	"colores, son muy bonitas.\n");
  AddDetail(({"ventana"}),"Es una ventana de madera, esta cubierta por una "
  	"cortina.\n");
  AddDetail(({"cortina"}),"Es una cortina hecha de tela, esta algo gastada.\n");
  AddDetail(({"mesa"}),"Es una mesa de tamaño medio. Encima hay platos, "
  	"vasos y un florero.\n");
  AddDetail(({"silla"}),"Es una silla pequeña de madera.\n");
  AddDetail(({"cama"}),"Es una cama pequeña, y esta hecha.\n");
  AddDetail(({"baul","baúl"}),"Es un gran baúl de madera.\n");
  AddDetail(({"plato"}),"Es un simple plato de madera.\n");
  AddDetail(({"vaso"}),"Es un simple vaso de madera.\n");
  AddDetail(({"florero"}),"Es un florero de barro sin adornos, contiene "
  	"flores silvestres.\n");
  AddDetail(({"techo"}),"El techo esta hecho de paja.\n");
  AddDetail(({"suelo"}),"El suelo es de madera. Está limpio.\n");

  AddExit("sur",FLENHAB+"calles/jefe_00");
  AddItem(FLENPNJ+"poblado/mujer",REFRESH_DESTRUCT);
}