/*
DESCRIPCION  : Bosque al nordeste de Zarkam.
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_??.c
MODIFICACION : 13-04-98 [Elric@Simauria] Creacion
               10-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetPreIntShort("junto al");
  SetIntShort("río Zarmaii");
  SetIntLong(
"Te encuentras en la orilla del río Zarmaii, uno de los afluentes naturales "
"del Kusaii. Si bien no es tan grande como este, posee el suficiente caudal "
"y fuerza como para disuadir a cualquiera de cruzarlo a nado. "
"Puedes seguir el cauce del río hacia el este, pero no puedes remontarlo "
"hacia el norte debido al acantilado que se alza ante ti, creando una "
"una cascada, no muy grande, pero si lo suficientemente alta como para ser "
"peligroso intentar escalarla.\n");
  SetIndoors(0);
  AddExit("sur",Z_BOSQUE("bosque_07"));
  AddExit("este",Z_BOSQUE("bosque_16"));
  AddExit("oeste",Z_BOSQUE("bosque_14"));
  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
  "Este es el río Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
  "cauce es ciertamente considerable.\n");
  AddDetail(({"cascada","acantilado"}),
  "El río llega hasta aqui cayendo desde un alto acantilado, formando una bella "
  "cascada de agua, pero igual de peligrosa que de hermosa.\n");
  SetIntNoise("Lo unico que puedes oir es el estridente ruido de la cascada.\n");
  SetIntSmell("El aire esta altamente humedo.\n");
  SetLocate("bosque de Zarkam");
}
