#include "path.h"
#include <colours.h>

inherit DOM_STD+"herreria";


create()
{
  ::create();
 SetIntLong(W("Esta es la caba�a de Arlin el Manitas. Arregla pr�cticamente "
  	"cualquier cosa, desde armas y armaduras hasta desvencijados "
  	"mobiliarios, siempre que no sean m�gicos, por supuesto.\n"));

  SetIntShort("la tienda de Arlin");
  SetIntNoise("El murmullo de la ciudad es aqu� un poco m�s tenue.\n");

  SetShopkeeper(PNJ("atbalnin/ciudad/arlin"));
  SetNoShop(1);
  SetSell(0);
  SetBuy(0);
  SetAppraise(0);
  SetSmithy(0);

  AddExit("salir", ATB_CI("ciudad12"));
}


