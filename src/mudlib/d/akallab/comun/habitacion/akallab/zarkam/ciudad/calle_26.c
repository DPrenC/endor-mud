/*
DESCRIPCION : barrio de los artesanos
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_26.c
MODIFICACION: 23-11-98 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
 ::create();
SetIntShort("el barrio de los artesanos");
 SetIntLong(
 "Te hallas en una ancha calle que recorre el Barrio de los Artesanos de esta "
   "ciudad. Al este de aqui puedes ver la herrería, mientras que al norte y "
   "al sur continúa la calle.\n");

  AddDetail(({"herreria"}), "Queda al este de aqui.\n");


  AddDetail(({"barrio","Barrio","barrio de los artesanos","Barrio de los Artesanos"}),
   "Te encuentras en el Barrio de los Artesanos, una zona al nordeste de la ciudad "
     "donde se encuentran los talleres en los que trabajan los artesanos de esta "
     "ciudad y en los que suelen vender sus productos y ofrecer sus servicios.\n");

  SetIntNoise("Oyes el ajetreo tipico de una ciudad.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  //AddExit("oeste",Z_GREMIO("/guerrero/entrada"));
  AddExit("este",Z_TIENDA("herreria1"));
  AddExit("norte",Z_CIUDAD("calle_25"));
  AddExit("sur",Z_CIUDAD("calle_27"));
}
