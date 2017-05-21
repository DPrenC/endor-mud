/*
DESCRIPCION   : camisa de cuero
FICHERO       : camisa_cuero.c
CREACION      : 27-11-01 [Chaos]
MODIFICACION  :
*/

#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create() {
  ::create();
  SetStandard(AT_TUNICA,2,P_SIZE_MEDIUM,M_CUERO);
  SetIds(({"camisa","camisa de cuero"}));
  SetShort("una camisa de cuero");
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetLong(W("Es una camisa hecha por completo de cuero, bastante resistente y muy"+
  	    " flexible, ideal para las personas que viajan mucho.\n"));
 }
