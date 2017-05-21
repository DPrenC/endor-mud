/***************************************************************************************
 ARCHIVO:	tunica.c
 AUTOR:		[z] Zomax
 FECHA:		30-12-2001
 COMENTARIOS:	La t�nica de los disc�pulos
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_TUNICA,2,P_SIZE_LARGE,M_TELA);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"tunica","t�nica"}));
  SetShort("una t�nica amarilla");
  SetLong(W("Es una t�nica amarilla con ribetes azules caracter�stica de los "
  	"disc�pulos del templo de Seri-Solderteg.\n"));
}
