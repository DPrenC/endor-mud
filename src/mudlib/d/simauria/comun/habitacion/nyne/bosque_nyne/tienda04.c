#include "path.h"
inherit BOSQUE_NYN("tiendac");

create(){
    ::create();

     SetIntShort("la tienda de Dan");
    SetIntLong("Estas en la Tienda de Dan. Se trata de un puesto"
              " casi al aire libre, aunque un toldo y un par de"
              " mal disimuladas paredes hacen que aqui el bullicio"
              " se oiga menos. Puedes ver distintos tipos de"
              " OBJETOS RAROS de contrabando por todos lados.\n");

    SetShopkeeper(PNJNYN("Dan"));

    AddArticle("/obj/lighter",REFRESH_REMOVE,d2());
    AddArticle("/obj/torch", REFRESH_REMOVE, d2());
    AddArticle("/obj/oil_bottle", REFRESH_REMOVE, d2());
    AddArticle(OTRO("lente"), REFRESH_REMOVE, 1);
    AddArticle("/obj/bag", REFRESH_REMOVE, d2());
    AddArticle("/obj/candle", REFRESH_REMOVE,d4());
    AddExit("norte",BOSQUE_NYN("g03"));
    AddExit("sur",BOSQUE_NYN("g10"));
    AddExit("este",BOSQUE_NYN("g08"));
}

