/*
DESCRIPCION : puerto de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/puerto/muelle00.c
MODIFICACION:
30-10-98 [Angor@Simauria] Creacion
07-02-00 [Angor@Simauria] Modificaciones varias
*/

#include "path.h"
#include AK_MACRO
inherit PORT;

create(){
 ::create();
SetIntShort("el puerto de Azzor");
 SetIntLong(
  "Estás en la dársena del puerto de la ciudad de Azzor. El muelle continúa "
  "hacia el Sur y hacia el Norte en dirección a la fortaleza. Lejos, al Este, "
  "observas los macizos malecones que protegen a los barcos aquí fondeados del "
  "fuerte oleaje. En esta parte del muelle hace escala la goleta Audaz, que "
  "realiza el trayecto entre Gorat y Azzor.\n");

#include "puerto_detail.h"

 AddShip(BAR_AUDAZ("audaz"));

 AddExit("norte",AZ_PUERTO("muelle03"));
 //AddExit("oeste",AZ_PUERTO("calle00"));
 AddExit("sur",AZ_PUERTO("muelle04"));
 AddExit("oeste",AZ_CIUDAD("calle00"));
 AddItem(PNJ_AZZOR("kalur"),REFRESH_DESTRUCT);
}
