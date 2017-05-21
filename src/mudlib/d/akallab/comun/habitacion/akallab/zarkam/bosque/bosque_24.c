/*
DESCRIPCION  : Orilla este del río Zarmaii, en el bosque de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_24.c
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
    "Te encuentras en la orilla del río Zarmaii, uno de los afluentes naturales del "
    "Kusaii. Su cauce es bastante complicado, al sur se pierde en un acantilado dando "
    "lugar a una cascada. No hay arboles en esta orilla del río, por lo que no parece "
    "que ningun animal se pueda ocultar para darte caza. Al nordeste puedes ver un "
    "pequenyo puente que cruza el río...\n");

  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
    "Este es el río Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
    "cauce es ciertamente considerable.\n");

  AddDetail(({"cascada","acantilado"}),
    "El cauce del río se pierde por el sur en un alto acantilado, formando una "
    "bella cascada de agua, pero igual de peligrosa que de hermosa.\n");

  AddDetail(({"puente"}),
    "Al nordeste ves un puente no muy grande pero seguro que eficiente y muy util "
    "para atravesar el río.\n");

  SetIntNoise("Lo unico que puedes oir es el estridente ruido de la cascada.\n");
  SetIntSmell("El aire esta altamente humedo.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("norte",Z_BOSQUE("bosque_34"));
  AddExit("este",Z_BOSQUE("bosque_25"));
  AddExit("nordeste",Z_BOSQUE("bosque_35"));

  AddItem(PNJ("animal/liebre"),REFRESH_DESTRUCT);
}
