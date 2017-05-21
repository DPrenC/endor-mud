/***************************************************************************************
 ARCHIVO:	tunica.c
 AUTOR:		[z] Zomax
 FECHA:		23-04-2003
 COMENTARIOS:	Una t�nica.
 ***************************************************************************************/

#include "path.h"
#include <moving.h>
#include <materials.h>
#include <properties.h>
#include <combat.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_TUNICA,1,P_SIZE_MEDIUM,M_TELA);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"tunica","t�nica","tunica ceremonial","t�nica ceremonial","t�nica p�rpura"}));
  SetShort("una t�nica ceremonial p�rpura");
  SetLong(W("Es una preciosa t�nica de color p�rpura intenso con bordados en los pu�os y un bonito "
  	"escudo en el pecho.\n"));
}
