/*
DESCRIPCION : zona de tiro en el patio del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/patio10.c
MODIFICACION: 02-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("el patio del castillo");
 SetIntLong(
     "Te hallas al norte del amplio patio que existe entre la muralla y el castillo de "
     "Zarkam. El castillo, que queda al suroeste, es una inmensa mole de piedra sobre "
     "la que se alza una alta torre. Al oeste observas un corredor que avanza entre la "
     "muralla y el castillo y al sudeste, adosada a la muralla, una caseta donde vive "
     "la guardia que custodia la entrada.\n");

  AddDetail(({"caseta"}),"Se halla al sudeste de aqui adosada a la muralla.\n");
  AddDetail("corredor","Se encuentra al oeste de aqui.\n");

  AddDetail(({"castillo"}),
     "La ciudad de Zarkam se ha construido en torno al gran castillo que observas al "
     "al noroeste de aqui. En el vive el governador orco que el emperador ha elegido "
     "para dirigir esta provincia. El castillo es una inmensa mole de piedra mas alta "
     "que cualquiera de los edificios que lo rodean. Sobre el se alza una alta torre "
     "desde la que se vigila el valle constantemente.\n");

  AddDetail(({"torre"}),"Se alza sobre el castillo. Desde alli se vigila todo el valle...\n");

  AddDetail(({"muralla"}),
     "Es un inmenso muro de piedra que protege el castillo rodeandola por completo. "
     "Dirias que debe tener al menos unos cinco metros de altura en las partes mas "
     "bajas sin contar con las almenas. Cada cierta distancia observas una torre o una "
     "escalera adosada a la muralla que permiten subir a ella. Continamente ves a "
     "soldados fuertemente armados patrullando sobre la muralla.\n");

  SetIntNoise("Se oye el ajetreo tipico del castillo.\n");
  SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
  SetLocate("castillo de Zarkam");
  SetIndoors(0);

  AddExit("este",Z_CASTILLO("patio/patio03"));
  AddExit("oeste",Z_CASTILLO("patio/patio06"));
  AddExit("sur",Z_CASTILLO("patio/patio04"));
}

