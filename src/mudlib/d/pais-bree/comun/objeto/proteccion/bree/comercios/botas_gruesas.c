/***************************************************************************************
 ARCHIVO:	botas_gruesas.c
 AUTOR:		aule
 FECHA:		30/01/2015
 COMENTARIOS:	Botas de Weltford el herrero de Bree
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_BOTAS,2,P_SIZE_LARGE,M_CUERO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetIds(({"botas","botas gruesas"}));
  SetShort("unas fuertes botas de cuero");
  SetLong(
  "Son unas botas de varias capas de cuero endurecido pero flexible con suela gruesa "
  "que llegan hasta la altura de la rodilla y no tienen cordones, ajustándose al pie y "
  "la pantorrilla por medio de unas correas del mismo material.\n");
  SetWeight(1200);
  }