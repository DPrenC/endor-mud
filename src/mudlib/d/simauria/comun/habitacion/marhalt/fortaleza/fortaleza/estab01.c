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
  SetIntLong(W("Los inmensos establos del castillo debieron ser un espectáculo "
  "glorioso en su día. Ahora mismo es una estancia abandonada y llena de polvo. "
  "Da la impresión de que nunca haya habido caballos aquí.\n"));
  AddItem(PNJFF("ladron"),REFRESH_DESTRUCT,3);
  AddItem(PNJFF("serg"),REFRESH_DESTRUCT);
  AddExit("este",ROOMFF("patio02"));
  }
