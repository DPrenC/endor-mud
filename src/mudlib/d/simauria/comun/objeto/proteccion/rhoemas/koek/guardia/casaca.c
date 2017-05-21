/***************************************************************************************
 ARCHIVO:	casaca.c
 AUTOR:		[z] Zomax
 FECHA:		30-11-2001
 COMENTARIOS:	Casaca de la Guardia de Koek
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();

  SetStandard(AT_TABARDO,2,P_SIZE_LARGE,M_TELA);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"casaca","casaca roja"}));
  SetShort("una casaca roja");
  SetLong(W("Es una casaca de gala de las que utiliza la guardia de Koek. Es de color "
  "rojo con el escudo del pueblo bordado a la altura del corazón con hilo dorado. En los "
  "laterales tiene unas bandas también bordadas en oro y unos bonitos gemelos en los puños.\n"));
  AddSubDetail(({"escudo","escudo bordado"}),W("Un precioso escudo significativo de la "
  	"guardia de Koek bordado en hilo de oro.\n"));
  AddSubDetail(({"bandas","bandas bordadas"}),W("Parecen las bandas que muestran la graduación "
  	"del guardia.\n"));
  AddSubDetail(({"gemelo","gemelos"}),W("En los puños tiene cosidos un par de gemelos parecen "
  	"ser de oro.\n"));
}