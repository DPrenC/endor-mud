/*
DESCRIPCION  : Cordillera de Kova
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/montain_6.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
               28-10-99 [Angor@Simauria] quest
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
  SetIntShort("la cordillera de Kova");
  SetIntLong(
    "Has llegado a uno de los lugares mas altos de la cordillera de Kova a "
      "los que se puede acceder no sin muchos problemas. Aunque estas a una "
      "altura mas que considerable, todavia ves montanyas mucho mas altas que "
      "el lugar en el que te encuentras, hacia el norte. Pero estas montanyas "
      "son inalcanzables para todo aquel que carece de la habilidad de volar "
      "como los pajaros e incluso estos no osan aventurarse a tales alturas, "
      "retando al mismisimo cielo y al frio eterno de esas cuspides.\n");

  AddDetail(({"cordillera","Kova"}),
    "La cordillera de Kova, en la que te encuentras, es una de las mas "
      "inhospitas de la region.\n");

  AddDetail(({"cuspides","montanyas"}),
    "Aunque te encuentras en una zona extremadamente elevada, todavia "
      "puedes ver montanyas mucho mas altas.\n");

  SetIntNoise("Reina el silencio en estas cumbres.\n");
  SetIntSmell("El aire es extremadamente frio en estas alturas.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("este",Z_BOSQUE("montain_c"));

  AddItem(QUEST+"amuleto/nido", REFRESH_ALWAYS);
  AddItem(PNJ("animal/urraca"),REFRESH_DESTRUCT,3);
}

