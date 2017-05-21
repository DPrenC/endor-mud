/*

    Nombre      : tiendaBertur
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripci�n : La tienda del feliz Bertur.
                  Se har�n descuentos a humanos, elfos y medioelfos.
                  Se vender�n todos los art�culos de comida y bebida de Enalel

*/

#include "./path.h"
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit SHOP;

create(){
    ::create();

    SetIntBright(30);
    SetLocate("Poblado de Enalel");
    SetIntShort("la tienda del feliz Bertur");
    SetIntLong("Est�s en la tienda del feliz Bertur. Es conocido por su afable "
    "sonrisa y sus buenos precios de venta a quien �l cree pertinente. En esta "
    "tienda encontrar�s art�culos de todo tipo. La salida de la tienda est� hacia "
    "el este.\n");
    SetIntNoise("Los ruidos de la naturaleza llegan hasta aqu� amortiguados.\n");
    SetIntSmell("Una fragancia a rosas te sorprende.\n");
    SetShopkeeper(ENALPNJ"tenderos/bertur");
    AddExit("este",ENALHAB"poblado/calles/calle18");
    RemoveExit("almacen");
    SetLastDest(ENALHAB"poblado/calles/calle18");
    SetNotifyExits("este");
    SetNotifyOpenMsg("@name@ llega felizmente desde el este, abre la tienda y se "
    "mete dentro.\n");
    SetNotifyCloseMsg("@name@ sale de la tienda, la cierra y se marcha hacia el este.\n");
    AddDoor("este", "la puerta de salida",
    "La puerta para salir a la calle.\n",
    ({"puerta", "puerta de salida", "puerta de la calle", "puerta del este"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AddArticle(ENALCOM"pan",REFRESH_REMOVE,3);
    AddArticle(ENALCOM"lechuga",REFRESH_REMOVE,3);
    AddArticle(ENALCOM"manzana",REFRESH_REMOVE,3);
    AddArticle(ENALCOM"chorizo",REFRESH_REMOVE,3);
    AddArticle(ENALCOM"uvas",REFRESH_REMOVE,3);
    AddArticle(ENALCOM"melon",REFRESH_REMOVE,3);
}

int ModifyPrice (object obj, int price, string verb){
    if (verb == "comprar" && (TP->QueryRace()=="humano" || TP->QueryRace()=="elfo" || TP->QueryRace()=="medioelfo")){
	write("Bertur te sonr�e y te dice: 'Me caes bien'\n");
        say("Bertur sonr�e a "+CATP+" y le dice: 'Me caes bien'\n");
        return (9*price)/10;
    }
    return price;
}
