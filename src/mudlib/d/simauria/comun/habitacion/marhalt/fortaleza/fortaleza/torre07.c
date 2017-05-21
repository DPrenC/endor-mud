/*
DESCRIPCION  : torre
FICHERO      : torre07.c
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
  AddExit("noroeste",ROOMFF("murall26"));
  AddExit("suroeste",ROOMFF("murall24"));
  AddExit("arriba",ROOMFF("torre11"));
  AddExit("abajo",ROOMFF("torre03"));
  AnyadirPnjs();
  }
