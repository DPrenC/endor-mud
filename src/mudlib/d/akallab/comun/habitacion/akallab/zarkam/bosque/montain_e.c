/*
DESCRIPCION  : Cordillera de Kova
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/montain_e.c
MODIFICACION : 10-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("la cordillera de Kova");
  SetIntLong(
    "Te encuentras en la empinada ladera de una de las montanyas de la cordillera de "
    "Kova. Es el unico camino viable, pese a ser bastante peligroso, para subir a "
    "ellas desde el bosque que se extiende a sus pies. Te hallas solo un poco por "
    "encima de la altura de los arboles del bosque que ya comienzas a apreciar en "
    "toda su extension.\n");

  AddDetail(({"bosque"}),"Ves como el bosque se extiende hacia el sur.\n");

  SetIntNoise("Reina el silencio.\n");
  SetIntSmell("El aire es algo frio en estas alturas.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("norte",Z_BOSQUE("montain_8"));
  AddExit("abajo",Z_BOSQUE("bosque_51"));
}

