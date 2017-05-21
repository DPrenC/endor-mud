/*
DESCRIPCION : barrios bajos de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_20.c
MODIFICACION: 18-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("los barrios bajos de Zarkam");
 SetIntLong(
    "Te encuentras en una de las calles que forman los barrios bajos de esta ciudad. "
    "Por lo que sabes, el gran edificio que se alza al oeste es 'La Gran Juerga', un "
    "conocido burdel. Hacia el este parte un oscuro callejon.\n");

  AddDetail(({"burdel","edificio"}),
    "En el gran edificio que queda justo al oeste se halla uno de los mas conocidos "
    "burdeles de Zarkam, 'La Gran Juerga'. Es uno de los lugares mas populares de la "
    "ciudad donde te podras divertir por una razonable suma de dinero. Es conocido "
    "incluso fuera del valle y se comenta que incluso el governador lo visita de vez "
    "en cuando.\n");

  AddDetail(({"callejon"}),
    "Un oscuro y estrecho callejon parte hacia el este de aqui. Esta lleno de trastos "
    "por lo que debe ser un buen lugar para esconderse. No parece muy recomendable...\n");

  SetIntNoise("Oyes algun gato callejero revolver en el callejon.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  AddExit("este",Z_CIUDAD("callejon_01"));
  AddExit("norte",Z_CIUDAD("calle_21"));
  AddExit("sur",Z_CIUDAD("calle_17"));
}
