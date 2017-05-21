/****************************************************************************
Fichero: tienda.c
Autor: Kastwey
       [T] Tagoras
Creación: 22/08/2005
Descripción: Tienda de Annufam
[T] 09/03/2009: Bajo el SetIntBright de 75 a 30.
                Pongo los articulos un random(3).
                Añado olor.
				Quito la salida al almacen.
				Añado puerta y todo lo que conlleva.
****************************************************************************/

#include "./path.h"
#include <materials.h>
#include <properties.h>
#include <sounds.h>
#include <door.h>
#include <scheduler.h>
#include <combat.h>

inherit SHOP;

public void create()
{
    ::create();

    SetIntBright(30);
	SetLocate("Annufam");
    SetIntShort("la tienda de Gemin");
    SetIntLong("Has entrado a la tienda de ropa de la ciudad. Aquí todos "
               "los tenderos y los residentes del centro de entrenamiento "
               "compran para cuando tienen que salir de Annufam. Podrás "
               "comprar y vender cosas, siempre que Gemin, la enana que "
               "lleva la tienda, acepte tu producto.\n");
    SetShopkeeper(PNJ_CIUDAD_ANNUFAM("gemin"));
	SetIntSmell("Huele a tinte para tela.\n");


    AddArticle(PROT("bota_monta"),REFRESH_REMOVE,1+random(3));

    AddArticle(ARMOUR,REFRESH_REMOVE,
               ([P_SHORT:"una camisa de tela",
                 P_LONG:W("Es una camisa típica de los enanos. Es de "
                          "un color marrón verdoso, imitando la "
                          "naturaleza.\n"),
                 P_ARMOUR_TYPE:AT_CORAZA,
                 P_MATERIAL:M_TELA,
                 P_AC:1,
                 P_IDS:({"camisa","camisa de tela"}),
                 P_GENDER:GENDER_FEMALE,
                 P_NUMBER:NUMBER_SINGULAR,
                 P_VALUE:1000,
                 P_SIZE:P_SIZE_NORMAL]),1+random(3));

    AddArticle(ARMOUR,REFRESH_REMOVE,
               ([P_SHORT:"unos pantalones",
                 P_LONG:W("Son unos graciosos pantalones color marrón "
                   "verdoso y con un par de bolsillos para guardar algo en "
                   "ellos.\n"),
                 P_ARMOUR_TYPE:AT_PANTALONES,
                 P_AC:1,
                 P_MATERIAL:M_TELA,
                 P_IDS:({"pantalon","pantalón","pantalones",
                         "pantalon de tela","pantalones de tela",
                         "pantalón de tela"}),
                 P_VALUE:1300,
                 P_GENDER:GENDER_MALE,
                 P_NUMBER:NUMBER_PLURAL,
                 P_SIZE:P_SIZE_NORMAL]),1+random(3));

    AddArticle(ARMOUR,REFRESH_REMOVE,
               ([P_SHORT:"un cinturón de oro",
                 P_LONG:W("Es un precioso cinturón que servirá para "
                   "sujetarte mejor los pantalones. Hecho con remaches de "
                   "oro, seguro será la envidia de amigos y conocidos.\n"),
                 P_IDS:({"cinturon","cinturón","cinturon de oro","cinturón "
                         "de oro"}),
                 P_ARMOUR_TYPE:AT_ANILLO,
                 P_AC:0,
                 P_MATERIAL:M_ORO,
                 P_GENDER:GENDER_MALE,
                 P_NUMBER:NUMBER_SINGULAR,
                 P_VALUE:8000,
                 P_SIZE:P_SIZE_NORMAL]),1+random(3));

    AddExit("sur", HAB_UNGRIM_ANNUFAM("ungrim_03"));
	RemoveExit("almacen");
	SetNotifyExits("sur");
	SetLastDest(HAB_UNGRIM_ANNUFAM("ungrim_03"));
	AddDoor("sur", "la puerta de la calle", "Es la puerta que da a la calle\n",
		({"puerta de la calle", "puerta del sur", "puerta"}),
		([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
		P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
		P_DOOR_CLOSE_TIME: S_CLOSED_AT_NIGHT]));
}
