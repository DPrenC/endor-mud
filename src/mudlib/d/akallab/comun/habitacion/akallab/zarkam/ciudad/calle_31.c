/*
DESCRIPCION : barrio de los espiritus
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_31.c
MODIFICACION: 27-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("el barrio de los espiritus");
 SetIntLong(
     "Te encuentras en una gran avenida que recorre el Barrio de los Espiritus. Al "
     "sur de aqui se halla el sombrio edificio del 'Gremio de Conjuradores'. En la "
     "casa que queda al norte vive una conocida vidente muy popular en la ciudad. "
     "Junto a la puerta de la casa hay un rotulo de madera.\n");

  AddDetail(({"rotulo"}),
     "Escrito en el rotulo de madera esta escrito lo siguiente: "
     " Consulta de Jezhabel, maestra en multiples artes magicas y adivinatorias. "
     " Servicios: Videncia, adivinacion, quiromancia.\n");

  AddDetail(({"casa"}),"Queda al norte de aqui. En ella vive la vidente Jezhabel.\n");

  AddDetail(({"gremio","Gremio","gremio de conjuradores","edificio"}),
    "Es el sombrio y austero edificio de tres plantas que se encuentra al sur.\n");

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

  AddExit("oeste",Z_CIUDAD("calle_37"));
  AddExit("este",Z_CIUDAD("calle_13"));
  //AddExit("norte",Z_TIENDA("vidente"));
}
