/***************************************************************************************
 ARCHIVO:	jubon.c
 AUTOR:		[k] Korsario
 FECHA:		25-06-1998
 COMENTARIOS:	Un jub�n
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
  SetIds(({"jubon","jub�n","jubon de cuero","jub�n de cuero"}));

  SetShort("un jub�n de cuero");
  SetLong("Es un jub�on de cuero. Tiene unos dibujos bordados en la parte "
  	"delantera con inspiraci�n en la caza. Es muy elegante y el cuero "
  	"parece de bastante calidad. Adem�s es muy ligero.\n");
}
