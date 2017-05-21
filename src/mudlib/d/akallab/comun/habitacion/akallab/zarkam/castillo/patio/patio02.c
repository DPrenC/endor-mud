/*
DESCRIPCION : patio del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/patio02.c
MODIFICACION: 30-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
 SetIntShort("la entrada al castillo");
 SetIntLong(
     "Te hallas en el amplio patio que hay entre el castillo de Zarkam, que se alza "
     "al oeste de aqui, y la muralla que lo rodea. El castillo es una inmensa mole "
     "de piedra mas alta que cualquiera de los edificios de la ciudad sobre el que se "
     "alza una alta torre. Una ancha rampa permite llegar hacia su entrada al oeste.\n");

  AddDetail(({"castillo"}),
     "La ciudad de Zarkam se ha construido en torno al gran castillo que observas al "
     "al oeste de aqui. En el vive el governador orco que el emperador ha elegido "
     "para dirigir esta provincia. El castillo es una inmensa mole de piedra mas alta "
     "que cualquiera de los edificios que lo rodean. Sobre el se alza una alta torre "
     "desde la que se vigila el valle constantemente.\n");

  AddDetail(({"torre"}),"Se alza sobre el castillo. Desde alli se vigila todo el valle...\n");

  AddDetail(({"rampa"}),
      "La planta baja del castillo se halla un poco por encima del nivel del suelo del "
      "patio. Es por ello que existe una amplia rampa de piedra permite llegar a la "
      "entrada del castillo desde aqui.\n");

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

  AddExit("sur",Z_CASTILLO("patio/patio05"));
  AddExit("norte",Z_CASTILLO("patio/patio04"));
  //AddExit("oeste",Z_CASTILLO("piso0/entrada"));
  AddExit("este",Z_CASTILLO("patio/patio01"));
}

