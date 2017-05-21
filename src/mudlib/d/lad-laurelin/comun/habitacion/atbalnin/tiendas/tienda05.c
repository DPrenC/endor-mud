#include "path.h"
#include <nightday.h>

inherit DOM_STD+"tienda";

create()
{
  ::create();
  SetIntLong(W("Obviamente est�s en una tienda de armas, dedicada sobre todo "
  	"a armas de filo, aunque tambi�n ves alguna alabarda y alg�n mazo.\n"));
  	
  SetIntShort("la tienda de armas");

  AddDetail(({"estanter�a", "estanteria", "estanter�as", "estanterias",
  	"estante", "estantes"}), W("En los estantes es donde est� toda "
  	"la mercanc�a en venta.\n"));
  	
  SetShopkeeper(PNJ("atbalnin/ciudad/taffed"));

  AddArticle(ARMA("espada-2manos"), REFRESH_REMOVE, 2);
  AddArticle(ARMA("espada-corta"), REFRESH_REMOVE, 3);
  AddArticle(ARMA("espada-larga"), REFRESH_REMOVE, 3);
  AddArticle(ARMA("martillo"), REFRESH_REMOVE, 3);
  AddArticle(ARMA("espada-2manos-acero"), REFRESH_REMOVE, 2);
  AddArticle(ARMA("espada-corta-acero"), REFRESH_REMOVE, 3);
  AddArticle(ARMA("espada-acero"), REFRESH_REMOVE, 3);

  AddExit("salir", ATB_CI("ciudad40"));
}


