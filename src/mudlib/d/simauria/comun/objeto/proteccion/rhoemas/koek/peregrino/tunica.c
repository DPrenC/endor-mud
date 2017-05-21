/***************************************************************************************
 ARCHIVO:	tunica.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	La t�nica de los peregrinos
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_TUNICA,1,P_SIZE_LARGE,M_TELA);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"tunica","t�nica"}));
  SetShort("una t�nica gris");
  SetLong(W("Es una t�nica gris hecha de una tela especial que calienta el cuerpo "
  	"en las fr�as noches a la intemperie. Parece que es muy popular entre los "
  	"peregrinos por su gran utilidad.\n"));
}