#include "path.h"
inherit BOSQUE_NYN("tiendac");

create(){
 ::create();

 SetIntShort("la tienda de Blister");
 SetIntLong(W("Estas en la Tienda de Blister. Se trata de un puesto"
              " casi al aire libre, aunque un toldo y un par de"
              " mal disimuladas paredes hacen que aqui el bullicio"
              " se oiga menos. Puedes ver todo tipo de protecciones"
              " y ARMADURAS GRANDES de contrabando por todos lados.\n"));

 SetShopkeeper(PNJNYN("Blister"));

 AddArticle(PROT("botas_metal_g"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("casco_hierro_g"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("coraza_acero_g"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("coraza_cuero_g"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("coraza_hierro_g"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("grebas_acero_g"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("guantes_metal_g"),REFRESH_DESTRUCT,1);

 AddExit("sur",BOSQUE_NYN("g03"));
 AddExit("este",BOSQUE_NYN("g01"));
 AddExit("sudeste",BOSQUE_NYN("g04"));
}
