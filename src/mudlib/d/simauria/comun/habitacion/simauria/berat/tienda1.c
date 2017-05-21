	/*
DESCRIPCION : tienda del poblado de pescadores
FICHERO     : /d/limbo/comun/habitacion/limbo/limbo/tienda.c
MODIFICACION: 17-07-98 [Angor@Simauria] Creacion
MODIFICACION: 04-11-99 [Icaro]Afanando para Berat
[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>
inherit SHOP;

#define NOMBRE          (TP->QueryName())
#define NOMBRE_M        (capitalize NOMBRE)
#define SUF             (TP->QueryGenderEndString())
#define SUF2            (TP->QueryGender()==2?"a":"e")

int matar_(string str);

create()
{
    ::create();
    SetIntShort("la tienda de Kalib");
    SetIntLong(
    "Est�s en la tienda de Kalib. Es una siniestra tienda en la que podr�s comprar "
    "y vender de todo. Es una tienda peque�a pero acogedora. Puedes ver un mostrador "
    "con una nota encima y todo tipo de objetos extra�os por las paredes, fruto "
    "de los incontables viajes que ha realizado su due�o.\n");

    AddDetail(({"tienda","local"}),QueryIntLong());

    AddDetail(({"objetos","objetos extra�os"}),
    "Son unos artilugios y m�scaras extra�os, muchos de los cuales son desconocidos "
    "incluso para ti. Parecen meramente decorativos y no tienen pinta de estar a la venta.\n");

    SetIntNoise("Escuchas ruidos procedentes del almac�n.\n");
    SetIntSmell("Huele a una extra�a mezcla de flores.\n");
    SetLocate("berat");
    SetIntBright(30);
    RemoveExit("almacen");
    AddExit("este","./cmerc4");
    AddDoor("este", "la puerta de la calle",
    "Es la puerta que da a la calle del mercado.\n",
    ({"puerta", "puerta de la calle", "puerta de salida", "puerta del este"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    SetLastDest("./cmerc4");
    SetNotifyExits("este");
    SetNotifyCloseMsg("@name@ cierra la tienda y se marcha hacia el norte.\n");
    SetNotifyOpenMsg("@name@ llega del sur, abre la puerta de la tienda y entra.\n");
    CanIdentify(0); //No se identifican objetos

    SetShopkeeper(PNJ("simauria/berat/kalib"));

    //articulos a la venta
    AddArticle("/std/weapon",REFRESH_REMOVE,2,
    ([P_SHORT: "una maza de madera",
    P_LONG:"Una maza de madera, �til para usar de martillo o para clavar clavos\n",
    P_IDS: ({"maza de madera","maza"}),
    P_WC: 5,
    P_WEIGHT: 3000,
    P_GENDER: 2,
    P_VALUE: 350,
    P_NUMBER_HANDS: 1,
    P_WEAPON_TYPE:CS_MAZA,
    P_DAM_TYPE:DT_BLUDGEON]));

    AddArticle("/obj/cuerda", REFRESH_REMOVE,d2());
    AddArticle("/obj/torch", REFRESH_REMOVE,d4());
    AddArticle("/obj/oil_bottle",REFRESH_REMOVE,d3());
    AddArticle("/obj/lighter", REFRESH_REMOVE, d2());
    AddArticle("/obj/bcocina",REFRESH_REMOVE,5);
    AddArticle("/obj/vial", REFRESH_REMOVE, 4);
    AddArticle("/obj/vialv", REFRESH_REMOVE, 4);
    AddArticle("/obj/vialm", REFRESH_REMOVE, 5);
    AddArticle("/obj/mochila",REFRESH_REMOVE,3);
    AddArticle("/obj/candle", REFRESH_REMOVE,d3());
}

void init()
{
  (::init());

  if (sk_in_shop())
   {
  write("Kalib te saluda al entrar en la tienda: 'Hola, bienvenid"+SUF+" a mi tienda. "
        "en que te puedo atender.\n");

  say(  "Kalib saluda a "+NOMBRE_M+" cuando est"+SUF2+" entra en la tienda y le atiende.\n",TP);

  }
}

