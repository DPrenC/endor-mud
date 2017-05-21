/*
DESCRIPCION  : muralla
FICHERO      : murall45.c
MODIFICACION : 16-07-00 [Maler] Creacion
*/

#include "path.h"
inherit ROOMFF("fortalez");
create()
{
  ::create();
  SetIntShort("la muralla");
  SetIntLong(W("Est�s en la tercera planta de la muralla. Caminas sobre la muralla, observando el "
  "bosque a tu alrededor. En este nivel, las murallas estan almenadas para proteger a los defensores "
  "del castillo de los ataques exteriores.\n"));
  AddExit("suroeste",ROOMFF("murall43"));
  AddExit("nordeste",ROOMFF("murall47"));
  AnyadirPnjs();
  }