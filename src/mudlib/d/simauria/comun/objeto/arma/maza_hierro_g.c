/*
DESCRIPCION  : MAza de hierro de crowy. Version grande de la maza de Woo
FICHERO      : maza_hierro_g.c
CREACION     : 10-11-01 [Bomber]
MODIFICACION : 07-03-03 [ChS] Cambio las propiedades para el numero de manos
			con las que se puede usar esta maza, al ser para gente
			enorme, ahora si eres tamaño 2 necesitas fuerza 30 para
			usarla a una mano
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
 	SetStandard(WT_MAZA,10,P_SIZE_LARGE,M_HIERRO);
	SetWeight(QueryWeight()*2);//Doblo peso
	SetValue(QueryValue()*2);//Doblo el valor
	SetShort("una maza de hierro");
	SetIds(({"maza","maza de hierro"}));
	Set(P_GENDER,GENERO_FEMENINO);
	Set(P_NUMBER,NUMERO_SINGULAR);
	SetNumberHands(2);
	SetLong("Es una enorme maza fabricada de hierro y que atemoriza a"
	 		" los enemigos solo de verla.\n");
}
