#include "path.h"
#include <nightday.h>

inherit DOM_STD+"tienda";

create()
{
  ::create();
  SetIntLong(W("Estás en una tienda de ropa. La cabaña es espaciosa "
	"por lo que hay bastante sitio para colocar los estantes donde "
	"se almacena el género. Puedes ver un poco de todo, desde guantes "
	"del piel a botas de cuero, pasando por capas y demás objetos "
	"más o menos útiles que pueden pasar a formar parte de tu "
	"indumentaria.\n"));
  SetIntShort("una tienda de ropa");
  SetLocate("la ciudad de Atbalnin");
  SetIntNoise("El murmullo de la ciudad es aquí un poco más tenue.\n");
  SetIntSmell("Huele a ropa.\n");
  AddDetail(({"estantería", "estanteria", "estanterías", "estanterias",
  	"estante", "estantes"}), W("En los estantes es donde está toda "
  	"la mercancía en venta.\n"));
  SetShopkeeper(PNJ("atbalnin/ciudad/asuen"));

  AddArticle(PROT("botas"), REFRESH_REMOVE, 3);
  AddArticle(PROT("tunica"), REFRESH_REMOVE, 3);
  AddArticle(PROT("pantalones"), REFRESH_REMOVE, 3);
  AddArticle(PROT("coraza"), REFRESH_REMOVE, 2);
  AddArticle(PROT("guantes"), REFRESH_REMOVE, 2);
  AddArticle(PROT("coraza-piel"), REFRESH_REMOVE, 3);
  AddArticle(PROT("guantes-piel"), REFRESH_REMOVE, 3);
  AddArticle(PROT("pantalones-piel"), REFRESH_REMOVE, 3);
  AddArticle("/obj/mochila", REFRESH_REMOVE, 2);
  AddArticle("/obj/vial", REFRESH_REMOVE, 4);
  AddArticle("/obj/vialv", REFRESH_REMOVE, 8);
  AddArticle("/obj/vialm", REFRESH_REMOVE, 8);

  AddExit("salir", ATB_CI("ciudad15"));
}


