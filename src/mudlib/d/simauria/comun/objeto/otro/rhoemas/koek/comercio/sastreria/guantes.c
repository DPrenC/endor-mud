/***************************************************************************************
 ARCHIVO:	guantes.c
 AUTOR:		[z] Zomax
 FECHA:		23-04-2003
 COMENTARIOS:	Unos guantes de piel.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_GUANTES,1,P_SIZE_MEDIUM,M_PIEL);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetIds(({"guantes"}));
  SetShort("unos guantes de piel");
  SetLong(W("Son unos guantes de piel marrón muy flexibles y bastante resistentes. "
  	"Tienen las costuras en forma de equis a lo largo de la muñeca en un hilo "
  	"marrón algo más oscuro que la piel del resto del guante y un bonito "
  	"grabado a fuego en la parte superior.\n"));
  AddSubDetail(({"grabado","grabado a fuego"}),W("Parece que es el escudo del "
  	"que cosió los guantes, pero no deja de ser bonito.\n"));
}