#include "path.h"
#include <nightday.h>

inherit DOM_STD+"tienda";

create()
{
  ::create();
  SetIntLong(W("Obviamente estás en una tienda de armas, dedicada sobre todo "
  	"a armas de filo, aunque también ves alguna alabarda y algún mazo.\n"));
  	
  SetIntShort("la tienda de armas");

  AddDetail(({"estantería", "estanteria", "estanterías", "estanterias",
  	"estante", "estantes"}), W("En los estantes es donde está toda "
  	"la mercancía en venta.\n"));
  	
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


