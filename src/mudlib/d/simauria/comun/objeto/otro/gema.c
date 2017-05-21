/********************************************
*    Archivo: gema.c                        *
*    Localizaci�n: Cueva de los Trolls      *
*    Realizada por: Cajun, el ejecutor      *
*    Creado: 08-02-00                       *
*    Modificado:                            *
*********************************************/

#include "path.h"
#include <properties.h>
inherit THING;

create () {
  ::create();
  SetShort("Extra�a gema ambar");
  SetLong(
    "Es una rara gema de color ambar. Es bastante brillante y atractiva, \
aunque no crees que tenga mucha utilidad tal vez podr�a valer algo.\n");
SetIds(({"gema","ambar","spell_bola_ereldil"}));
  SetWeight(100);
  SetValue(10000);
}
