/***************************************************************************************
 ARCHIVO:	panyales.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Unos pañales
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_PANTALONES,1,P_SIZE_MEDIUM,M_TELA);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetIds(({"pañales","panyales"}));
  SetShort("unos pañales");
  SetLong("Son unos pañales blancos para los bebés. Parece que están usados.\n");
  SetSmell(W("Huelen a rayos. A saber qué comía el niño que los llevaba para que huelan "
  	"así de mal.\n"));
}