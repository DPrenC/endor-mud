/*
DESCRIPCION  : torre
FICHERO      : torre08.c
MODIFICACION : 16-07-00 [Maler] Creacion
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
  AddExit("sudeste",ROOMFF("murall32"));
  AddExit("suroeste",ROOMFF("murall31"));
  AddExit("arriba",ROOMFF("torre12"));
  AddExit("abajo",ROOMFF("torre04"));
  AnyadirPnjs();
  }
