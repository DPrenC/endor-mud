/* Nombre: herreria.c
Autor: aule
Fecha: 10/06/2014
Descripción: herrería de Bree, enclave de quest.
*/
#include "./path.h"
#include <attributes.h>
#include <properties.h>
#include <combat.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit "/room/herreria";


create()
{
    ::create();

   SetLocate("la herrería de la aldea de Bree");
    SetIntShort("La herrería de Weltford");
    SetIntLong(
    "Estás en la herrería de Bree, donde Weltford, el propietario, se encarga de forjar "
    "y reparar todos los objetos de metal que necesitan los habitantes de las cuatro "
    "aldeas. Es una estancia rectangular, con piso de tierra apisonada y argamasa "
    "alisada y paredes de piedra toscamente pulimentada. La gran puerta de doble "
    "batiente da acceso a la calle al este mientras que al sur, otra puerta grande da paso al patio "
    "de la herrería donde suelen herrarse los animales que así lo requieren. Junto a la "
    "forja hay un gran yunque de hierro y unos fuelles de piel de buey curtida.\n"
    "Una gran chimenea de piedra y ladrillo canaliza el humo del fuego hacia el "
    "exterior, y un par de enormes barriles de roble contienen agua para atemperar "
    "el metal y prevenir posibles incendios. De las paredes, sobre valdas y en "
    "diversos estantes hay toda clase de artículos fabricados por el herrero y que están "
    "a la venta. Aquí puede encontrarse casi de todo, desde una piedra de afilar o un "
    "clavo de herradura hasta una azada, y últimamente, a causa de los rumores de "
    "conflictos lejanos que llegan de todas partes, también pueden verse algunas armas "
    "básicas que han comenzado a fabricarse en previsión de cualquier contingencia.\n");
    AddDetail(({"valdas", "estantes"}),
    "Simples tablones sujetos a los muros.\n");
    AddDetail("fuelles",
    "Constan de un armazón de fuertes varillas de acero envueltas en pieles de buey que "
    "al contraerse y expanderse arrojan una corriente de aire sobre las brasas.\n");
    AddDetail("barriles",
    "Dos enormes toneles de roble claveteado con grifos de bronce que permiten llenar "
    "cubos rápidamente.\n");
        SetIntBright(35);
    SetIntNoise("Escuchas los golpes  intermitentes del martillo sobre el yunque.\n");
    SetIntSmell("Huele a humo, metal al rojo, aceite y madera seca.\n");

    AddItem(OTROS("yunque"),REFRESH_REMOVE,1);
        SetShopkeeper(PNJ_BREE("comercios/weltford"));



        AddArticle("/obj/armas/daga",REFRESH_REMOVE, d8());
      AddArticle("/obj/armas/espada_corta",REFRESH_REMOVE, d3());
       AddArticle("/obj/armas/jabalina",REFRESH_REMOVE, d6());
       AddArticle("/obj/armas/hacha_mano",REFRESH_REMOVE, d4());
     AddArticle("/obj/armas/cuchillo",REFRESH_REMOVE, d8());
       AddArticle("/obj/herramientas/azada",REFRESH_REMOVE, d4());
       AddArticle("/obj/herramientas/rastrillo", REFRESH_REMOVE, d3());
       AddArticle("/obj/herramientas/guadanya", REFRESH_REMOVE, d2());
AddArticle("/obj/herramientas/tenazas", REFRESH_REMOVE, d2());
AddArticle("/obj/herramientas/pala", REFRESH_REMOVE, d3());
AddArticle("/obj/herramientas/martillo_herrero", REFRESH_REMOVE, d2());
AddArticle("/obj/herramientas/hoz_mano", REFRESH_REMOVE, d4());
AddArticle("/obj/herramientas/horca", REFRESH_REMOVE, d2());
AddArticle("/obj/herramientas/hachuela", REFRESH_REMOVE, d4());
AddArticle("/obj/herramientas/hacha_lenyador", REFRESH_REMOVE, d2());
("/obj/herramientas/sierra", REFRESH_REMOVE, d2());
AddArticle("/obj/otros/clavos_herrar", REFRESH_REMOVE, d10());
AddArticle("/obj/otros/eslabon", REFRESH_REMOVE, d6());
AddArticle("/obj/otros/herradura_g", REFRESH_REMOVE, d20());
AddArticle("/obj/otros/herradura_p", REFRESH_REMOVE, d20());
AddArticle("/obj/otros/piedra_afilar", REFRESH_REMOVE, d6());


AddExit("oeste", "../h_patio");
    AddExit("este", "../vias9");
    AddDoor("este", "una puerta de doble batiente",
    "Es un gran portón de madera por la que podría entrar un carro y por la que es fácil "
    "introducir a las monturas para herrarlas..\n",
    ({"porton", "este", "puerta del este", "puerta", "e"}));
        AddDoor("oeste", "el portón del sur",
    "Es un gran portón de madera por la que podría entrar un carro y por la que es fácil "
    "introducir a las monturas en el patio para herrarlas.\n",
    ({"porton", "oeste", "puerta del oeste", "puerta", "o"}));


/* Funciones propias de las tiendas */

    CanIdentify(0);
    CanAppraise(1);
    CanShow(1);
    CanList(1);
    CanBuy(1);
    CanSell(1);
    RemoveDustbin(1);


    SetNotifyExits("este");
    SetLastDest("../vias9");

}


int CheckTrade(object ob){
    if (ob->QueryMaterial()=="hierro" || ob->QueryMaterial()=="cobre" || ob->QueryMaterial()=="acero" || ob->QueryMaterial()=="bronce" || ob->QueryMaterial()=="mithril" || ob->QueryMaterial()=="plomo") return 1;
    return 0;
}
