/*

    Nombre      : tiendaPofor
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : tienda de cualquier tipo de art�culo.
                  Se har�n descuentos a todos los players con alineamientos menores de 0.

*/
#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit SHOP;

create(){
    ::create();

    SetIndoors(1);
    SetIntBright(35);
    SetLocate("Poblado de Enalel");
    SetIntShort("la tienda de Pofor");
    SetIntLong("Est�s en la tienda del elfo Pofor. Se dice que el exc�ntrico "
    "Pofor compra casi cualquier cosa. Percheros y estanter�as repletos de "
    "art�culos variados forman el inmoviliario de la tienda. La salida est� "
    "hacia el sur.\n");
    SetIntNoise("El m�s absoluto e intranquilizante de los silencios llena esta sala.\n");
    SetIntSmell("El aroma de las manzanas se mezcla con el de ex�ticos potingues.\n");
    SetShopkeeper(ENALPNJ"tenderos/pofor");
    AddDetail(({"estanter�a","estanter�as","perchero","percheros"}),"Los productos "
    "a la venta est�n colocados en perfecto orden.\n");
    AddDetail(({"producto","productos","mercancia","mercancias","mercanc�a","mercanc�as"}),
    "Si quieres saber que vende Pofor, pidele la lista de precios.\n");
    AddExit("sur",ENALHAB"poblado/calles/calle06");
    RemoveExit("almacen");
    SetLastDest(ENALHAB"poblado/calles/calle06");
    SetNotifyExits("sur");
    SetNotifyOpenMsg("@name@ llega del este, abre la tienda y entra pausadamente.\n");
    SetNotifyCloseMsg("@name@ sale de la tienda y, tras cerrar la puerta con llave, "
    "se marcha airoso hacia el este.\n");
    AddDoor("sur", "la puerta de salida",
    "La puerta para salir a la calle del comercio.\n",
    ({"puerta", "puerta de salida", "puerta de la calle", "puerta del sur"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
      AddArticle("/obj/bcocina",REFRESH_REMOVE,d4());
    AddArticle("/obj/bandage",REFRESH_REMOVE,d6());
    AddArticle("/obj/lighter", REFRESH_REMOVE, d2());
    AddArticle("/obj/torch", REFRESH_REMOVE, d2());
    AddArticle("/obj/oil_bottle", REFRESH_REMOVE, d2());
    AddArticle("/obj/cuerda", REFRESH_REMOVE, 1);
    AddArticle("/obj/sunglasses", REFRESH_REMOVE,1);
    AddArticle("/obj/bag", REFRESH_REMOVE,1);
    AddArticle("/obj/candle", REFRESH_REMOVE,d4());
}

int ModifyPrice (object obj, int price, string verb){
    if (verb == "comprar" && TP->QueryAlign()<0)
	return (9*price)/10;
    return price;
}
