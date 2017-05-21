/***************************************************************************************
 ARCHIVO:	cuchillo.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	El cuchillo de la carnicera
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_CUCHILLO,2,P_SIZE_MEDIUM,M_HIERRO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"cuchillo"}));
  SetShort("un cuchillo");
  SetLong("Es un cuchillo de carnicero, muy afilado pero poco manejable.\n");
}