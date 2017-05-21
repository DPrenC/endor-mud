/***************************************************************************************
 ARCHIVO:	sedal.c
 AUTOR:		[z] Zomax
 FECHA:		07-01-2002
 COMENTARIOS:	Sedal
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit THING;

create () {
 ::create();

  SetShort("un carrete de hilo");
  SetLong(W("Es un largo carrete de hilo muy resistente para reparar la caña de pescar "
  	"cuando se rompe el sedal.\n"));
  SetIds(({"sedal","carrete de hilo","carrete"}));
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_SIZE,P_SIZE_GENERIC);
  SetWeight(20);
  SetValue(250);
}
