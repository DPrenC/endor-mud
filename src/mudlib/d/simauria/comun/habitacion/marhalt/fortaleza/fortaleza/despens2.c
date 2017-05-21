/*
DESCRIPCION  : despensa
FICHERO      : despens2.c
MODIFICACION : 16-07-00 [Maler] Creacion
*/

#include "path.h"
inherit ROOMFF("fortalez");
create()
{
  ::create();
  SetIntShort("una despensa");
  SetIntLong(W("Es una despensa propiedad de Tamara, la mujer que regenta la tienda. "
  "Hay un montón de embalajes y paquetes desperdigados por el suelo, o apilades en "
  "grandes montones.\n"));
  AddDetail(({"paquetes","embalajes"}),W("Son un montón de paquetes sin identificar "
  "algo te dice que no debes abrirlos.\n"));
  SetIndoors(1);
  SetIntBright(30);
  AddExit("norte",ROOMFF("patio16"));
  }
