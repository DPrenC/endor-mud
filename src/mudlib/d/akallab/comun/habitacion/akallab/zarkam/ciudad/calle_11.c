/*
DESCRIPCION : junto a la muralla
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_11.c
MODIFICACION: 10-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("una calle junto a la muralla sur");
 SetIntLong(
     "Te encuentras a la entrada del llamado Barrio de los Espiritus. En esta zona de "
     "la ciudad de Zarkam es donde se puede encontrar todo aquello relacionado con la "
     "magia o con la religion. Al noroeste de aqui se alza un gran edificio, "
     "probablemente la sede de un gremio. Una estrecha callejuela avanza entre el y la "
     "muralla de la ciudad hacia el oeste. Hacia el norte parte una gran avenida.\n");

  AddDetail(({"barrio","Barrio","barrio de los espiritus","Barrio de los Espiritus"}),
     "Te encuentras en el Barrio de los Espiritus, una zona al suroeste de la ciudad "
     "donde se puede encontrar todo aquello relacionado con la magia o la religion de "
     "esta parte del mundo. Aqui podrias comprar un filtro de amor, rezar u ofrecer un "
     "un sacrificio a alguno de los muchos dioses locales, ingresar en algun gremio "
     "que domine la magia o encontrar una fria sepultura. Las fuerzas que se mueven "
     "por esta zona son poderosas haciendo que incluso los propios orcos, pese a su "
     "fuerte caracter, sean aqui respetuosos...");

  AddDetail(({"edificio"}),"Por su aspecto dirias que se trata de un gremio.\n");

  AddDetail(({"muralla"}),
     "Es un inmenso muro de piedra que protege la ciudad rodeandola por completo. "
     "Dirias que como minimo tiene unos cinco metros de altura en las partes mas bajas "
     "y esta protegida con gruesas almenas. Sobre ella hay una pasarela por la que "
     "cada cierto tiempo ves pasar soldados fuertemente armados.\n");

  SetIntNoise("Oyes el ajetreo tipico de una ciudad.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  AddExit("oeste",Z_CIUDAD("calle_36"));
  AddExit("este",Z_CIUDAD("calle_10"));
  AddExit("norte",Z_CIUDAD("calle_12"));
}
