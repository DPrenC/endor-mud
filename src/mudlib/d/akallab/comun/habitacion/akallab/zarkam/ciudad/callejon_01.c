/*
DESCRIPCION : barrios bajos de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/callejon_01.c
MODIFICACION: 18-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("los barrios bajos de Zarkam");
 SetIntLong(
    "Estas en un estrecho y oscuro callejon en algun lugar de la ciudad de Zarkam. "
    "Las puertas traseras de varios edificios dan a el, pero por su aspecto dirias "
    "que no parecen haber sido usadas en bastante tiempo. Ves algunos trastos "
    "abandonados a lo largo del callejon.\n");

  AddDetail(({"trastos"}),
    "A lo largo del callejon hay abandonados todo tipo de trastos viejos. Supones "
    "que estan ahi porque o bien molestaban en otra parte o bien eran inutiles para "
    "sus propietarios.\n");

  AddDetail(({"puertas"}),
    "A este callejon dan las puertas traseras de varios edificicios.\n");

  SetIntNoise("Oyes algun gato callejero revolver en el callejon.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  AddExit("oeste",Z_CIUDAD("calle_20"));
}
