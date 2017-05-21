/***************************************************************************************
 ARCHIVO:	botas.c
 AUTOR:		[k] Korsario
 FECHA:		25-06-1998
 COMENTARIOS:	Unas botas
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();
  SetStandard(AT_BOTAS,1,P_SIZE_SMALL,M_CUERO);
  Set(P_GENDER,GENERO_FEMENINO);
  Set(P_NUMBER,NUMERO_PLURAL);
  SetIds(({"botas"}));
  SetAds(({"unas","de cuero"}));

  SetShort("unas botas de cuero");
  SetLong("Son unas botas de cuero de la mejor calidad. Parecen pequeñas "
  	"y tienes la ligera impresión de que no se ajustarian a cualquier pie, "
  	"sólo al de un kender o algo por el estilo.\n");
}
