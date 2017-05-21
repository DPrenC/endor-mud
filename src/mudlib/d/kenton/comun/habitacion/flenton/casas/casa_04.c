/***************************************************************************************
 ARCHIVO:	casa_04.c
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
  SetIntNoise("Escuchas el bullicio de la calle.\n");
  SetIntSmell("Huele a pintura fresca.\n");

  SetIntShort("una casa en la Calle del Jefe");
  SetIntLong("Est�s en el interior de la casa. Parece una casa bastante "
  	"alegre. Las paredes est�n decoradas con diversos grabados y dibujos. "
  	"Hay una cama pegada a la pared, y en el otro lado una mesa y un taburete.\n");

  AddDetail(({"pared"}),"Est� llena de grabados y dibujos bastante bonitos.\n");
  AddDetail(({"ventana"}),"Es una ventana de madera. A trav�s de ella puedes "
  	"ver la calle.\n");
  AddDetail(({"mesa"}),"Es una mesa de tama�o medio, encima hay un par de vasos "
  	"y un plato.\n");
  AddDetail(({"taburete"}),"Ves un peque�o taburete de madera.\n");
  AddDetail(({"cama"}),"Es una cama peque�a, y est� hecha.\n");
  AddDetail(({"plato"}),"Es un simple plato de madera.\n");
  AddDetail(({"vaso"}),"Es un simple vaso de madera.\n");
  AddDetail(({"grabados"}),"Son grabados de madera con motivos de caza.\n");
  AddDetail(({"vaso"}),"Son pinturas con mucho colorido, parecen hechas por un ni�o.\n");
  AddDetail(({"suelo","abajo"}),"El suelo est� bastante limpio. Es de madera.\n");
  AddDetail(({"techo","arriba"}),"El techo est� hecho de paja.\n");

  AddExit("norte",FLENHAB+"calles/jefe_01");
}
