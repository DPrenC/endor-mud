#include "path.h"
inherit BOSQUE_NYN("tiendac");

create(){
 ::create();

 SetIntShort("la tienda de Handalf");
 SetIntLong(W("Estas en la Tienda de Handalf. Se trata de un puesto"
              " casi al aire libre, aunque un toldo y un par de"
              " mal disimuladas paredes hacen que aqui el bullicio"
              " se oiga menos. Puedes ver distintos tipos"
              " de ARMAS GRANDES de contrabando por todos lados.\n"));

 SetShopkeeper(PNJNYN("Handalf"));

 AddArticle(ARMA("baculo_g"),REFRESH_DESTRUCT,1);
 AddArticle(ARMA("baston_g"),REFRESH_DESTRUCT,1);
 AddArticle(ARMA("cadena_g"),REFRESH_DESTRUCT,1);
 AddArticle(ARMA("claymore_g"),REFRESH_DESTRUCT,1);
 AddArticle(ARMA("daga_g"),REFRESH_DESTRUCT,2);
 AddArticle(ARMA("esp_plata_g"),REFRESH_DESTRUCT,2);
 AddArticle(ARMA("espada_g"),REFRESH_DESTRUCT,1);
 AddArticle(ARMA("espada_larga_g"),REFRESH_DESTRUCT,2);
 AddArticle(ARMA("hacha_combate_g"),REFRESH_DESTRUCT,1);
 AddArticle(ARMA("hacha-2manos_g"),REFRESH_DESTRUCT,1);
 AddArticle(ARMA("mangual_g"),REFRESH_DESTRUCT,2);
 AddArticle(ARMA("maza_hierro_g"),REFRESH_DESTRUCT,2);
 AddArticle(ARMA("vara_g"),REFRESH_DESTRUCT,1);
    if(d2()==1)
        AddArticle(ARMA("baston_lujoso"),REFRESH_REMOVE);
 AddExit("sur",BOSQUE_NYN("g05"));
 AddExit("este",BOSQUE_NYN("g02"));
 AddExit("oeste",BOSQUE_NYN("g01"));
}

