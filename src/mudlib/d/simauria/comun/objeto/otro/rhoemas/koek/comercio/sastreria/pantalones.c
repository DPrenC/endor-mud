/***************************************************************************************
 ARCHIVO:	pantalones.c
 AUTOR:		[z] Zomax
 FECHA:		23-04-2003
 COMENTARIOS:	Unos pantalones marrones.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_PANTALONES,2,P_SIZE_MEDIUM,M_TELA);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetIds(({"pantalones"}));
  SetShort("unos pantalones marrones");
  SetLong(W("Son unos pantalones de tela marrón ideales para el trabajo diario. Parecen "
  	"cómodos y fáciles de lavar.\n"));
}