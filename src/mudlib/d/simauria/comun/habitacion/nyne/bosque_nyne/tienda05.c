#include "path.h"
inherit BOSQUE_NYN("tiendac");

create(){
    ::create();

    SetIntShort("la tienda de Dash");
    SetIntLong("Estas en la Tienda de Dash. Se trata de un puesto"
              " casi al aire libre, aunque un toldo y un par de"
              " mal disimuladas paredes hacen que aqui el bullicio"
              " se oiga menos. Puedes ver distintos tipos de"
              " HIERBAS de contrabando por todos lados.\n");

    SetShopkeeper(PNJNYN("Dash"));

    AddArticle(OTRO("fruto_plata"),REFRESH_DESTRUCT,3);
    AddArticle(OTRO("fruta_rara"),REFRESH_DESTRUCT,2);
    AddArticle(HERBS("hierba_venenosa"), REFRESH_REMOVE, d6());
    AddExit("norte",BOSQUE_NYN("g07"));
    AddExit("sur",BOSQUE_NYN("g14"));
    AddExit("oeste",BOSQUE_NYN("g09"));

}

