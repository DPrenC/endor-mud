/*
DESCRIPCION : calle junto al castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_19.c
MODIFICACION: 16-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <door.h>
#include <properties.h>
#include <scheduler.h>
#include <materials.h>


inherit ROOM;

create() {
 ::create();
SetIntShort("una calle junto al castillo");
 SetIntLong(
    "Te encuentras en una ancha calle que avanza junto a la muralla del castillo de "
    "la ciudad. Al norte puedes ver un edificio que parece estar de "
    "reformas. Al este de aquí la calle acaba en lo que parece ser una gran "
    "plaza.\n");


  AddDetail(({"edificio","norte"}),"Es un edificio que ahora parece estar de "
            "reformas. En la puerta puedes ver un cartel que reza: Oficina de "
            "consignas. ¡Esperamos abrir próximamente!\n");


  AddDetail(({"calle"}),
    "Es una ancha calle que corre junto a las murallas del castillo de la ciudad.\n");

  AddDetail(({"muralla"}),
    "Es la alta pared exterior del castillo. No ves desde aqui que tenga ninguna "
    "puerta que de a esta calle.\n");

  AddDetail(({"castillo"}),
    "La ciudad de Zarkam se ha construido en torno al gran castillo que observas al "
    "al sur de aqui. En el vive el governador orco que el emperador ha elegido "
    "para dirigir esta provincia. El castillo es una inmensa mole de piedra mas alta "
    "que cualquiera de los edificios que lo rodean. Sobre el se alza una alta torre "
    "desde la que se vigila el valle constantemente.\n");

  AddDetail(({"torre"}),"Se alza sobre el castillo.\n");

  SetIntNoise("Se oye el ajetreo tipico de una ciudad.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  AddExit("norte",Z_TIENDA("taquillas"));
  AddExit("este",Z_CIUDAD("plaza_00"));
  AddExit("oeste",Z_CIUDAD("calle_17"));
  AddDoor("norte", "la puerta de las consignas", "Se trata de una gran puerta de madera maciza.\n",
        ({"puerta", "puerta maciza", "puerta de madera"}), GENDER_FEMALE,
        ([P_MATERIAL : M_MADERA, P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}


