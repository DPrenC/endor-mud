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
  "Est�s a las afueras del peque�o pueblo de Gaddaro que se halla al norte "
  "de aqu� en un camino que va desde �l hacia un cruce que observas al sur. "
  "Al oeste de aqu� hay un peque�o puerto en la orilla del lago Darum y "
  "m�s lejos al suroeste se divisa un puente para cruzar el r�o Daraii.\n");

#include "geografia.ic"
#include "ambiente.ic"

 AddExit("sur",AZ_CAMINO("camino11"));
 AddExit("oeste",GADDARO("puerto"));
 AddExit("norte",GADDARO("calle01"));
}
