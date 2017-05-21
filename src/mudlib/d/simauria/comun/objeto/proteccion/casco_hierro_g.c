/*
DESCRIPCION   : casco de hierro grande
FICHERO       : casco_hierro_g.c
CREACION      : 10-11-01 [Bomber]
MODIFICACION  :
*/


#include <combat.h>
#include <properties.h>
#include "path.h"

inherit ARMOUR;

create()
{
 ::create();
 SetStandard(AT_HELMET,2,P_SIZE_LARGE,M_HIERRO);
  SetWeight(QueryWeight()*2); // Doblo peso
  SetValue(QueryValue()*4); // Cuadruplico Valor
 SetShort("un casco de hierro");
 SetIds(({"casco","casco de hierro"}));
 Set(P_GENDER,GENERO_MASCULINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetLong("\
Es un casco bastante sucio de hierro.\n");
}

