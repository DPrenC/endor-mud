/* fichero: estilete.c */


#include <combat.h>
#include <properties.h>

inherit WEAPON;


create(){
  ::create();

  SetStandard(WT_DAGA,3,P_SIZE_GENERIC,M_ACERO);
  AddAdjective("pequeñO");
  SetIds(({"estilete","daga","AHUSADA"}));
  SetAds(({"afilada","larga"}));

  SetShort("un estilete");
  SetLong("Una daga fina y larga. Tiene una hoja estrecha muy afilada, con\n"
  	"una empuñadura de madera. Es un arma ligera y muy manejable.\n");
}
