/*
DESCRIPCION  : Cordillera de Kova
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/montain_9.c
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
    "La cordillera de Kova suele ser bastante inaccesible, aunque por esta zona se "
    "puede avanzar sin excesivos problemas, al menos para todo aquel que no sufra de "
    "vertigo. Mirando hacia abajo puedes ver un extenso bosque hacia el sur: es "
    "increible como los grandes arboles parecen miniaturas desde aqui. Aunque si te "
    "parecen pequenyos desde aqui, te preguntas como se veran desde las altas "
    "montanyas que te rodean y a las que no puedes acceder. Puedes avanzar hacia el "
    "este hasta un saliente en las rocas.\n");

  AddDetail(({"bosque","arboles"}),
     "Ves como el bosque se extiende hacia el sur.\n");

  AddDetail(({"cordillera","Kova"}),
     "La cordillera de Kova, en la que te encuentras, es una de las mas inospitas "
     "de la region.\n");

  AddDetail(({"saliente"}),
     "Al este puedes ver un saliente en la roca, parece firme, seguro que desde "
     "alli hay unas vistas estupendas.\n");

  SetIntNoise("Reina el silencio.\n");
  SetIntSmell("El aire es algo frio en estas alturas.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("suroeste",Z_BOSQUE("montain_6"));
  AddExit("este",Z_BOSQUE("montain_a"));

  AddItem(PNJ("animal/aguila"),REFRESH_DESTRUCT);
}

