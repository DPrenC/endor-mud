/********************************************
*    Archivo: caparazon.c                   *
*    Localizaci�n: Cueva de los Trolls      *
*    Realizada por: Cajun, el ejecutor      *
*    Creado: 31-03-00                       *
*    Modificado:                            *
*********************************************/

#include "path.h"
#include <properties.h>
inherit THING;

create () {
  ::create();
  SetShort("Un caparaz�n enorme de shad");
  SetLong("Es la enorme c�scara que cubre el cuerpo de los shad. Es tan dura \
como el mejor acero y les da una protecci�n prodigiosa frente a los ataques de los enemigos.\n");
  SetIds(({"caparazon","caparaz�n","cascara","c�scara"}));
  SetWeight(80000);
  SetValue(100);
}
