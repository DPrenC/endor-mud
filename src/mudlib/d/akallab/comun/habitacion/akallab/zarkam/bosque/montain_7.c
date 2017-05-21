/*
DESCRIPCION  : Cordillera de Kova
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/montain_7.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Rehecha
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la cordillera de Kova");
  SetIntLong(
     "A estas alturas apenas si existe vegetacion en las montanya debido sobre todo al "
     "gelido viento que las barre incansablemente. Todo a tu alrededor son grandes "
     "rocas y altos acantilados, de forma que avanzar resulta bastante complicado. "
     "Al sur puedes ver como se extiende el bosque y como entre el, hacia el este,  "
     "transcurre el río Zarmaii. Observas una cabanya junto al río.\n");

  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
     "Al este ves el río Zarmaii, afluente del Kusaii. Puedes contemplarlo desde su "
     "nacimiento al norte, hasta que se pierde de vista por el sur.\n");

  AddDetail(({"cabanya"}),
     "Al este, y sobre el Zarmaii, ves una cabanya bastante grande que cruza el río "
     "de orilla a orilla.\n");

  AddDetail(({"roca","rocas"}),
     "Las rocas de esta montanya son altamente lisas lo que las hace bastante "
     "resvaladizas\n");

  AddDetail(({"bosque"}),"Ves como el bosque se extiende hacia el sur.\n");

  SetIntNoise("Reina el silencio.\n");
  SetIntSmell("El aire es algo frio en estas alturas.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("norte",Z_BOSQUE("montain_5"));
  AddExit("este",Z_BOSQUE("montain_8"));
}

