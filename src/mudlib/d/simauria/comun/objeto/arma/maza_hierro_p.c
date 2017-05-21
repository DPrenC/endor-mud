/*
DESCRIPCION  : MAza de hierro de crowy. Version pequeña de la maza de Woo
FICHERO      : maza_hierro_p.c
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
 if (!clonep(TO)) return;
 ::create();
 SetStandard(WT_MAZA,10,P_SIZE_SMALL,M_HIERRO);
  SetWeight(QueryWeight()*2);//Doblo peso
  SetValue(QueryValue()*4);//Cuadruplico valor
 SetShort("una maza de hierro");
 SetIds(({"maza","maza de hierro"}));
 Set(P_GENDER,GENERO_FEMENINO);
 Set(P_NUMBER,NUMERO_SINGULAR);
 SetNumberHands(2);
 SetLong("\
Es una pequeña maza fabricada de hierro y que atemoriza a los enemigos solo\n\
de verla.\n");
}
