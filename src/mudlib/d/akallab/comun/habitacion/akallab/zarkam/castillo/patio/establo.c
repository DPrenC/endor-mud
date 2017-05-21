/*
DESCRIPCION : establos del castillo
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/castillo/patio/establo.c
MODIFICACION: 29-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
 SetIntShort("un establo en el castillo");
  SetIntLong(
     "Te encuentras en un establo en el patio del castillo de Zarkam. Es una especie "
     "de cobertizo de madera abierto adosado a la pared de la muralla donde la guardia "
     "de la puerta guarda sus monturas. El suelo esta cubierto por una capa de paja "
     "que se cambia regularmente. Al este de aqui se halla una torre en la muralla.\n");

  AddDetail(({"castillo"}),"El castillo que hacia el oeste.\n");

  AddDetail(({"paja","suelo"}),
    "Todo el suelo del establo esta cubierto de una gruesa capa de paja. Alguien se "
    "encarga de limpiar regularmente el establo cada pocos dias y renueva la paja. "
    "De esta forma esta limpio de los excrementos que dejan los animales.\n");

  SetIntNoise("Oyes a los caballos relinchar.\n");
  SetIntSmell("Hmm.. huele a animales.\n");
  SetLocate("castillo de Zarkam");
  SetIndoors(0);

  AddItem(PNJ("animal/caballo"), REFRESH_DESTRUCT, 2);
  AddExit("norte",Z_CASTILLO("patio/patio01"));
  AddExit("sur",Z_CASTILLO("patio/patio07"));
  AddExit("este",Z_CASTILLO("muralla/torre04"));
  AddExit("oeste",Z_CASTILLO("patio/patio05"));
}
