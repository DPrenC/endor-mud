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
  SetIntLong("Est�s dentro de la casa. Las paredes est�n decoradas con "
  	"flores silvestres y y piedras de colores. La casa est� bastante "
  	"limpia y ordenada. En el centro de la est�ncia hay una mesa y dos "
  	"sillas. Al fondo hay un ba�l y una cama. A ambos lados de la puerta "
  	"hay ventanas con cortinas.\n");

  AddDetail(({"pared"}),"Las paredes est�n decoradas con flores silvestres "
  	"y piedras de colores.\n");
  AddDetail(({"flores"}),"Son flores silvestres, algunas est�n algo secas, "
  	"otras parecen frescas.\n");
  AddDetail(({"piedras","piedras de colores"}),"Son piedras de muy diversos "
  	"colores, son muy bonitas.\n");
  AddDetail(({"ventana"}),"Es una ventana de madera, esta cubierta por una "
  	"cortina.\n");
  AddDetail(({"cortina"}),"Es una cortina hecha de tela, esta algo gastada.\n");
  AddDetail(({"mesa"}),"Es una mesa de tama�o medio. Encima hay platos, "
  	"vasos y un florero.\n");
  AddDetail(({"silla"}),"Es una silla peque�a de madera.\n");
  AddDetail(({"cama"}),"Es una cama peque�a, y esta hecha.\n");
  AddDetail(({"baul","ba�l"}),"Es un gran ba�l de madera.\n");
  AddDetail(({"plato"}),"Es un simple plato de madera.\n");
  AddDetail(({"vaso"}),"Es un simple vaso de madera.\n");
  AddDetail(({"florero"}),"Es un florero de barro sin adornos, contiene "
  	"flores silvestres.\n");
  AddDetail(({"techo"}),"El techo esta hecho de paja.\n");
  AddDetail(({"suelo"}),"El suelo es de madera. Est� limpio.\n");

  AddExit("sur",FLENHAB+"calles/jefe_00");
  AddItem(FLENPNJ+"poblado/mujer",REFRESH_DESTRUCT);
}