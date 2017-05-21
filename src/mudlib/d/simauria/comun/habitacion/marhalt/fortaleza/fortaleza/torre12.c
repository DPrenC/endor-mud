/*
DESCRIPCION  : torre
FICHERO      : torre12.c
MODIFICACION : 16-07-00 [Maler] Creacion
*/

#include "path.h"
inherit ROOMFF("fortalez");
create()
{
  ::create();
  SetIntShort("una torre");
  SetIntLong(W("Estás en la tercera planta de una torre, en el castillo de Cored. Unas "
  "escaleras de caracol parten de este piso hacia abajo. A pesar de llevar mucho tiempo "
  "descuidada, la torre aguanta firmemente el paso del tiempo.\n"));
  AddExit("suroeste",ROOMFF("murall47"));
  AddExit("sudeste",ROOMFF("murall48"));
  AddExit("abajo",ROOMFF("torre08"));
  AnyadirPnjs();
  }
