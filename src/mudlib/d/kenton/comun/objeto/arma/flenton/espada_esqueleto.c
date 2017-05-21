/***************************************************************************************
 ARCHIVO:	espada_esqueleto.c
 AUTOR:		[z] Zomax
 FECHA:		25-01-2002
 COMENTARIOS:	La espada de un esqueleto guerrero.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();
  SetStandard(WT_ESPADA,5,P_SIZE_MEDIUM,M_ACERO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetNumberHands(1);
  SetIds(({"espada","vieja"}));

  SetShort("una espada vieja");
  SetLong("Es una espada muy vieja que perteneció a un gran guerrero.\n");
}
