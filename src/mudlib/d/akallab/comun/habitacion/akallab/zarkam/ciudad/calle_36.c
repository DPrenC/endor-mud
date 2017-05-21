/*
DESCRIPCION : callejuela junto a la muralla
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_36.c
MODIFICACION: 25-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>


inherit ROOM;

int ir_o(){
  if (TP->QueryIsPlayer()) return TP->move(Z_CEMENTERIO("tumba00"),M_GO);
  return 1;
}

create() {
 ::create();
SetIntShort("una callejuela junto a la muralla");
 SetIntLong(
     "Te hallas en una estrecha callejuela que corre encajonada entre la muralla sur "
     "de la ciudad y el alto edificio del 'Gremio de Conjuradores' que queda al norte. "
     "Al este de aqui observas como la callejuela llega a lo que parece ser una ancha "
     "avenida y al oeste a un cementerio.\n");

  AddDetail(({"cementerio"}),
     "Observas que al oeste de aqui se halla la entrada a un solitario e inquietante "
     "cementerio. La idea de entrar en el no te resulta demasiado agradable.\n");

  AddDetail(({"muralla"}),
     "Es un inmenso muro de piedra que protege la ciudad rodeandola por completo. "
     "Dirias que como minimo tiene unos cinco metros de altura en las partes mas bajas "
     "y esta protegida con gruesas almenas. Sobre ella hay una pasarela por la que "
     "cada cierto tiempo ves pasar soldados fuertemente armados.\n");

  AddDetail(({"gremio","Gremio","gremio de conjuradores","edificio"}),
    "Es el sombrio y austero edificio de tres plantas que se encuentra al norte.\n");

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

  AddExit("oeste",SF(ir_o));
  AddExit("este",Z_CIUDAD("calle_11"));
}
