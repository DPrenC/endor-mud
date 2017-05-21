/*
DESCRIPCION  : CAPILLA
FICHERO      : capilla.c
MODIFICACION : 16-07-00 [Maler] Creacion
*/

#include "path.h"
inherit ROOMFF("fortalez");
create()
{
    ::create();
    SetIntShort("una capilla");
    SetIntLong("Esta es la capilla de la fortaleza. Aquí los caballeros velaban sus "
    "armas y armaduras, antes de jurar lealtad a su señor en la torre del homenaje.\n "
    " En este momento esta completamente en desuso.\n");
    AddDetail("altar","El altar se mantiene en perfecto estado a pesar del tiempo.\nTiene una extraña marca dibujada.\n");
    SetIndoors(1);
    AddExit("oeste",ROOMFF("patio06"));
    AddDoor("oeste", "una puerta", "Es una sencilla puerta de madera sin nada de particular.\n",
        ({"puerta", "puerta de madera", "puerta sencilla"}));
  }