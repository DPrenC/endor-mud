/***************************************************************************************
 ARCHIVO:	vara.c
 AUTOR:		[z] Zomax
 FECHA:		19-12-2001
 COMENTARIOS:	Una vara de madera
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit WEAPON;

create(){
  ::create();
  SetStandard(WT_VARA,6,P_SIZE_GENERIC,M_MADERA);
  SetNumberHands(2);
  Set(P_WP_PER_QP,20);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"vara","vara tallada"}));
  SetShort("una vara tallada");
  SetLong(W("Es una vara tallada con gran maestría de una sola pieza de roble "
  	"de Koek, una de las variedades más duras y resistentes de madera que "
  	"se conocen. Tiene también talladas las hendiduras de las manos que "
  	"la empuñan en un lugar estratégico que proporciona un mayor control "
  	"del golpe. Parece estudiada al milímetro.\n"));
  AddSubDetail(({"hendidura","hendiduras"}),W("Parece que tiene tallada la "
  	"posición mas idónea donde tiene que estar la mano para manejar bien "
  	"la vara.\n"));
}
