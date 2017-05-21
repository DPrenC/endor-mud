#include "path.h"
inherit BOSQUE_NYN("tiendac");

create(){
 ::create();

 SetIntShort("la tienda de Curush");
 SetIntLong(W("Estas en la Tienda de Curush. Se trata de un puesto"
              " casi al aire libre, aunque un toldo y un par de"
              " mal disimuladas paredes hacen que aqui el bullicio"
              " se oiga menos. Puedes ver todo tipo de"
              " ROPAJES GRANDES de contrabando por todos lados.\n"));

 SetShopkeeper(PNJNYN("Curush"));

 AddArticle(PROT("camisa_cuero_g"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("botas_cuero_g"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("pantalones_cuero_g"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("guantes_cuero_g"),REFRESH_DESTRUCT,1);

 AddExit("sur",BOSQUE_NYN("g07"));
 AddExit("oeste",BOSQUE_NYN("g02"));
 AddExit("suroeste",BOSQUE_NYN("g06"));
}

