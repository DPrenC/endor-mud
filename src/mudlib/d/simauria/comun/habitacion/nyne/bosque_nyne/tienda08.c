#include "path.h"
inherit BOSQUE_NYN("tiendac");

create(){
 ::create();

 SetIntShort("la tienda de Vix");
 SetIntLong(W("Estas en la Tienda de Vix. Se trata de un puesto"
              " casi al aire libre, aunque un toldo y un par de"
              " mal disimuladas paredes hacen que aqui el bullicio"
              " se oiga menos. Puedes ver todo tipo de"
              " ROPAJES PEQUEÑOS de contrabando por todos lados.\n"));

 SetShopkeeper(PNJNYN("Vix"));

 AddArticle(PROT("camisa_cuero_p"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("botas_cuero_p"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("pantalones_cuero_p"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("guantes_cuero_p"),REFRESH_DESTRUCT,1);
    if(d3()==1)
        AddArticle(PROT("diadema"), REFRESH_REMOVE);

 AddExit("norte",BOSQUE_NYN("g14"));
 AddExit("oeste",BOSQUE_NYN("g16"));
 AddExit("noroeste",BOSQUE_NYN("g13"));

}

