#include "./path.h"
#include <rooms.h>
#include <guild.h>
inherit "/std/shop";


create() {
::create();

  SetIntLong(W("Est�s en la tienda del Gremio de los Hechiceros. Aqu� se venden "
  	"varios art�culos, todos ellos de caracter magico. Sin embargo, los "
  	"precios son bastante altos,por lo menos parece que los objetos "
  	"valen su precio.\nLa tienda regenta ilania , una elfa de bastante poder magico .\n"));
SetIndoors(1);
  SetIntShort("la tienda de Ilania");
  SetLocate("el gremio de los Hechiceros");
  AddDetail(({"estanter�a", "estanteria", "estanter�as", "estanterias",
  	"estante", "estantes"}), W("Un poco por todos sitios puedes ver la "
 	"mercancia cuidadosamente guardada en el lugar... .\n"));


AddArticle(H_HOME+"pergamino/pergamino_campo", REFRESH_REMOVE,3);
  AddExit("norte","./esca1");
  RemoveExit("almacen");

//SetShopkeeper("/d/simauria/comun/pnj/simauria/berat/ilania");
}



