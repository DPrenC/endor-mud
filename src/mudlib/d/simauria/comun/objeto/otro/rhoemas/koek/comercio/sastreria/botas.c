/***************************************************************************************
 ARCHIVO:	botas.c
 AUTOR:		[z] Zomax
 FECHA:		23-04-2003
 COMENTARIOS:	Unas botas de cuero negro.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_BOTAS,2,P_SIZE_MEDIUM,M_CUERO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetIds(({"botas"}));
  SetShort("unas botas de cuero");
  SetLong(W("Son unas botas de cuero negro altas y bastante flexibles. La punta es "
  	"algo redondeada y parecen bastante c�modas para las largas caminatas. "
  	"La suela parece de alg�n tipo de piel impermeable de un color "
  	"oscurro pero sin llegar a ser negro y las costuras est�n hechas con hilo "
  	"beige.\n"));
  AddSubDetail(({"costuras"}),"El que lo cosi� sab�a lo que hac�a, son muy buenas.\n");
}