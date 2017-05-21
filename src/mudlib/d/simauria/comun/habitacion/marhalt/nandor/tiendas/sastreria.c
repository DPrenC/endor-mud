/****************************************************************************
Fichero: sastreria.c
Autor: Ratwor
Fecha: 04/11/2006
Descripci�n: la sastrer�a de nandor, solo se venden y compran protecciones.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>
inherit SHOP;

create(){
    ::create();

    SetIntBright(25);
    SetLocate("Aldea de Nandor");
    SetIntShort("la sastrer�a");
    SetIntLong("Est�s en una estancia un tanto reducida, en donde el olor, a las pieles que"
        " se venden, inunda todo a su alrededor. Algunas prendas se exponen en estanter�as,"
        " aunque no es que haya mucha mercanc�a.\n");
    SetShopkeeper(PNJ("marhalt/peletera_nandor"));
    SetIntSmell("Huele a pieles.\n");
    AddDetail(({"estanter�a","estanter�as"}),"Los productos a la venta est�n colocados en"
        " perfecto orden.\n");
    AddDetail(({"ropa","ropas","prenda","prendas","producto","productos","mercancia",
        "mercancias","mercanc�a","mercanc�as"}), "Est� todo  bien ordenado en las "
        "estanter�as, pide la lista para saber sus precios.\n");
    AddExit("sur", MARH("nandor/calle14"));
    RemoveExit("almacen");
    SetNotifyExits("sur");
    SetLastDest("../calle14");
    AddDoor("sur", "la puerta de la calle",
    "Es la puerta que da a la calle.\n",
    ({"puerta de la calle", "puerta del sur", "puerta"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));

    AddArticle(PROT("blusa"),REFRESH_REMOVE,d2());
    AddArticle(PROT("falda"),REFRESH_REMOVE,d2());
    AddArticle(PROT("guantes"),REFRESH_REMOVE,d2());
    AddArticle(PROT("pantalon"),REFRESH_REMOVE,d2());
    AddArticle(PROT("camisa_cuero"),REFRESH_REMOVE,d2());
    AddArticle(PROT("cota_cuero"),REFRESH_REMOVE,d2());
    AddArticle(PROTNANDOR("capucha_p"), REFRESH_REMOVE,d2());
    AddArticle(PROTNANDOR("sandalias_p"), REFRESH_REMOVE,d2());
    AddArticle(PROTNANDOR("tunica_p"), REFRESH_REMOVE,d2());
    AddArticle(PROT("botas_cuero"),REFRESH_REMOVE);
    AddArticle(PROT("botas_cuero_p"),REFRESH_REMOVE);
    AddArticle(PROT("botas_cuero_g"),REFRESH_REMOVE);
    
    if(d2()==1)
        AddArticle(OTRO("azmodan/vaina"),REFRESH_REMOVE,1);
}

int CheckTrade(object ob){
    if (ob->QueryArmourType()) return 1;
    return 0;
}
