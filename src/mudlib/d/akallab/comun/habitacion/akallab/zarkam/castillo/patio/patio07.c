/*
DESCRIPCION : zona de entrenamiento en el patio del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/patio/patio07.c
MODIFICACION: 02-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
SetIntShort("la zona de entrenamiento");
 SetIntLong(
     "Te encuentras en la zona de entrenamiento del castillo. Aqui junto a la muralla "
     "hay un gran barril con agua y unos bancos de madera en los que los soldados "
     "suelen descansar tras el entrenamiento o cuidar sur armas. Al norte de aqui se "
     "halla un establo donde los soldados tienen a sus monturas.\n");

  AddDetail(({"establo"}),"Queda al norte de aqui.\n");

  AddDetail(({"banco","bancos"}),
     "Junto a la muralla hay varios alargados bancos de madera. Estan hechos de forma "
     "mas bien tosca con varios gruesos tablones de madera.\n");

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

  AddExit("norte",Z_CASTILLO("patio/establo"));
  AddExit("sur",Z_CASTILLO("patio/swordmaster"));
  AddExit("oeste",Z_CASTILLO("patio/lucha"));

  //AddItem(PNJ("z_castillo/reparador"),REFRESH_DESTRUCT);
  AddItem(BEBIDA("barril_agua"),REFRESH_DESTRUCT);
}

