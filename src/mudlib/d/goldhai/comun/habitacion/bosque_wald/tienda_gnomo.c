/****************************************************/
//
//	"tienda_spook"
//	La tienda del valle
//	18-12-01: Kodex -> Creación
//	20-12-01: Kodex -> Última modificación
//		*Añadidos unos cuantos objetos a parte
//		 del pergata.
// 23-03-2008 Ratwor: traslado la tienda desde el valle de Azmodan a los bosques de Goldhai.
/****************************************************/

inherit SHOP;
#include "./path.h"

create()
{
    ::create();

    SetIntShort("la tienda de Ychnglldyl");

    SetIntLong("Esta es la casa de Ychnglldyl, un brujo gnomo que vive"
    " entre estas cuatro paredes de madera resguardado de la violencia "
    "de fuera. La casa no tiene techo y las enredaderas suben por las "
    "paredes, Ychnglldyl usa esta casa también como una tienda, le gusta comprar "
    "objetos extraños y vende sus conocimientos. Hay un letrero que "
    "pone: precios sobre maldiciones.\n");

    AddDetail("letrero","Precios sobre maldiciones\n"
		    "Yo puedo arreglar tus objetos malditos:\n"
		    " * quitar maldicion a <objeto> ........ 400 monedas de mithril\n\n");

    SetIntBright(30);
    AddExit("fuera",BWALD("bosque24"));

    SetLocate("bosque Wald");
    SetShopkeeper(PNJ("bosque_wald/gnomo"));

    RemoveDustbin(1);
    RemoveExit("almacen");
    SetNotifyExits("fuera");
    SetLastDest("./bosque24");
    SetNotifyCloseMsg("@name@ se asoma por la puerta y dice: voy a descansar, "
    "mañana más.\n Seguidamente cierra la puerta quedándose dentro de la cabaña.\n");
    SetNotifyOpenMsg("La puerta de la cabaña se abre y @name@ asoma la cabeza, tras "
    "una mirada a la frondosidad del bosque dice:\n Bien, ya estoy disponible para quien "
    "precise de mis servicios.\n");
    AddDoor("fuera", "la puerta de salida",
    "Es la puerta para salir al bosque wald.\n",
    ({"puerta de salida", "puerta de fuera", "puerta"}));

    AddArticle(COMIDA("tarta"),REFRESH_REMOVE,d4());
    AddArticle("/obj/torch",REFRESH_REMOVE,d3());
    AddArticle("/obj/oil_bottle",REFRESH_REMOVE,d2());
    AddArticle("/obj/lighter", REFRESH_REMOVE, 1);
    AddArticle("/obj/sunglasses",REFRESH_REMOVE,1);
    AddArticle("/obj/bandage",REFRESH_REMOVE,d10());
    AddArticle("/obj/bcocina",REFRESH_REMOVE,d6());
    AddArticle(PROT("cuero"),REFRESH_REMOVE,1);
    AddArticle(PROT("cota"),REFRESH_REMOVE,1);
    AddArticle("/obj/candle", REFRESH_REMOVE,d3());
}
