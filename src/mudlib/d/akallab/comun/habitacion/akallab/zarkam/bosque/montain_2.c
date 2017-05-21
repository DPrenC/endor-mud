/*
DESCRIPCION  : Cordillera de Kova
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/montain_2.c
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
      "En estas alturas la temperatura es bastante baja, incluso cuando puedes ver "
      "el calido sol es como si este perdiera sus fuerzas al llegar a las rocas. "
      "No logras ver ningun tipo de vegetacion, todo a tu alrededor son piedras y "
      "rocas. En tu busca por encontrar algo verde que demuestre que incluso en "
      "las alturas puede haber vida, alzas la vista y descubres en lo mas alto de "
      "un pico, hacia el este, algo parecido a un nido, por desgracia es imposible "
      "alcanzarlo desde aqui.\n");

  AddDetail(({"vegetacion","plantas"}),
      "Es inutil que te esfuerces, parece imposible que nada crezca aqui.\n");

  AddDetail(({"roca","rocas"}),
      "Las rocas de esta montanya son altamente lisas lo que las hace bastante "
      "resvaladizas\n");

  AddDetail(({"pico","nido"}),
      "Dirigiendo tu mirada hacia el este y arriba, puedes ver en lo mas alto de un "
      "inospito pico un pequenyo nido, te preguntas que puede haber en el.\n");

  SetIntNoise("Reina el silencio.\n");
  SetIntSmell("El aire es algo frio en estas alturas.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("oeste",Z_BOSQUE("montain_1"));
  AddExit("sudeste",Z_BOSQUE("montain_4"));
  AddExit("sur",Z_BOSQUE("montain_3"));
}

