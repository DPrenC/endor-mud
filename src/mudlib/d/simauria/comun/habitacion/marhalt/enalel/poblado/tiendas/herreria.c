/*

    Nombre      : herreriaEnalel
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : La herrer�a y armer�a de Enalel.
                  S�lo se puede comerciar con armas.

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
    SetIntShort("la herrer�a de Krolle");
    SetIntLong("Est�s en la herrer�a de Enalel, propiedad del viejo Krolle. "
    "Al sur est� la salida hacia la calle del comercio.\n");
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
    SetNotifyOpenMsg("@name@ llega del este y abre la herrer�a.\n");
    SetNotifyCloseMsg("@name@ sale de la herrer�a, cierra la puerta con llave y se va "
    "hacia el oeste.\n");
}

int CheckTrade(object ob){
    if (ob->QueryWeaponType() || ob->QueryArmourType())
        return 1;
}
