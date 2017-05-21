/*
DESCRIPCION    : estatuilla del dios Dehim que se usa para el Quest
FICHERO        : ......../tiindhil/comun/objeto/otro/estatui.c
CREACION       : Abril 99[Alura].
U.MODIFICACION : Junio 2001 [Alura]
*/



#include <properties.h>
#include "path.h"

inherit THING;

create() {
  ::create();
  SetValue(0);
  SetWeight(5000);
  Set("llevamedal",0);
  SetMaterial("porcelana");
  SetIds(({"estatuilla","figurilla","estatua"}));
  SetShort("una pequeña estatuilla");
  SetLong((:"Es la delicada figura de un hombre cubierto por enredaderas. "
  	        "Con una beatífica expresión, sus brazos parece que indiquen "
  	        "algo al cielo. Mide alrededor de un metro" + (!Query("llevamedal") ?
  	        " y en su cuello ves las marcas de algo que ya no lleva" :
  	        " y en su cuello ves un pequeño medallón con una réplica en miniatura "
  	        "de la propia estatuilla""") + ".\n":));
  AddSubDetail("brazos","El brazo izquierdo toca su corazón y el derecho "
  	      "se alza hacia el cielo.\n");
}
