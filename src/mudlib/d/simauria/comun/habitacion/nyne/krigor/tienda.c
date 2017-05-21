/****************************************************************************
Fichero: tienda.c
Autor: Ratwor
Fecha: 02/06/2007
Descripción: La tienda de Krigor. Totalmente reformada.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <combat.h>
#include <materials.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>

inherit SHOP;

object art1, art2, art3, art4;

create()
{
	::create();
	SetIntShort("la tienda de Kluer");
	SetIntLong("Esta es la pequeña tienda de Krigor, donde se pueden encontrar "
	    "artículos sencillos y cotidianos, pero no por ello menos importantes.\n La "
	    "regenta el humano Kluer desde hace muchos años, pues él es de los más "
	    "antiguos del lugar.\n");
    SetIntBright(35);
	   SetIntSmell("Huele a distintas cosas, pero nada en concreto.\n");
	SetShopkeeper(PNJKRIG("kluer"));

    RemoveExit("almacen");
	AddExit("norte",KRIGOR("plaza"));
    AddDoor("norte", "la puerta de la calle",
    "Es la puerta de salida que da a la plaza de Krigor.\n",
    ({"puerta", "puerta de salida", "puerta del norte"}),
    ([P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"), P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    SetLastDest("./plaza");
    SetNotifyExits("norte");

	art1=clone_object("/std/weapon");
	art1->SetStandard(WT_CUCHILLO, 3, P_SIZE_MEDIUM, M_ACERO);
	art1->SetShort("un cuchillo de cocina");
	art1->SetLong("Un cuchillo de cocina con empuñadura de madera.\n");

	art2=clone_object("/std/weapon");
	art2->SetStandard(WT_HACHA,8 , P_SIZE_LARGE, M_ACERO);
	art2->SetShort("un hacha de leñador");
	art2->SetLong("Una enorme hacha de leñador. Podría ser de algún troll por el "
	    "tamaño.\n  Está bien afilada e intuyes que no sólo se puede cortar árboles con "
	    "ella.\n");

	art3=clone_object("/std/weapon");
	art3->SetStandard(WT_MAZA, 6, P_SIZE_MEDIUM, M_MADERA);
	art3->SetShort("una maza de madera");
	art3->SetLong("Una maza de madera, útil para clavar clavos.\n");

	art4=clone_object("std/armour");
	art4->SetStandard(AT_TUNICA, 0, P_SIZE_GENERIC, M_TELA);
	art4->SetShort("una blusa de mujer");
	art4->SetLong("Una bonita blusa blanca típica de la región de Nyne, que suelen llevar "
	    "las pastoras.\n");
	    art4->SetValue(700);
	art4->AddId(({"una blusa de mujer","blusa"}));

	AddArticle(OTRO("cuerda"), REFRESH_REMOVE,1);
	AddArticle("/obj/torch", REFRESH_REMOVE, d3(2));
	AddArticle("/obj/oil_bottle",REFRESH_REMOVE,d3());
	AddArticle("/obj/lighter", REFRESH_REMOVE, d2());
	AddArticle(art1, REFRESH_REMOVE, 1);
	AddArticle(art2, REFRESH_REMOVE,1);
	AddArticle(art3, REFRESH_REMOVE, 1);
	AddArticle(art4, REFRESH_REMOVE, 1);
	AddArticle(PROT("amuleto"), REFRESH_REMOVE, 1);
	AddArticle(ARMA("vara"));
	AddArticle(ARMA("arma_rnd"),REFRESH_REMOVE,2);
	AddArticle(PROT("anillo"));
	AddArticle(PROT("guantes"), REFRESH_REMOVE, 1);
    AddArticle("/obj/candle", REFRESH_REMOVE,d4());
	SetLocate("Krigor");
}
