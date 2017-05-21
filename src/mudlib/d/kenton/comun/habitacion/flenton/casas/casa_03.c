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
  SetIntSmell("�Aqu� huele que apesta! huele a humedad y a cerrado.\n");

  SetIntShort("una casa de la Calle del Jefe");
  SetIntLong("Est�s dentro de la casa. Las paredes est�n cubiertas de mugre "
  	"y moho, y la casa est� bastante desordenada. A ambos lados de la puerta "
  	"hay ventanas con cortinas. En el centro hay una mesa y una silla. Al "
  	"fondo hay una cama.\n");

  AddDetail(({"pared"}),"Esta cubierta de mugre y moho, e incluso alguna que otra "
  	"tela de ara�a.\n");
  AddDetail(({"ventana"}),"Es una ventana de madera, est� cubierta por una cortina.\n");
  AddDetail(({"cortina"}),"est� hecha de tela, pero est� toda rota y hecha girones.\n");
  AddDetail(({"mesa"}),"Es una mesa de tama�o medio. Encima hay un plato y un vaso.\n");
  AddDetail(({"silla"}),"Es una silla peque�a de madera.\n");
  AddDetail(({"cama"}),"Es una cama peque�a y est� sin hacer.\n");
  AddDetail(({"plato"}),"Es un simple plato de madera. A�n tiene restos de comida.\n");
  AddDetail(({"vaso"}),"Es un simple vaso de madera, est� medio lleno.\n");
  AddDetail(({"tela de ara�a"}),"Es una tela de ara�a abandonada.\n");

  AddExit("norte",FLENHAB+"calles/jefe_00");
}