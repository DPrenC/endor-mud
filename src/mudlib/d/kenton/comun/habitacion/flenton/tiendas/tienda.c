/***************************************************************************************
 ARCHIVO:	tienda.c
 AUTOR:		[k] Korsario
 FECHA:		23-06-1998
 COMENTARIOS:	Tienda de Flenton
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>

inherit SHOP;

create(){
  ::create();

  SetIndoors(1);
  SetIntBright(80);
  SetLocate("Flenton");
  SetIntNoise("Escuchas un pequeño ruido proveniente del almacén, ratones quizás.\n");
  SetIntSmell("Hay una mezcla de olores, pero no es desagradable el resultado.\n");
  SetIntShort("la tienda de Flenton");
  SetIntLong("Esta es la tienda de Flenton, que tambien las veces de pequeño "
  	"almacén. En esta tienda podrás encontrar las cosas más diversas y "
  	"extrañas que te puedas imaginar, cualquier cosa es posible.\n");

  AddDetail(({"tienda","tienda de Flenton"}),"Es una tienda como todas las "
  	"tiendas de pueblo, hay de todo.\n");
  AddRoomCmd("matar","fmatar");

  AddExit("sur",FLENHAB+"calles/plaza_00");

    AddArticle(FLENVAR+"mapa",REFRESH_REMOVE,3);
    AddArticle(FLENVAR+"plato",REFRESH_REMOVE,3);
    AddArticle(FLENVAR+"vaso",REFRESH_REMOVE,3);
    AddArticle(FLENVAR+"cuchara",REFRESH_REMOVE,3);
    AddArticle("/obj/candle",REFRESH_REMOVE,5);
    AddArticle("/obj/torch",REFRESH_REMOVE,5);
    AddArticle("/obj/oil_bottle",REFRESH_REMOVE,4);
    AddArticle("/obj/lighter",REFRESH_REMOVE,2);
    AddArticle("/obj/cuerda", REFRESH_REMOVE,3);

  RemoveDustbin();
  SetShopkeeper(0,([P_SHORT:"Tirma, la tendera",P_LONG: "Tirma, la tendera de "
  	"la única tienda de Flenton. Es una mujer kender muy amable. Tiene una "
  	"bonita sonrisa, y siempre palabras de amabilidad para un extraño.\n",
  	P_IDS: ({"tirma","tendera"}),P_ADS: ({"la","kender"})]));
}

int fmatar(string str)
{
	if(!str) return 0;
	write("La tendera te mira con cara de pocos amigos y saca una "
		"escoba enorme.\nLa tendera dice: ¡este es un establecimiento "
		"decente y no se mata a nadie aquí!\n""La tendera te echa a la "
		"calle a escobazos.\n");
	say("La tendera hecha a escobazos a "+CATP+".\n",TP);
	TP->move(FLENHAB+"calles/plaza_00",M_GO);
	return 1;
}
