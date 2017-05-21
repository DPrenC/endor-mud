/*
DESCRIPCION  : torre
FICHERO      : torre03.c
MODIFICACION : 14-07-00 [Maler] Creacion
*/

#include "path.h"
inherit ROOMFF("fortalez");
create()
{
  ::create();
  SetIntShort("una torre");
  SetIntLong(W("Estás en la primera planta de una torre, en el castillo de Cored. Unas "
  "escaleras de caracol parten de este piso hacia arriba. A pesar de llevar mucho tiempo "
  "descuidada, la torre aguanta firmemente el paso del tiempo.\n"));
  AddExit("noroeste",ROOMFF("murall10"));
  AddExit("suroeste",ROOMFF("murall08"));
  AddExit("arriba",ROOMFF("torre07"));
  AnyadirPnjs();
  }
