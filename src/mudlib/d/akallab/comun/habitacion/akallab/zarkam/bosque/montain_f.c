/*
DESCRIPCION  : Cordillera de Kova
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/montain_f.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la cordillera de Kova");
  SetIntLong(
"Has llegado a uno de los lugares mas altos de la cordillera de Kova a los "
"que se puede acceder no sin muchos problemas. Aunque estas a una altura mas "
"que considerable, todavia ves montanyas mucho mas altas que el lugar en el "
"que te encuentras, hacia el norta. Pero estas montanyas son inalcanzables "
"para todo aquel que carece de la habilidad de volar como los pajaros e "
"incluso estos no osan aventurarse a tales alturas, retando al mismisimo "
"cielo y al frio eterno de esas cuspides.\n");
  SetIndoors(0);
  AddExit("oeste",Z_BOSQUE("montain_c"));
  AddExit("sur",Z_BOSQUE("montain_d"));
  AddDetail(({"cordillera","Kova"}),
  "La cordillera de Kova, en la que te encuentras, es una de las mas inospitas "
  "de la region.\n");
  AddDetail(({"cuspides","montanyas"}),
  "Aunque te encuentras en una zona extremadamente elevada, todavia puedes ver "
  "montanyas mucho mas altas.\n");
  SetIntNoise("Reina el silencio.\n");
  SetIntSmell("El aire es extremadamente frio en estas alturas.\n");
  SetLocate("bosque de Zarkam");
}

