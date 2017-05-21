/********************************************
*    Archivo: caparazon.c                   *
*    Localización: Cueva de los Trolls      *
*    Realizada por: Cajun, el ejecutor      *
*    Creado: 31-03-00                       *
*    Modificado:                            *
*********************************************/

#include "path.h"
#include <properties.h>
inherit THING;

create () {
  ::create();
  SetShort("Un caparazón enorme de shad");
  SetLong("Es la enorme cáscara que cubre el cuerpo de los shad. Es tan dura \
como el mejor acero y les da una protección prodigiosa frente a los ataques de los enemigos.\n");
  SetIds(({"caparazon","caparazón","cascara","cáscara"}));
  SetWeight(80000);
  SetValue(100);
}
