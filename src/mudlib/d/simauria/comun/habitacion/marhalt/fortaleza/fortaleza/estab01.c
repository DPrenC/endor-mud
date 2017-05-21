/*
DESCRIPCION  : establo
FICHERO      : estab01.c
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
  AddItem(PNJFF("ladron"),REFRESH_DESTRUCT,3);
  AddItem(PNJFF("serg"),REFRESH_DESTRUCT);
  AddExit("este",ROOMFF("patio02"));
  }
