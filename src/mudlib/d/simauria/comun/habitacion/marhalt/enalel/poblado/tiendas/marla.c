/*

    Nombre      : tiendaMarla
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Tienda de ropa y artículos de vestimenta.
                  Marla es la madre del niño relacionado con el miniquest
                  Sólo se pueden comprar y vender protecciones.

*/
#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <scheduler.h>
inherit SHOP;

create(){
    ::create();

    SetIntBright(35);
    SetLocate("Poblado de Enalel");
    SetIntShort("la tienda de Marla");
    SetIntLong("Estás en la tienda de Marla. Es una coqueta tiendecita donde "
    "podrás comprar prendas de vestir de todo tipo. Las mercancías están colocadas "
    "de forma ordenada en percheros y estanterías. La salida está hacia el norte.\n");
    SetIntNoise("Una tenue melodía se escucha en la sala consiguiendo una calma total.\n");
    SetIntSmell("El aroma de las manzanas se mezcla con el de perfumes y maderas.\n");
    SetShopkeeper(ENALPNJ"tenderos/marla");
    AddDetail(({"estantería","estanterías","perchero","percheros"}),"Los productos "
    "a la venta están colocados en perfecto orden.\n");
    AddDetail(({"ropa","ropas","prenda","prendas","producto","productos","mercancia",
    "mercancias","mercancía","mercancías"}),"Si quieres saber que vende Marla, pidele "
    "la lista de precios.\n");
    RemoveDustbin();
    RemoveExit("almacen");
    AddExit("norte",ENALHAB"poblado/calles/calle04");
    AddDoor("norte", "la puerta de salida",
    "Es la puerta para salir a la calle del comercio.\n",
    ({"puerta", "puerta de la calle", "puerta de salida", "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    SetLastDest(ENALHAB"poblado/calles/calle04");
    SetNotifyExits("norte");
    SetNotifyOpenMsg("@name@ llega del oeste y abre la tienda.\n");
    SetNotifyCloseMsg("@name@ sale de la tienda, cierra la puerta con llave y se va "
    "hacia el este.\n");
    AddArticle(ENALPRT"blusa",REFRESH_REMOVE,d4());
    AddArticle(ENALPRT"camisa",REFRESH_REMOVE,d4());
    AddArticle(ENALPRT"pantalon",REFRESH_REMOVE,d4());
    AddArticle(ENALPRT"guante",REFRESH_REMOVE,d4());
}

int CheckTrade(object ob){
    if (ob->QueryArmourType()) return 1;
}
