/***************************************************************************************
 ARCHIVO:	baculo.c
 AUTOR:		[z] Zomax
 FECHA:		29-12-2001
 COMENTARIOS:	El b�culo del adalid
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();
  SetStandard(WT_VARA,5,P_SIZE_MEDIUM,M_MADERA);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  Set(P_CANT_STEAL,1);
  SetIds(({"b�culo","baculo"}));
  SetShort("un b�culo");
  SetLong(W("Es un b�culo largo de madera con una peque�a bola de cristal negro en "
  	"la punta. Parece que es algo m�s que un palo, pero sin duda el �nico que sabe "
  	"usarlo es su due�o.\n"));
  AddSubDetail(({"bola","bola de cristal","bola de cristal negro"}),W("Es muy "
  	"extra�a. Parece que est� vacia pero jurar�as que de vez en cuando se "
  	"ilumina y algo se mueve en su interior.\n"));
}
