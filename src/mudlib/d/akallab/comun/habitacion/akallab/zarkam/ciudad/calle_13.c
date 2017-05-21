/*
DESCRIPCION : barrio de los espiritus
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_13.c
MODIFICACION: 13-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("el barrio de los espiritus");
 SetIntLong(
     "La gran avenida que recorre este Barrio de los Espiritus gira aqui desde el sur "
     "hacia el oeste. Observas tambien como otra calle se aleja de este barrio hacia "
     "el este en direccion al centro de la ciudad. Al suroeste de aqui se alza el "
     "sombrio edificio del 'Gremio de Conjuradores' y al norte un templo dedicado a "
     "Kavar, uno de los mas importantes dioses que veneran los orcos.\n");

  AddDetail(({"gremio","Gremio","gremio de conjuradores"}),
     "Es el sombrio y austero edificio de tres plantas que se encuentra al suroeste.\n");

  AddDetail(({"templo","Kavar","kavar"}),
     "Kavar es el poderoso dios de la guerra en la mitologia orca. El templo que ves "
     "al norte de aqui esta dedicado a el.\n");

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

  AddExit("norte",Z_TIENDA("templo"));
  AddExit("oeste",Z_CIUDAD("calle_31"));
  AddExit("este",Z_CIUDAD("calle_14"));
  AddExit("sur",Z_CIUDAD("calle_12"));
}
