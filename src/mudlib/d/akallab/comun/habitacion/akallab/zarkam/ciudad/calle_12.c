/*
DESCRIPCION : barrio de los espiritus
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_12.c
MODIFICACION: 10-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("el barrio de los espiritus");
 SetIntLong(
     "Te encuentras en una gran avenida que recorre el Barrio de los Espiritus. Al "
     "oeste de aquí se halla un gran edificio de tres plantas. Esta sombria y austera "
     "construcción es la sede local del 'Gremio de Conjuradores'. Un rótulo en su "
     "fachada te indica que en el bajo del edificio que queda al este se encuentra la "
     "tienda de Tzara, donde podrás encontrar todo tipo de objetos relacionados con "
     "la magia o un sortilegio a medida.\n");

  AddDetail(({"rotulo"}),"En el se lee: 'Tienda de magia de Tzara'.\n");

  AddDetail(({"tienda"}),
    "En el bajo del edificio que queda al oeste se halla la pequenya tienda de Tzara. "
    "En ella puedes encontrar todo tipo de objetos relacionados con la magia, desde "
    "varitas hasta amuletos. Seguro que por un buen precio Tzara tambien es capaz de "
    "realizar algun tipo de sortilegio para ti.\n");

  AddDetail(({"gremio","Gremio","gremio de conjuradores"}),
    "Es el sombrio y austero edificio de tres plantas que se encuentra al oeste.\n");

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

  AddExit("norte",Z_CIUDAD("calle_13"));
  AddExit("oeste","/guilds/conjuradores/gremio");
  //AddExit("este",Z_TIENDA("magia"));
  AddExit("sur",Z_CIUDAD("calle_11"));
}
