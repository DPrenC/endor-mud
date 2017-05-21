/*
DESCRIPCION : plaza de central de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/plaza_01.c
MODIFICACION: 12-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el norte de la plaza");
  SetIntLong(
    "La plaza mayor de Zarkam se extiende ante ti. Observas que en el medio de ella "
    "hay construido un patibulo del que cuelgan varias horcas. Los edficios que "
    "rodean la plaza son los mas altos y ricos de la ciudad, pero no son comparables "
    "con el impresionante castillo del governardor que se alza al oeste. La calle "
    "mayor de Zarkam parte desde aqui hacia la puerta norte de la ciudad. Al este "
    "se halla la parada de las diligencias y las caravanas.\n");

  AddDetail(({"diligencia","parada","caravanas"}),
    "En el edificio que queda al este de aqui es la parada de la diligencia. Es el "
    "lugar al que llegan las diligencias y carvanas a la ciudad procedentes de otros "
    "lugares. Alli podras comprar un billete o informarte de los horarios de las que "
    "regularmente parten de Zarkam.\n");

  AddDetail(({"calle"}),
    "La calle mayor de Zarkam parte de esta parte de la plaza hacia la puerta norte "
    "de la ciudad.\n");

  AddDetail(({"patibulo"}),
    "Es una plataforma elevada de madera con varias horcas. Es alli donde se ejecuta "
    "publicamente a los delincuentes o prisioneros de guerra como castigo publico y "
    "como advertencia al resto de la poblacion.\n");

  AddDetail(({"horcas"}),
    "Varias horcas hechas con una gruesa soga cuelgan de la viga superior del "
    "en ellas los orcos ajustician publicamente a quien el governador decide.\n");

  AddDetail(({"plaza","plaza central"}),
    "Es una gran explanada que se encuentra en el centro de la ciudad de Zarkam. A su "
    "alrededor se alzan altos edificios y al oeste el castillo de la ciudad. Es el "
    "lugar en que se reune la gente cuando se producen ejecuciones publicas o cuando "
    "el governador realiza algun importante anuncio.\n");

  AddDetail(({"castillo"}),
    "La ciudad de Zarkam se ha construido en torno al gran castillo que observas al "
    "al suroeste de aqui. En el vive el governador orco que el emperador ha elegido "
    "para dirigir esta provincia. El castillo es una inmensa mole de piedra mas alta "
    "que cualquiera de los edificios que lo rodean. Sobre el se alza una alta torre "
    "desde la que se vigila el valle constantemente.\n");

  AddDetail(({"torre"}),"Se alza sobre el castillo.\n");

  SetIntNoise("Se oye el ajetreo tipico de una ciudad.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  AddExit("sur",Z_CIUDAD("plaza_03"));
  AddExit("este",Z_TIENDA("diligencia"));
  AddExit("oeste",Z_CIUDAD("plaza_00"));
  AddExit("norte",Z_CIUDAD("calle_04"));
}
