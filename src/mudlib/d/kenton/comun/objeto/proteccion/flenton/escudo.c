/***************************************************************************************
 ARCHIVO:	escudo.c
 AUTOR:		[k] Korsario
 FECHA:		25-06-1998
 COMENTARIOS:	Un escudo
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>

inherit ARMOUR;

create(){
  ::create();
  SetStandard(AT_ESCUDO,1,P_SIZE_SMALL,M_CUERO);
  Set(P_GENDER,GENERO_MASCULINO);
  Set(P_NUMBER,NUMERO_SINGULAR);
  SetIds(({"escudo"}));
  SetAds(({"de cuero"}));

  SetShort("un escudo de cuero");
  SetLong("Es un escudo de cuero. Tiene el flamante emblema de Flenton, "
  	"El Gran Árbol, grabado con mucha habilidad. Es muy bonito y ligero.\n");
}
