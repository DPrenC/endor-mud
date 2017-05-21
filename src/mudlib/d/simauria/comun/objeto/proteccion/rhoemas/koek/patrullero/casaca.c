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

  SetStandard(AT_TABARDO,1,P_SIZE_LARGE,M_TELA);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"casaca","casaca azul","casaca azul"}));
  SetShort("una casaca azul");
  SetLong(W("Es una casaca azul oscura con bordados en plata parecida en el diseño a las "
  "que utilizan los guardias de gala, pero no de tan buena calidad como esas, sin embargo "
  "esta no se queda atrás. Tiene un bordado a la altura del corazón y unos bonitos gemelos "
  "en los puños.\n"));
  AddSubDetail(({"escudo","escudo bordado"}),W("Un precioso escudo significativo de los "
  	"patrulleros de Koek bordado en hilo de plata.\n"));
  AddSubDetail(({"bandas","bandas bordadas"}),W("Parecen las bandas que muestran la graduación "
  	"del patrullero.\n"));
  AddSubDetail(({"gemelo","gemelos"}),W("En los puños tiene cosidos un par de gemelos parecen "
  	"ser de plata.\n"));
}