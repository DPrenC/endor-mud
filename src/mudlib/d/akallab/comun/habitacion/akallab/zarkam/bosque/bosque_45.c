/*
DESCRIPCION  : Orilla este del río Zarmaii, en el bosque de Zarkam
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
"del Kusaii. Si bien no es tan grande como este, posee el suficiente caudal "
"y fuerza como para disuadir a cualquiera de cruzarlo a nado. "
"Al sur se encuentra el puente que permite cruzar el río sin peligro de ser "
"arrastrado por su caudal de agua. Al este ves una rara extension de arbustos.\n");
  SetIndoors(0);
  AddExit("sur",Z_BOSQUE("bosque_35"));
  AddExit("este",Z_BOSQUE("bosque_46"));
  AddExit("nordeste",Z_BOSQUE("bosque_56"));
  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
  "Este es el río Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
  "cauce es ciertamente considerable.\n");
  AddDetail(({"puente"}),
  "Al sur puedes ver un puente no muy grande pero bastante eficiente y muy util "
  "para atravesar el río.\n");
  AddDetail(({"arbustos"}),
  "Al este crecen unos arbustos que no logras distinguir desde aqui, pero lo que "
  "si logras distinguir es que forman una grandisima extension.\n");
  SetIntNoise("Al norte oyes algo mas que el agua...\n");
  SetIntSmell("El aire esta altamente humedo.\n");
  SetLocate("bosque de Zarkam");
}
