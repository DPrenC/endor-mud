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
"La orilla esta repleta de huellas, posiblemente de animales que vienen a "
"saciar su sed, y de otros que vienen a saciar su apetito con estos. "
"Incluso desde aqui puedes apreciar el gran arbol que se alza al sur.\n");
  SetIndoors(0);
  AddExit("sudeste",Z_BOSQUE("bosque_17"));
  AddExit("oeste",Z_BOSQUE("bosque_24"));
  AddExit("este",Z_BOSQUE("bosque_26"));
  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
  "Este es el río Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
  "cauce es ciertamente considerable.\n");
  AddDetail(({"huellas","pisadas"}),
  "Cualquiera hubiera deducido que se trata tanto de huellas de herviboros como "
  "algunas de carnivoros. Tambien hay senyales de lucha entre estos.\n");
  AddDetail(({"arbol"}),
  "Al sur ves un gran arbol que parece ser muy antiguo. Al mirar al otro lado "
  "del río ves otro arbol, mas pequenyo, que entrecruza sus ramas con este.\n");
  SetIntNoise("Oyes el rumor del agua.\n");
  SetIntSmell("El aire esta altamente humedo.\n");
  SetLocate("bosque de Zarkam");
}
