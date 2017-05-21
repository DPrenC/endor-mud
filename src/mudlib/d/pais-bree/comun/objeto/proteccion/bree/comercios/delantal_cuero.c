/***************************************************************************************
 ARCHIVO:	delantal_cuero.c
 AUTOR:		aule
 FECHA:		30/01/2015
 COMENTARIOS:	un delantal de cuero para proteger al herrero
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_TABARDO,2,P_SIZE_LARGE,M_CUERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"delantal"}));
  SetShort("un delantal de cuero");
  SetLong(
  "Se trata de una prenda de cuero grueso que se sujeta al cuello y a la cintura por "
  "cordones de cuero trenzado. Lo forman varias capas y protege a su portador del calor "
  "del fuego. Está algo ajado por el uso.\n");
  SetWeight(450);
  }