/*
DESCRIPCION : establo de la guardia de las puertas de la ciudad
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
     "Te encuentras en el establo de la guardia de la puerta de la ciudad de Zarkam. "
     "Es una especie de cobertizo de madera abierto adosado a la pared de la muralla "
     "donde la guardia de la puerta guarda sus monturas. El suelo esta cubierto por "
     "una capa de paja que se cambia regularmente. Al oeste de aqui se halla una de "
     "las torres que forman la puerta de la ciudad.\n");

  AddDetail(({"paja","suelo"}),
    "Todo el suelo del establo esta cubierto de una gruesa capa de paja. Alguien se "
    "encarga de limpiar regularmente el establo cada pocos dias y renueva la paja. "
    "De esta forma esta limpio de los excrementos que dejan los animales.\n");

  AddDetail(({"torre"}),
     "Es una inmensa torre de piedra. Junto con otra igual que se halla mas al oeste "
     "forman la entrada sur a esta ciudad.\n");

  AddDetail(({"muralla"}),
     "Es un inmenso muro de piedra que protege la ciudad rodeandola por completo. "
     "Dirias que como minimo tiene unos cinco metros de altura en las partes mas bajas "
     "y esta protegida con gruesas almenas. Sobre ella hay una pasarela por la que "
     "cada cierto tiempo ves pasar soldados fuertemente armados.\n");

  SetIntNoise("Oyes a los caballos relinchar.\n");
  SetIntSmell("Hmm.. huele a animales.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(0);
  SetIntBright(30);

  AddItem(PNJ("animal/caballo"), REFRESH_DESTRUCT, 2);
  AddExit("norte",Z_CIUDAD("calle_08"));
}
