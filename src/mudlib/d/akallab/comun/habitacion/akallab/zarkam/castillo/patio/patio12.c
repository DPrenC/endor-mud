/*
DESCRIPCION : patio del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/patio12.c
MODIFICACION: 04-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
 SetIntShort("el patio del castillo");
 SetIntLong(
     "Te encuentras en la esquina noroeste de la muralla que rodea el castillo de "
     "Zarkam en un amplio corredor que hay entre ella y el castillo. Desde aqui ves "
     "como el corredor continua hacia el este y hacia el sur. Al noroeste de aqui se "
     "halla la entrada a una de las torres que forman parte de la muralla y al sur, "
     "una pasarela elevada conecta la muralla con la primera planta del castillo.\n");

  AddDetail(({"corredor"}),QueryIntLong());

  AddDetail(({"pasarela"}),
     "Es una especie de puente que conecta las almenas de la muralla con la primera "
     "planta del castillo al sur de aqui.\n");


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

  AddExit("este",Z_CASTILLO("patio/patio11"));
  AddExit("sur",Z_CASTILLO("patio/patio13"));
  AddExit("noroeste",Z_CASTILLO("muralla/torre17"));
}

