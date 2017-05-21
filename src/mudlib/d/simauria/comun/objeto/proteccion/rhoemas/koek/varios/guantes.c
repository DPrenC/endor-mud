/***************************************************************************************
 ARCHIVO:	guantes.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Guantes de acero de la carnicera
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_GUANTES,3,P_SIZE_LARGE,M_ACERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetIds(({"guantes","guantes de acero"}));
  SetShort("unos guantes de acero");
  SetLong(W("Son los guantes de acero que usan los carniceros para no cortarse mientras "
  	"hacen lo propio con la carne.\n"));
}