/*
DESCRIPCION : calle mayor de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_15.c
MODIFICACION: 11-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
 SetIntShort("una callejuela junto al castillo");
 SetIntLong(
    "La estrecha callejuela en la que te encuentras avanza junto al muro del castillo "
    "que se alza al norte. No ves que haya ninguna entrada al castillo desde esta "
    "calle. Al sur de aqui se halla la casa donde vive un conocido curandero.\n");

  AddDetail(({"callejuela"}),
    "Es una estrecha callejuela que corre junto a la muralla del castillo. Es "
    "bastante larga y en ella hay algunas tiendas.\n");

  AddDetail(({"muralla"}),
    "Es la alta pared exterior del castillo. No ves desde aqui que tenga ninguna "
    "puerta que de a esta callejuela.\n");

  AddDetail(({"castillo"}),
    "La ciudad de Zarkam se ha construido en torno al gran castillo que observas al "
    "al norte de aqui. En el vive el governador orco que el emperador ha elegido "
    "para dirigir esta provincia. El castillo es una inmensa mole de piedra mas alta "
    "que cualquiera de los edificios que lo rodean. Sobre el se alza una alta torre "
    "desde la que se vigila el valle constantemente.\n");

  AddDetail(({"torre"}),"Se alza sobre el castillo.\n");

  SetIntNoise("Se oye el ajetreo tipico de una ciudad.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  AddExit("este",Z_CIUDAD("calle_03"));
  AddExit("oeste",Z_CIUDAD("calle_14"));
  AddExit("sur",Z_TIENDA("curandero"));
}