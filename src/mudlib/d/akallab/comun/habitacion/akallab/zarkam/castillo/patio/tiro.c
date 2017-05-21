/*
DESCRIPCION : zona de tiro en el patio del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/tiro.c
MODIFICACION: 02-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("la zona de tiro");
 SetIntLong(
     "Te hallas en una zona del patio del castillo dedicada al entrenamiento de los "
     "soldados. Aqui puedes ver varias grandes dianas de esparto donde los soldados "
     "practican el tiro con arco y, sobre todo, el lanzamiento de armas arrojadizas "
     "tales como machetes o dagas. Al oeste observas un corredor que avanza entre la "
     "muralla y el castillo.\n");

  AddDetail(({"diana","dianas"}),
     "Al sur, junto a la pared de la muralla se encuentran varias grandes dianas. Son "
     "unos bloques de esparto arrollado de forma circular sobre los que se han pintado "
     "varias circulos concentricos. Los soldados los usan para entrenar su punteria, "
     "ya sea con el arco o con armas arrojadizas como las dagas. Por su estado dirias "
     "las han usado bastante.\n");

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

  AddExit("norte",Z_CASTILLO("patio/lucha"));
  AddExit("oeste",Z_CASTILLO("patio/patio08"));
  AddExit("este",Z_CASTILLO("patio/swordmaster"));

  AddItem(PNJ("z_castillo/lanzador"),REFRESH_DESTRUCT);
}

