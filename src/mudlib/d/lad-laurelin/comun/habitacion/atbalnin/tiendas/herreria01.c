#include "path.h"
#include <colours.h>

inherit DOM_STD+"herreria";


create()
{
  ::create();
 SetIntLong(W("Esta es la cabaña de Arlin el Manitas. Arregla prácticamente "
  	"cualquier cosa, desde armas y armaduras hasta desvencijados "
  	"mobiliarios, siempre que no sean mágicos, por supuesto.\n"));

  SetIntShort("la tienda de Arlin");
  SetIntNoise("El murmullo de la ciudad es aquí un poco más tenue.\n");

  SetShopkeeper(PNJ("atbalnin/ciudad/arlin"));
  SetNoShop(1);
  SetSell(0);
  SetBuy(0);
  SetAppraise(0);
  SetSmithy(0);

  AddExit("salir", ATB_CI("ciudad12"));
}


