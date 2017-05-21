/***************************************************************************************
 ARCHIVO:	jubon.c
 AUTOR:		[k] Korsario
 FECHA:		25-06-1998
 COMENTARIOS:	Un jubón
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();
  SetStandard(AT_TUNICA,1,P_SIZE_SMALL,M_CUERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"jubon","jubón","jubon de cuero","jubón de cuero"}));

  SetShort("un jubón de cuero");
  SetLong("Es un jubóon de cuero. Tiene unos dibujos bordados en la parte "
  	"delantera con inspiración en la caza. Es muy elegante y el cuero "
  	"parece de bastante calidad. Además es muy ligero.\n");
}
