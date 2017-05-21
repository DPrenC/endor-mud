#include "path.h"
#include <nightday.h>

inherit DOM_STD+"tienda";

create()
{
  ::create();
  SetIntLong(W("Est�s en una tienda de ropa. La caba�a es espaciosa "
	"por lo que hay bastante sitio para colocar los estantes donde "
	"se almacena el g�nero. Puedes ver un poco de todo, desde guantes "
	"del piel a botas de cuero, pasando por capas y dem�s objetos "
	"m�s o menos �tiles que pueden pasar a formar parte de tu "
	"indumentaria.\n"));
  SetIntShort("una tienda de ropa");
  SetLocate("la ciudad de Atbalnin");
  SetIntNoise("El murmullo de la ciudad es aqu� un poco m�s tenue.\n");
  SetIntSmell("Huele a ropa.\n");
  AddDetail(({"estanter�a", "estanteria", "estanter�as", "estanterias",
  	"estante", "estantes"}), W("En los estantes es donde est� toda "
  	"la mercanc�a en venta.\n"));
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


