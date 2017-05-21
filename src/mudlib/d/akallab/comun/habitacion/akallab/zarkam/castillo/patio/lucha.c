/*
DESCRIPCION : zona de lucha en el patio del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/patio/lucha.c
MODIFICACION: 02-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("la zona de lucha");
 SetIntLong(
     "En esta zona del patio del castillo suelen entrenarse los soldados. Ademas del "
     "ejercicio en si, el entrenamiento les hace mejorar sus habilidades en la lucha "
     "cuerpo a cuerpo, convirtiendolos en peligrosos adversarios. Al sur junto a la "
     "muralla puedes ver varias grandes dianas.\n");

  AddDetail(({"diana","dianas"}),"Quedan al sur de aqui.\n");

  AddDetail(({"castillo"}),
     "La ciudad de Zarkam se ha construido en torno al gran castillo que observas al "
     "al oeste de aqui. En el vive el governador orco que el emperador ha elegido "
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

  AddExit("norte",Z_CASTILLO("patio/patio05"));
  AddExit("sur",Z_CASTILLO("patio/tiro"));
  AddExit("este",Z_CASTILLO("patio/patio07"));

  AddItem(PNJ("z_castillo/luchador"),REFRESH_DESTRUCT,2);
}

