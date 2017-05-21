/*
DESCRIPCION : patio del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/patio/patio06.c
MODIFICACION: 02-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
 SetIntShort("el patio del castillo");
 SetIntLong(
     "Te encuentras en un amplio corredor que hay entre la muralla y el castillo. "
     "Sobre tu cabeza observas una pasarela que conecta la parte superior de la "
     "muralla con el primer piso del castillo. Al norte se encuentra una de las torres "
     "que forman parte de la muralla.\n");

  AddDetail(({"pasarela"}),
     "Esta sobre tu cabeza. Conecta la muralla con el primer piso del castillo.\n");

  AddDetail(({"castillo"}),
     "La ciudad de Zarkam se ha construido en torno al gran castillo que observas al "
     "al norte de aqui. En el vive el governador orco que el emperador ha elegido "
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

  AddExit("norte",Z_CASTILLO("muralla/torre15"));
  AddExit("oeste",Z_CASTILLO("patio/patio11"));
  AddExit("este",Z_CASTILLO("patio/patio10"));
}

