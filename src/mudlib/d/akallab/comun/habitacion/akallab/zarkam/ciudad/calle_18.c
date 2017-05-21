/*
DESCRIPCION : barrios bajos de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_18.c
MODIFICACION: 18-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("los barrios bajos de Zarkam");
 SetIntLong(
    "Te encuentras en los barrios bajos de la ciudad de Zarkam, una zona atractiva y "
    "tambien peligrosa. El gran edificio que queda al norte es uno de los mas "
    "conocidos burdeles de esta ciudad. Es muy popular y se comenta que incluso el "
    "governador lo visita de vez en cuando. Oyes voces y musica que provienen de la "
    "taberna que queda al sur de aqui.\n");

  AddDetail(({"burdel","edificio"}),
    "En el gran edificio que queda justo al norte se halla uno de los mas conocidos "
    "burdeles de Zarkam, 'La Gran Juerga'. Es uno de los lugares mas populares de la "
    "ciudad donde te podras divertir por una razonable suma de dinero. Es conocido "
    "incluso fuera del valle y se comenta que incluso el governador lo visita de vez "
    "en cuando.\n");

  AddDetail(({"taberna"}),
    "El edificio que queda justo al sur de aqui se encuentra una taberna, a la que "
    "un triste rotulo en su fachada la identifica como 'El Tonel de Vino'. Oyes "
    "voces y musica que provienen de su interior.\n");

  SetIntNoise("Oyes voces y musica.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  //AddExit("oeste",Z_CIUDAD("calle_"));
  AddExit("este",Z_CIUDAD("calle_17"));
  //AddExit("norte",Z_BURDEL("entrada"));
  //AddExit("sur",Z_TIENDA("taberna00"));
}
