#include "path.h"
inherit BOSQUE_NYN("tiendac");

create(){
    ::create();

    SetIntShort("la tienda de Trancer");
    SetIntLong("Estás en la Tienda de Trancer. Se trata de un puesto"
              " casi al aire libre, aunque un toldo y un par de"
              " mal disimuladas paredes hacen que aquí el bullicio"
              " se oiga menos. Puedes ver distintos tipos"
              " de ARMAS de distinto tamaño de contrabando por todos lados.\n");

    SetShopkeeper(PNJNYN("Trancer"));

    AddArticle(ARMA("baculo_p"),REFRESH_DESTRUCT,1);
    AddArticle(ARMA("baston_p"),REFRESH_DESTRUCT,1);
    AddArticle(ARMA("cadena_p"),REFRESH_DESTRUCT,1);
    AddArticle(ARMA("claymore_p"),REFRESH_DESTRUCT,1);
    AddArticle(ARMA("daga_p"),REFRESH_DESTRUCT,2);
    AddArticle(ARMA("esp_plata_p"),REFRESH_DESTRUCT,2);
    AddArticle(ARMA("espada_p"),REFRESH_DESTRUCT,1);
    AddArticle(ARMA("espada_larga_p"),REFRESH_DESTRUCT,2);
    AddArticle(ARMA("hacha_combate_p"),REFRESH_DESTRUCT,1);
    AddArticle(ARMA("hacha-2manos_p"),REFRESH_DESTRUCT,1);
    AddArticle(ARMA("mangual_p"),REFRESH_DESTRUCT,2);
    AddArticle(ARMA("maza_hierro_p"),REFRESH_DESTRUCT,2);
    AddArticle(ARMA("vara_p"),REFRESH_DESTRUCT,1);
    AddArticle(ARMA("alfanje"), REFRESH_REMOVE);
    AddArticle(ARMA("estoque"), REFRESH_REMOVE);
    if(d3()==1)
        AddArticle(ARMA("daga_enjoyada"), REFRESH_REMOVE);
    if(d2()==1)
        AddArticle(ARMANANDOR("espada_1mano"), REFRESH_REMOVE);
    AddExit("norte",BOSQUE_NYN("g12"));
    AddExit("este",BOSQUE_NYN("g16"));
    AddExit("oeste",BOSQUE_NYN("g15"));

}

