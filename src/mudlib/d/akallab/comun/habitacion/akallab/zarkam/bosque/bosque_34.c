/*
DESCRIPCION  : Orilla este del r�o Zarmaii, en el bosque de Zarkam
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
  SetIntShort("el r�o Zarmaii");
  SetIntLong(
"Te encuentras en la orilla del r�o Zarmaii, uno de los afluentes naturales "
"del Kusaii. Si bien no es tan grande como este, posee el suficiente caudal "
"y fuerza como para disuadir a cualquiera de cruzarlo a nado. "
"La orilla esta repleta de huellas, posiblemente de animales que vienen a "
"saciar su sed, y de otros que vienen a saciar su apetito con estos. "
"Ves un puente que permite atravesar el r�o al este\n");
  SetIndoors(0);
  AddExit("este",Z_BOSQUE("bosque_35"));
  AddExit("sur",Z_BOSQUE("bosque_24"));
  AddDetail(({"r�o","zarmaii","Zarmaii","afluente"}),
  "Este es el r�o Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
  "cauce es ciertamente considerable.\n");
  AddDetail(({"puente"}),
  "Al nordeste ves un puente no muy grande pero seguro que eficiente y muy util "
  "para atravesar el r�o.\n");
  AddDetail(({"huellas","pisadas"}),
  "Cualquiera hubiera deducido que se trata tanto de huellas de herviboros como "
  "algunas de carnivoros. Tambien hay senyales de lucha entre estos.\n");
  SetIntNoise("Oyes como corre el agua r�o abajo.\n");
  SetIntSmell("El aire esta altamente humedo.\n");
}
