/*
DESCRIPCION  : Mangual to enano
FICHERO      : mangual_p.c
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
 SetStandard(WT_MANGUAL, 5, P_SIZE_SMALL, M_HIERRO);
 SetShort("Un mangual pequeño");
 SetLong(W("Es una mangual de combate pequeño. Está formado por una gran bola "
           "metálica con pinchos unida a un mango de madera por una pesada "
  	     "cadena de metal.\n"));
 SetIds(({"mangual","mangual pequeño"}));
  SetWeight(QueryWeight()*2);//Doblo peso
  SetValue(QueryValue()*4);//Cuadruplico valor

}