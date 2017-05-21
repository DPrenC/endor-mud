/***************************************************************************************
 ARCHIVO:	navaja.c
 AUTOR:		[z] Zomax
 FECHA:		14-01-2002
 COMENTARIOS:	Una navaja para arreglar redes
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_CUCHILLO,1,P_SIZE_MEDIUM,M_HIERRO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"navaja"}));
  SetShort("una navaja");
  SetLong("Es una pequeña navaja muy util para los pescadores y sus redes.\n");
}