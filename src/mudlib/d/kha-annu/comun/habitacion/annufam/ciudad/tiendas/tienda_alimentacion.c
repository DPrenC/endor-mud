/****************************************************************************
Fichero: tienda_alimentacion.c
Autor: Riberales
Creación: 27/09/2005
Descripción: La tienda de alimentación..
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit SHOP;

public void create()
{
	::create();

	SetIndoors(1);
	SetIntLight(75);
	SetLocate("Annufam");
	SetIntShort("la tienda de alimentación de Annufam");
	SetIntLong("Has entrado a la tienda de alimentos de la ciudad. Un "
				"tendero enano regenta el comercio. Por doquier ves estantes "
				"con diferentes productos para llevar: Desde botellas hasta "
				"fruta, pasando por carnes y pescados.\n");

	AddDetail(({"pared","paredes"}), "Son paredes muy vulgares y llenas de estanterías.\n");

	AddDetail(({"estantes","estanterias","estanteria","estante","estantería"}),
				"Son unos estantes de madera con todo el género de la tienda. "
				"Escribe lista para saber qué contienen.\n");

	SetShopkeeper(PNJ_CIUDAD_ANNUFAM("loinus"));
	SetIntSmell("Una mezcla de olores se juntan en tu olfato debido a la "
				"gran variedad de género.\n");
	AddExit("sur",HAB_UNGRIM_ANNUFAM("ungrim_01"));
	RemoveExit("almacen");
	SetNotifyExits("sur");
	SetLastDest(HAB_UNGRIM_ANNUFAM("ungrim_01"));
	AddDoor("sur", "la puerta de la calle", "Es la puerta que da a la calle.\n",
		({"puerta de la calle", "puerta del sur", "puerta"}),
		([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
		P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
		P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));

	//Ahora el género de la tienda.
	AddArticle(COMIDA_ANNUFAM("t_alimentacion/manzana"),REFRESH_REMOVE,4);
	AddArticle(COMIDA_ANNUFAM("t_alimentacion/naranja"),REFRESH_REMOVE,3);
	AddArticle(COMIDA_ANNUFAM("t_alimentacion/platano"),REFRESH_REMOVE,4);
	AddArticle(COMIDA_ANNUFAM("t_alimentacion/uvas"),REFRESH_REMOVE,2);
	AddArticle(COMIDA_ANNUFAM("t_alimentacion/lechuga"),REFRESH_REMOVE,4);
	AddArticle(COMIDA_ANNUFAM("t_alimentacion/cebolla"),REFRESH_REMOVE,3);
	AddArticle(COMIDA_ANNUFAM("t_alimentacion/pepino"),REFRESH_REMOVE,3);
	AddArticle(COMIDA_ANNUFAM("t_alimentacion/tomate"),REFRESH_REMOVE,5);
	AddArticle(COMIDA_ANNUFAM("t_alimentacion/jabali"),REFRESH_REMOVE,3);
	AddArticle(COMIDA_ANNUFAM("t_alimentacion/cordero"),REFRESH_REMOVE,4);
	AddArticle(COMIDA_ANNUFAM("t_alimentacion/besugo"),REFRESH_REMOVE,2);
	AddArticle(COMIDA_ANNUFAM("t_alimentacion/merluza"),REFRESH_REMOVE,3);
	AddArticle(BEB_ANNUFAM("ciudad/botella_cerveza"),REFRESH_REMOVE,3);
	AddArticle(BEB_ANNUFAM("ciudad/botella_vino"),REFRESH_REMOVE,2);
	AddArticle(BEB_ANNUFAM("ciudad/botella_agua"),REFRESH_REMOVE,3);
}
