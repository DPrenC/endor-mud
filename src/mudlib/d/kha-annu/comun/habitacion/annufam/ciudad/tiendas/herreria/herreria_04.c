/****************************************************************************
Fichero: herreria_04.c
Autor: Riberales
		[T] Tagoras
Creación: 30/09/2005
Descripción: La herrería propiamente dicha.
[T] 11/03/2009: Añado puerta.
****************************************************************************/

#include "./path.h"
#include <door.h>
#include <properties.h>
#include <materials.h>
#include <scheduler.h>

inherit SMITHY;

string cmd_escuchar();
int ir_este();

public void create()
{
    ::create();

    CanSell(0);
    SetIntShort("la herreria de Annufam");
    SetLocate("annufam");
    SetIntLong("Has llegado a la zona de la herrería donde el calor es más "
               "insoportable. Esta es la parte destinada a crear, eliminar, "
               "modificar y arreglar las armas y armaduras. En el centro de "
               "la estancia observas un yunque, y la pared este está "
               "ocupada por el gran horno de fundición y una puerta que da "
               "a las cuadras de la ciudad.\n");

    AddDetail("suelo",
            "Hay pequeños trozos de hierro y acero, debidos a la forja de "
            "la herrería. No estaría mal que barriesen de vey en "
            "cuando.\n");

    AddDetail(({"horno","horno de fundición","horno de fundicion"}),
              "Es un hueco donde ves fuego encendido. Ahí introduce el "
              "herrero las piezas de hierro para fundirlas y poder "
              "modelarlas.\n");

    AddDetail(({"fuego","fuego de horno"}), "Al mirar al fuego comienzan a llorarte los ojos.\n");

    AddDetail("yunque",
            "Es una pieza de hierro de forma cuadrada pero que se estrecha "
            "en la mitad de la misma. Sirve para enderezar armas y "
            "armaduras, entre otras cosas.\n");

    AddDetail("puerta",
            "Es una sencilla puerta, forrada de un material ignífugo, "
            "y que comunica la herrería con la cuadra de Annufam.\n");

    AddReadMsg("nota",
             "Aquí podrás reparar, arreglar y modificar armas y armaduras, "
             "así como valorar cuánto te costará hacerlo.\n");

    SetShopkeeper(PNJ_CIUDAD_ANNUFAM("foifur"));
    SetIndoors(1);
    SetIntLight(80);
    SetIntSmell(W("Ni se te ocurra intentar inspirar más de lo que toca, "
                  "podría ser tu fin.\n"));
    SetIntNoise(SF(cmd_escuchar));
    AddExit("oeste",HAB_HERRERIA_ANNUFAM("herreria_01"));
    AddExit("noroeste",HAB_HERRERIA_ANNUFAM("herreria_02"));
    AddExit("norte",HAB_HERRERIA_ANNUFAM("herreria_03"));
    AddExit("este",SF(ir_este));
    RemoveExit("almacen");
	SetCloseTime(S_CLOSED_AT_NIGHT);
    SetMainRoom(HAB_HERRERIA_ANNUFAM("herreria_01"));
    SetLastDest(HAB_UNGRIM_ANNUFAM("ungrim_08"));
}

public int do_list(string str)
{
    if (QueryShopkeeper())
    {
        return  notify_fail(W("El herrero dice: "+ CAP(TNAME)+ ", aquí no se "
                              "comercia. Para eso, ve a la zona de compra-"
                              "venta que hay al norte de la herrería.\n"),
                NOTIFY_NOT_VALID);
    }
}

int ir_este()
{
    return notify_fail("La puerta está cerrada con llave. No puedes pasar.\n");
}

string cmd_escuchar()
{
    if (QueryShopkeeper())
    {
        return "Escuchas el crepitar del fuego en el horno, y los golpes "
               "intermitentes del herrero contra el yunque.\n";
    }
    return "Escuchas el crepitar del fuego.\n";
}
