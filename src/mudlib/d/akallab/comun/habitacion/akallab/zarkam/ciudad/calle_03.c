/*
DESCRIPCION : calle mayor de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_03.c
MODIFICACION: 11-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
 SetIntShort("la calle mayor de Zarkam");
 SetIntLong(
    "Te encuentras en un cruce en la calle mayor de Zarkam. Desde el oeste llega una "
    "estrecha callejuela que avanza junto a la muralla del inmenso castillo que se "
    "alza en medio de la ciudad al noroeste de aqui. Observas como un poco mas hacia "
    "el norte la calle alcanza una gran plaza. Al este se encuentra una de las "
    "entradas al alto edificio que es la posada del 'Cuervo Blanco'.\n");

  AddDetail(({"callejuela"}),
    "Es una estrecha callejuela que corre junto a la muralla del castillo. Es "
    "bastante larga y en ella hay algunas tiendas.\n");

  AddDetail(({"muralla"}),
    "Es la alta pared exterior del castillo. No ves desde aqui que tenga ninguna "
    "puerta que de a la callejuela que parte hacia el oeste.\n");

  AddDetail(({"castillo"}),
    "La ciudad de Zarkam se ha construido en torno al gran castillo que observas al "
    "al noroeste de aqui. En el vive el governador orco que el emperador ha elegido "
    "para dirigir esta provincia. El castillo es una inmensa mole de piedra mas alta "
    "que cualquiera de los edificios que lo rodean. Sobre el se alza una alta torre "
    "desde la que se vigila el valle constantemente.\n");

  AddDetail(({"torre"}),"Se alza sobre el castillo.\n");

  AddDetail(({"posada"}),
    "Es el alto edificio que queda al este de aqui en el que los viajeros pueden "
    "encontrar alojamiento por un modico precio. Su puerta principal debe dar a la "
    "plaza, ya que la que ves al este de aqui parece una entrada secundaria.\n");

  SetIntNoise("Se oye el ajetreo tipico de una ciudad.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);

  AddExit("norte",Z_CIUDAD("plaza_02"));
  AddExit("este",Z_POSADA("entrada"));
  AddExit("oeste",Z_CIUDAD("calle_15"));
  AddExit("sur",Z_CIUDAD("calle_02"));
}