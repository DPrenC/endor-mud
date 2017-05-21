/***************************************************************************************
 ARCHIVO:	hacha.c
 AUTOR:		[z] Zomax
 FECHA:		20-12-2001
 COMENTARIOS:	Hacha del herrero
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();

  SetStandard(WT_HACHA,9,P_SIZE_MEDIUM,M_HIERRO);
  SetNumberHands(2);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"hacha"}));
  SetShort("un hacha");
  SetLong(W("Esta es un hacha muy especial, con el mango lleno de hendiduras para "
  	"poder agarrarla mejor y un filo tan extraño como afilado. Tiene grabada "
  	"en la hoja un símbolo distintivo de Kolen, su forjador.\n"));
  AddSubDetail(({"símbolo","simbolo","distintivo","marca"}),"Es la marca de su creador: Kolen el herrero.\n");
  AddSubDetail(({"mango","hendidura","hendiduras"}),W("El mango es ideal para el manejo "
  	"seguro del arma. Incorpora unas hendiduras donde se colocan las manos.\n"));
}
