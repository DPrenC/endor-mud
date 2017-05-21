/*
DESCRIPCION  : torre
FICHERO      : torre06.c
MODIFICACION : 14-07-00 [Maler] Creacion
*/

#include "path.h"
inherit ROOMFF("fortalez");
create()
{
  ::create();
  SetIntShort("una torre");
  SetIntLong(W("Estás en la segunda planta de una torre, en el castillo de Cored. Unas "
  "escaleras de caracol parten de este piso hacia arriba y hacia abajo. A pesar de llevar mucho tiempo "
  "descuidada, la torre aguanta firmemente el paso del tiempo.\n"));
  AddExit("sudeste",ROOMFF("murall23"));
  AddExit("nordeste",ROOMFF("murall25"));
  AddExit("arriba",ROOMFF("torre10"));
  AddExit("abajo",ROOMFF("torre02"));
  AnyadirPnjs();
  }
