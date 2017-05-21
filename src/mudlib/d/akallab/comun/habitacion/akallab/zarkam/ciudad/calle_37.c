/*
DESCRIPCION : barrio de los espiritus
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_37.c
MODIFICACION: 27-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>


inherit ROOM;

int ir_s(){
  if (TP->QueryIsPlayer()) return TP->move(Z_CEMENTERIO("tumba02"),M_GO);
  return 1;
}


create() {
 ::create();
SetIntShort("el barrio de los espíritus");
 SetIntLong(
     "Una vieja verja metalica separa el inquietante y solitario cementerio que ves "
     "al suroeste de esta calle en la que estas. Su entrada se encuentra justo al sur "
     "de aqui, al lado del edificio del 'Gremio de Conjuradores'. Hacia el norte, la "
     "calle se aleja del Barrio de los Espiritus en direccion a los Barrios bajos.\n");

  AddDetail(({"verja"}),
     "Es una vieja verja metalica que separa el cementerio de la calle. Esta en mal "
     "estado y no crees que sea un obstaculo serio para que nada pueda entrar o salir "
     "de alli...\n");

  AddDetail(({"cementerio"}),
     "Observas que al oeste de aqui se halla la entrada a un solitario e inquietante "
     "cementerio. La idea de entrar en el no te resulta demasiado agradable.\n");

  AddDetail(({"gremio","Gremio","gremio de conjuradores","edificio"}),
    "Es el sombrio y austero edificio de tres plantas que se encuentra al sudeste.\n");

  AddDetail(({"barrio","Barrio","barrio de los espiritus","Barrio de los Espiritus"}),
     "Te encuentras en el Barrio de los Espiritus, una zona al suroeste de la ciudad "
     "donde se puede encontrar todo aquello relacionado con la magia o la religion de "
     "esta parte del mundo. Aqui podrias comprar un filtro de amor, rezar u ofrecer un "
     "un sacrificio a alguno de los muchos dioses locales, ingresar en algun gremio "
     "que domine la magia o encontrar una fria sepultura. Las fuerzas que se mueven "
     "por esta zona son poderosas haciendo que incluso los propios orcos, pese a su "
     "fuerte caracter, sean aqui respetuosos...");

  SetIntNoise("Oyes el ajetreo tipico de una ciudad.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  AddExit("sur",SF(ir_s));
  AddExit("este",Z_CIUDAD("calle_31"));
  //AddExit("norte",Z_CIUDAD("calle_"));
}
