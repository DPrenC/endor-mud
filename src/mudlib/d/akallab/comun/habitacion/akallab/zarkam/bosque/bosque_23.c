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
  SetPreIntShort("junto a");
  SetIntShort("el río Zarmaii");
  SetIntLong(
"Te encuentras en la orilla del río Zarmaii, uno de los afluentes naturales "
"del Kusaii. Su cauce es bastante complicado, al sur se pierde en un  "
"acantilado formando una cascada. "
"A pesar de la cascada, hay indicios de que mas de una vez el río se ha "
"desbordado en esta zona, tal vez debido a la maleza acumulada. Aunque "
"por suerte, al hallarte en una zona abierta, sin arboles, el suelo ha "
"secado rapidamente.\n");
  SetIndoors(0);
  AddExit("oeste",Z_BOSQUE("bosque_22"));
  AddExit("noroeste",Z_BOSQUE("bosque_32"));
  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
  "Este es el río Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
  "cauce es ciertamente considerable.\n");
  AddDetail(({"cascada","acantilado"}),
  "El cauce del río se pierde por el sur en un alto acantilado, formando una "
  "bella cascada de agua, pero igual de peligrosa que de hermosa.\n");
  SetIntNoise("Lo unico que puedes oir es el estridente ruido de la cascada.\n");
  SetIntSmell("El aire esta altamente humedo.\n");
  SetLocate("bosque de Zarkam");
}
