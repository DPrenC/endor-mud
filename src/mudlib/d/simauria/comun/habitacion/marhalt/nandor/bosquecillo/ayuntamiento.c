/*
DESCRIPCION  : Ayuntamiento
FICHERO      : ayuntamiento.c
CREACION     : 03-12-01 [Bomber]
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit SIM_ROOM;

create() {
  ::create();
  SetIntShort("el ayuntamiento");
  SetIntLong("Estás en el ayuntamiento de la aldea. Frente a ti se halla un mostrador.\n");

SetIntNoise("Esto esta bastante tranquilo. No oyes nada.\n");
SetIntSmell("Un fuerte olor a hierba fresca.\n");
SetLocate("???");
SetIndoors(1);

AddExit("oeste","plaza");
}