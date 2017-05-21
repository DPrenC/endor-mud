/*
DESCRIPCION  : Cordillera de Kova
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/montain_3.c
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
"Avanzas por zonas abruptas, un paso en falso puede conducirte a una muerte "
"segura, solo de pensarlo, diriges timidamente tu mirada hacia el sur y te "
"cercioras de que ni siquiera los grandes arboles del bosque alcanzan la "
"altura en la que te encuentras, un frio gelido recorre tu espalda. Aun asi, "
"intentas apartar ese pensamiento de tu mente y comienzas a dar pasos firmes "
"sin que nada rompa tu concentracion.\n");
  SetIndoors(0);
  AddExit("norte",Z_BOSQUE("montain_2"));
  AddExit("este",Z_BOSQUE("montain_4"));
  AddDetail(({"bosque","arboles"}),
  "Ves como el bosque se extiende hacia el sur.\n");
  SetIntNoise("Reina el silencio.\n");
  SetIntSmell("El aire es algo frio en estas alturas.\n");
  SetLocate("bosque de Zarkam");
}

