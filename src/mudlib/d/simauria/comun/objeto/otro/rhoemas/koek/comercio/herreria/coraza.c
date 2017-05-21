/***************************************************************************************
 ARCHIVO:	coraza.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Una coraza
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_CORAZA,12,P_SIZE_MEDIUM,M_ACERO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"coraza"}));
  SetShort("una coraza");
  SetLong("Es una resistente coraza de acero con grabados.\n");
  AddSubDetail(({"grabado","grabados"}),W("La coraza tiene unos grabados a la altura "
  	"de los hombros que hacen a su portador más aterrador ante sus enemigos.\n"));
}