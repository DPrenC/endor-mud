/***************************************************************************************
 ARCHIVO:	daga.c
 AUTOR:		[z] Zomax
 FECHA:		20-12-2001
 COMENTARIOS:	Daga del herrero
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_CUCHILLO,3,P_SIZE_MEDIUM,M_HIERRO);
  SetNumberHands(1);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"daga"}));
  SetShort("una daga");
  SetLong(W("Es una daga muy normal, lo que no quita que esté muy muy afilada. "
  	"Según una inscripción que tiene está forjada por Kolen, el famoso "
  	"herrero.\n"));
  AddSubDetail(({"inscripción","inscripcion","marca"}),W("Es la marca de su "
  	"creador: Kolen el herrero.\n"));
}
