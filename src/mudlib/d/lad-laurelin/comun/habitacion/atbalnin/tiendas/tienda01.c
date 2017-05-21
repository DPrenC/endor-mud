#include "path.h"
#include "/secure/wizlevels.h"
#include <nightday.h>
inherit DOM_STD+"tienda";

create()
{
  ::create();
  SetIntLong(W("Estás en la tienda de Alombir, un curioso hombrecillo que "
  	"regenta este comercio. Es un poco austera, aunque prácticamente "
  	"tiene de todo.\n"));
  SetIntShort("la tienda de Alombir");
  SetLocate("la ciudad de Atbalnin");
  SetIntNoise("El murmullo de la ciudad es aquí un poco más tenue.\n");
  SetIntSmell("Huele a objetos antiguos amontonados.\n");
  AddDetail(({"estantería", "estanteria", "estanterías", "estanterias",
  	"estante", "estantes"}), W("Un poco por todos sitios puedes ver el "
 	"desorden reinante en el lugar... Los objetos se amontonan por donde "
 	"pueden en unas resistentes estanterías de madera, las cuales carecen "
 	"totalmente de cualquier ornamento.\n"));
  SetShopkeeper(PNJ("atbalnin/ciudad/alombir"));
  AddArticle(BEBIDA("licor"), REFRESH_REMOVE, 5);
  AddArticle(ARMA("vara"), REFRESH_REMOVE, 2);
  AddArticle(PROT("botas"), REFRESH_REMOVE, 3);
  AddArticle(PROT("capa"), REFRESH_REMOVE, 3);
  AddArticle(PROT("pantalones"), REFRESH_REMOVE, 3);
  AddArticle("/obj/arco", REFRESH_REMOVE, 3);
  AddArticle("/obj/carcaj", REFRESH_REMOVE, 6);
  AddArticle("/obj/torch", REFRESH_REMOVE, 3);
  AddArticle("/obj/oil_bottle",REFRESH_REMOVE,3);
  AddArticle("/obj/lighter",REFRESH_REMOVE,1);
  AddArticle("/obj/bcocina", REFRESH_REMOVE, 5);
  AddArticle("/obj/mochila", REFRESH_REMOVE, 3);
  AddArticle(OTRO("mochilac"), REFRESH_REMOVE, 2);
  AddArticle("/obj/vial", REFRESH_REMOVE, 4);
  AddArticle("/obj/vialv", REFRESH_REMOVE, 8);
  AddArticle("/obj/vialm", REFRESH_REMOVE, 8);

  AddExit("salir", ATB_CI("ciudad09"));
}


