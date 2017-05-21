/*
DESCRIPCION   : camisa de cuero grande
FICHERO       : camisa_cuero_g.c
CREACION      : 10-11-01 [Bomber]
MODIFICACION  :
*/

#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>


inherit ARMOUR;

create() {
  ::create();
  SetStandard(AT_TUNICA,2,P_SIZE_LARGE,M_CUERO);
  SetIds(({"camisa","camisa de cuero"}));
  SetShort("una camisa de cuero");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetLong(
"Es una camisa hecha por completo de cuero, bastante resistente y muy\n\
flexible, ideal para las personas que viajan mucho.\n");
  SetWeight(QueryWeight()*2); // Doblo peso
  SetValue(QueryValue()*4); // Cuadruplico Valor

}
