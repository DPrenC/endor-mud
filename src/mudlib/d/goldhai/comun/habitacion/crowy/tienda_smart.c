/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |               Ultima Modificacion.. 16-11-99                |
 |               Cajun................ 12-06-01                |
 *=============================================================*/

#include "./path.h"
#include <properties.h>


inherit SHOP;

create()
{
 ::create();
 SetIntShort("la tienda de Smart");
   SetIntLong(
    "Estás dentro de la tienda del viejo Smart, un anciano que se dedica a reparar "
    "todos los objetos que encuentra para luego revenderlos. Sus manos son capaces "
    "de hacer cualquier cosa y todo el mundo lo sabe. Todo lo que vende, aunque "
    "este usado, es de primera calidad, asimismo también compra casi todo lo que "
    "le traigas.\n");
   SetIntBright(40);
   SetIntNoise("No oyes nada que atraiga tu atención.\n");
   SetIntSmell("Hmm.. no huele a nada especial.\n");

 AddExit("norte",CROWY("zona_comercial1"));

    RemoveExit("almacen");
 AddItem(PNJ("crowy/guardia_elfo"),REFRESH_DESTRUCT); // Smart necesita proteccion

AddArticle("/obj/candle", REFRESH_REMOVE,d3());
 AddArticle("/obj/torch",REFRESH_REMOVE,5);
 AddArticle("/obj/oil_bottle",REFRESH_REMOVE,4);
 AddArticle("/obj/lighter",REFRESH_REMOVE,2);
 AddArticle(OTRO("pala"),REFRESH_REMOVE,3);
 AddArticle("/obj/sunglasses",REFRESH_REMOVE,([P_VALUE:18]),3);
 AddArticle(OTRO("brocha"),REFRESH_REMOVE,5);
 AddArticle("/obj/cuerda",REFRESH_REMOVE,3);
 AddArticle("/obj/bcocina",REFRESH_REMOVE,5);

 SetShopkeeper(PNJ("crowy/smart"));
 SetLocate("Crowy");
}

