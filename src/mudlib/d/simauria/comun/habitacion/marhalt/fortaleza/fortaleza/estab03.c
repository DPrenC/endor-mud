/*
DESCRIPCION  : establo
FICHERO      : estab03.c
MODIFICACION : 14-07-00 [Maler] Creacion
*/

#include "path.h"
inherit ROOMFF("fortalez");
create()
{
  ::create();
  SetIntShort("un establo");
  SetIntLong(W("Los inmensos establos del castillo debieron ser un espect�culo "
  "glorioso en su d�a. Ahora mismo es una estancia abandonada y llena de polvo. "
  "Da la impresi�n de que nunca haya habido caballos aqu�.\n"));
  AddExit("este",ROOMFF("patio03"));
  }
