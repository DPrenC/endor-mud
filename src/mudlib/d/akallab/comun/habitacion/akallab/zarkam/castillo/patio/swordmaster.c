/*
DESCRIPCION : zona de entrenamiento con el maesto de armas en el patio del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/patio/swordmaster.c
MODIFICACION: 02-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("la zona del maestro de armas");
 SetIntLong(
     "Te encuentras en la esquina sudeste del patio del castillo. En esta zona suele "
     "hallarse el maestro de armas del castillo, un experimentado guerrero que entrena "
     "a los soldados en el uso de todo tipo de armas para combate cuerpo a cuerpo. Al "
     "oeste de aqui ves varias grandes dianas y al sudeste la entrada a una de las "
     "torres que forman parte de la muralla.\n");

  AddDetail(({"diana","dianas"}),"Quedan al oeste de aqui.\n");

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

  AddExit("norte",Z_CASTILLO("patio/patio07"));
  AddExit("sudeste",Z_CASTILLO("muralla/torre10"));
  AddExit("oeste",Z_CASTILLO("patio/tiro"));

  //AddItem(PNJ("z_castillo/swordmaster"),REFRESH_DESTRUCT);
}

