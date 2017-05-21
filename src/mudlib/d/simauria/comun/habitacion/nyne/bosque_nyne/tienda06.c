#include "path.h"
inherit BOSQUE_NYN("tiendac");

create(){
 ::create();

 SetIntShort("la tienda de Don");
 SetIntLong(W("Estas en la Tienda de Don. Se trata de un puesto"
              " casi al aire libre, aunque un toldo y un par de"
              " mal disimuladas paredes hacen que aqui el bullicio"
              " se oiga menos. Puedes ver todo tipo de protecciones y"
              " ARMADURAS PEQUEÑAS de contrabando por todos lados.\n"));

 SetShopkeeper(PNJNYN("Don"));

 AddArticle(PROT("botas_metal_p"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("casco_hierro_p"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("coraza_acero_p"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("coraza_cuero_p"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("coraza_hierro_p"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("grebas_acero_p"),REFRESH_DESTRUCT,1);
 AddArticle(PROT("guantes_metal_p"),REFRESH_DESTRUCT,1);
    if(d10()==1)
        AddArticle(PROT("yelmo_ornamentado"), REFRESH_REMOVE);

 AddExit("norte",BOSQUE_NYN("g10"));
 AddExit("este",BOSQUE_NYN("g15"));
 AddExit("nordeste",BOSQUE_NYN("g11"));

}

