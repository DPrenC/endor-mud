/***************************************************************************************
 ARCHIVO:	guantes_gruesos.c
 AUTOR:		Aule
 FECHA:		30/01/2014
 COMENTARIOS:	guantes para el herrero
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_GUANTES,2,P_SIZE_LARGE,M_CUERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetIds(({"guantes","guantes de cuero"}));
  SetShort("unos gruesos guantes de cuero");
  SetLong(
  "Son unos guantes muy gruesos con varias capas de cuero cosidas unas sobre otras.\n"
  "Ofrecen gran protección contra el fuego y no tienen ninguna parte metálica.\n");
  SetWeight(300);
  }