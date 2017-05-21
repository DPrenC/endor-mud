/***************************************************************************************
 ARCHIVO:	panyales.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Unos pa�ales
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
  SetIds(({"pa�ales","panyales"}));
  SetShort("unos pa�ales");
  SetLong("Son unos pa�ales blancos para los beb�s. Parece que est�n usados.\n");
  SetSmell(W("Huelen a rayos. A saber qu� com�a el ni�o que los llevaba para que huelan "
  	"as� de mal.\n"));
}