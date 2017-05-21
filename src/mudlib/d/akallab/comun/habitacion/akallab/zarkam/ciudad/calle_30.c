/*
DESCRIPCION : barrio de los artesanos
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_30.c
MODIFICACION: 24-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("el barrio de los artesanos");
 SetIntLong("Te encuentras en una de las calles del barrio de los artesanos. "
            "Al norte observas la fachada lateral de la herrería de la ciudad, "
            "mientras que al sur puedes ver el edificio que aloja la famosa "
            "sastrería de Maoli. Al oeste continúa la calle.\n");



  AddDetail(({"barrio","Barrio","barrio de los artesanos","Barrio de los Artesanos"}),
     "Te encuentras en el Barrio de los Artesanos, una zona al nordeste de la ciudad\n"
     "donde se encuentran los talleres en los que trabajan los artesanos de esta\n"
     "ciudad y en los que suelen vender sus productos y ofrecer sus servicios.\n");

  AddDetail(({"edificio norte","norte"}),
            "Al norte puedes ver la fachada lateral de la herrería de la "
            "ciudad.\n");

 AddDetail(({"edificio sur","sur"}),
           "Al sur puedes ver la fachada lateral de la sastrería de Maoli.\n");

  // SetIntNoise("Oyes el sonido del hierro golpear contra el yunque.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  //AddExit("norte",Z_TIENDA("espadas"));
  AddExit("oeste",Z_CIUDAD("calle_27"));
  //AddExit("este",Z_CIUDAD("calle_"));
  //AddExit("sur",Z_TIENDA("escudos"));
}
