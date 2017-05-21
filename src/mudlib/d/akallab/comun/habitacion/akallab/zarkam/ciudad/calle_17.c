/*
DESCRIPCION : en una calle de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_17.c
MODIFICACION: 16-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("una calle de Zarkam");
 SetIntLong(
     "Al noroeste de aqui comienzan los barrios bajos de esta ciudad, una zona donde "
     "se puede encontrar todo tipo de diversion y otras cosas... Es un lugar bastante "
     "conflictivo, especialmente por las noches, por lo que no es muy aconsejable "
     "aventurarse a solas en el. La ancha calle que rodea el castillo avanzando "
     "junto a su muralla gira aqui desde el este hacia el sur.\n");

  AddDetail(({"calle"}),
    "Es una ancha calle que corre junto a las murallas del castillo de la ciudad.\n");

  AddDetail(({"muralla"}),
     "Es la alta pared exterior del castillo. No ves desde aqui que tenga ninguna "
     "puerta que de esta calle.\n");

  AddDetail(({"castillo"}),
     "La ciudad de Zarkam se ha construido en torno al gran castillo que observas al "
     "al sudeste de aqui. En el vive el governador orco que el emperador ha elegido "
     "para dirigir esta provincia. El castillo es una inmensa mole de piedra mas alta "
     "que cualquiera de los edificios que lo rodean. Sobre el se alza una alta torre "
     "desde la que se vigila el valle constantemente.\n");

  AddDetail(({"torre"}),"Se alza sobre el castillo.\n");

  SetIntNoise("Oyes el ajetreo tipico de una ciudad.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  AddExit("oeste",Z_CIUDAD("calle_18"));
  AddExit("este",Z_CIUDAD("calle_19"));
  AddExit("norte",Z_CIUDAD("calle_20"));
  AddExit("sur",Z_CIUDAD("calle_16"));
}
