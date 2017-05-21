/*
DESCRIPCION  : Orilla este del río Zarmaii, en el bosque de Zarkam
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/bosque/bosque_56.c
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
    "Kusaii. Si bien no es tan grande como este, posee el suficiente caudal y fuerza "
    "como para disuadir a cualquiera de cruzarlo a nado. La orilla esta repleta de "
    "huellas, posiblemente de animales que vienen a saciar su sed, y de otros que "
    "vienen a saciar su apetito con estos. Si al oeste es el río el que te impide "
    "avanzar, al este lo son unos grandes penyascos.\n");

  AddDetail(({"río","zarmaii","Zarmaii","afluente"}),
    "Este es el río Zarmaii, afluente del Kusaii. Aunque no es muy grande, su "
    "cauce es ciertamente considerable.\n");

  AddDetail(({"huellas","pisadas"}),
    "Cualquiera hubiera deducido que se trata tanto de huellas de herviboros como "
    "algunas de carnivoros. Tambien hay senyales de lucha entre estos.\n");

  AddDetail(({"penyasco","penyascos","penya","penyas"}),
    "Hacia el este se levantan grandes penyascos extremadamente lisos y resvaladizos "
    "como para que nadie los pueda escalar.\n");

  SetIntNoise("Oyes hacia el norte ruido de maquinaria.\n");
  SetIntSmell("El aire esta altamente humedo.\n");
  SetLocate("bosque de Zarkam");
  SetIndoors(0);

  AddExit("sur",Z_BOSQUE("bosque_46"));
  AddExit("suroeste",Z_BOSQUE("bosque_45"));
  AddExit("norte",Z_BOSQUE("bosque_61"));

  AddItem(PNJ("animal/liebre"),REFRESH_DESTRUCT);
}
