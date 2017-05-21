/*
DESCRIPCION  : Cordillera de Kova
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/montain_a.c
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
"Has llegado a un saliente, desde el que se tiene la que, posiblemente, es la "
"mejor vista de todo el bosque del sur. Desde aqui puedes ver debajo tuyo y "
"al este una cabanya sobre el río Zarmaii. Sin ningun problema ves como el "
"agua del río es retenida al llegar a la cabanya, dejandola escapar por unas "
"compuertas a modo de presa. Aunque todo indica que es una presa, desde aqui "
"te es imposible deducir para que utilizan la fuerza del agua.\n");
  SetIndoors(0);
  AddExit("oeste",Z_BOSQUE("montain_9"));
  AddDetail(({"bosque","arboles"}),
  "Ves como el bosque se extiende hacia el sur.\n");
  AddDetail(({"saliente"}),
  "Te encuentras sobre un saliente bastante firme, te permite una bella vista, "
  "pero solo puedes volver hacia el oeste.\n");
  AddDetail(({"cordillera","Kova"}),
  "La cordillera de Kova, en la que te encuentras, es una de las mas inospitas "
  "de la region.\n");
  AddDetail(({"río","Zarmai","cabanya","presa"}),
  "Por debajo tuya y hacia el este ves una cabanya a modo de presa sobre el río "
  "Zarmaii.\n");
  SetIntNoise("Oyes ruido proveniente de abajo.\n");
  SetIntSmell("El aire es algo frio en estas alturas.\n");
  SetLocate("bosque de Zarkam");
}

