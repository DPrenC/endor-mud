/*
DESCRIPCION  : Calle de Gaddaro
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/gaddaro/calle00.c
MODIFICACION :
04-02-99 [Angor] Creacion
16-09-07 [Angor] Modificaciones
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
 SetIntShort("las afueras del pueblo de Gaddaro");
  SetIntLong(
  "Estás a las afueras del pequeño pueblo de Gaddaro que se halla al norte "
  "de aquí en un camino que va desde él hacia un cruce que observas al sur. "
  "Al oeste de aquí hay un pequeño puerto en la orilla del lago Darum y "
  "más lejos al suroeste se divisa un puente para cruzar el río Daraii.\n");

#include "geografia.ic"
#include "ambiente.ic"

 AddExit("sur",AZ_CAMINO("camino11"));
 AddExit("oeste",GADDARO("puerto"));
 AddExit("norte",GADDARO("calle01"));
}
