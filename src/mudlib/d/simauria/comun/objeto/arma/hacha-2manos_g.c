/*
DESCRIPCION  : Hacha de guerra a 2 manos de Theuzifan. Version Grande.
FICHERO      : hacha-2manos_g.c
CREACION     : 10-11-01 [Bomber]
MODIFICACION :
*/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create()
{
  ::create();
 SetStandard(WT_HACHA, 10, P_SIZE_LARGE, M_HIERRO);
  SetShort("un hacha de guerra");
  SetLong(W("Es una hacha de guerra de dos manos. La pesada cabeza de dos "
  	"hojas está sujeta a un largo mango metálico.\n"));
  SetIds(({"hacha", "hacha de guerra"}));
  Set(P_GENDER, GENDER_FEMALE);
  Set(P_NUMBER_HANDS, 2);
  SetWeight(QueryWeight()*2);//Doblo peso
  SetValue(QueryValue()*4);//Cuadruplico valor
}