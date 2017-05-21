/*

    Nombre      : herreriaEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : La herrería y armería de Enalel.
                  Sólo se puede comerciar con armas.

*/
#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <scheduler.h>
inherit "/room/herreria";

create(){
    ::create();

    SetIntBright(30);
    SetLocate("Poblado de Enalel");
    SetIntShort("la herrería de Krolle");
    SetIntLong("Estás en la herrería de Enalel, propiedad del viejo Krolle. "
    "Al sur está la salida hacia la calle del comercio.\n");
    SetShopkeeper(ENALPNJ"tenderos/krolle");
    RemoveDustbin();
    RemoveExit("almacen");
    AddArticle(ARMAS("cuchillo"),REFRESH_REMOVE,1);
    AddArticle(ARMAS("espada_ancha"),REFRESH_REMOVE,d2());
    AddExit("sur",ENALHAB"poblado/calles/calle03");
    AddDoor("sur", "la puerta de salida",
    "La puerta para salir a la calle del comercio.\n",
    ({"puerta", "puerta de salida", "puerta de la calle", "puerta del sur"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    SetLastDest(ENALHAB"poblado/calles/calle03");
    SetNotifyExits("sur");
    SetNotifyOpenMsg("@name@ llega del este y abre la herrería.\n");
    SetNotifyCloseMsg("@name@ sale de la herrería, cierra la puerta con llave y se va "
    "hacia el oeste.\n");
}

int CheckTrade(object ob){
    if (ob->QueryWeaponType() || ob->QueryArmourType())
        return 1;
}
