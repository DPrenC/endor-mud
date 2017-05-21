/***************************************************************************************
 ARCHIVO:	hilos.c
 AUTOR:		[z] Zomax
 FECHA:		09-04-2003
 COMENTARIOS:	Unos hilos de paja.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("unos hilos de paja");
  SetLong("Son unos finos hilos de paja seca y dorada.\n");
  SetIds(({"paja","hilos","hilos de paja"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  Set(P_SIZE,P_SIZE_SMALL);
  SetWeight(5);
  SetValue(0);
}
