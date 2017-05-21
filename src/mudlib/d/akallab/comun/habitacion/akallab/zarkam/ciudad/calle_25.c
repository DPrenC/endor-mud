/*
DESCRIPCION : junto a la muralla
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_25.c
MODIFICACION: 23-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("una calle junto a la muralla norte");
 SetIntLong(
     "Te encuentras a la entrada del llamado Barrio de los Artesanos. En esta zona de\n"
     "la ciudad de Zarkam es donde los artesanos locales tienen sus talleres en\n"
     "los que fabrican y suelen vender sus productos. Una calle avanza junto a\n"
     "la muralla del castillo hacia este y oeste, y otra, parte hacia el sur.\n");

  AddDetail(({"barrio","Barrio","barrio de los artesanos","Barrio de los Artesanos"}),
     "Te encuentras en el Barrio de los Artesanos, una zona al nordeste de la ciudad\n"
     "donde se encuentran los talleres en los que trabajan los artesanos de esta\n"
     "ciudad y en los que suelen vender sus productos y ofrecer sus servicios.\n");


  AddDetail(({"muralla"}),
     "Es un inmenso muro de piedra que protege la ciudad rodeandola por completo.\n"
     "Dirias que como minimo tiene unos cinco metros de altura en las partes mas bajas\n"
     "y esta protegida con gruesas almenas. Sobre ella hay una pasarela por la que\n"
     "cada cierto tiempo ves pasar soldados fuertemente armados.\n");

  SetIntNoise("Oyes el ajetreo tipico de una ciudad.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  //AddExit("este",Z_CIUDAD("calle_"));
  AddExit("oeste",Z_CIUDAD("calle_24"));
  AddExit("sur",Z_CIUDAD("calle_26"));
}
