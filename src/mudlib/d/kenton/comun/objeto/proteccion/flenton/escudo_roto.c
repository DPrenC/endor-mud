/***************************************************************************************
 ARCHIVO:	escudo_roto.c
 AUTOR:		[k] Korsario
 FECHA:		25-06-1998
 COMENTARIOS:	Un escudo roto
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
  SetLong("Es un escudo de cuero. Está bastante deteriorado y parece muy "
  	"antiguo. Ahora a penas si se observa, pero debía tener grabado un "
  	"precioso emblema.\n");
}
