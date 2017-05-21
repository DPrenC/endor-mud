/****************************************************************************
Fichero: herreria_02.c
Autor: Riberales
		[T] Tagoras
Creaci�n: 29/09/2005
Descripci�n: La parte de armas de la herrer�a.
[T] 06/03/2009 A�adidaas las armas del centro
[T] 11/03/2009 A�ado puertas
****************************************************************************/

#include "./path.h"
//#include <door.h>
#include <properties.h>
#include <materials.h>
#include <scheduler.h>

inherit SHOP;

string cmd_escuchar();

public void create()
{
    ::create();

    SetIntShort("la zona de venta de armas, en la herrer�a");
    SetLocate("Annufam");
	SetIntLong("Esta es la zona dedicada a la venta de armas de la herrer�a "
               "de Annufam. Desde aqu� se distribuyen todas las hachas y el "
               "resto de armas con las que trabajan y entrenan los enanos "
               "del Centro.\n");

    AddDetail("suelo",
            "Hay peque�os trozos de hierro y acero, debidos a la forja de "
            "la herrer�a. No estar�a mal que barriesen de vez en "
            "cuando.\n");

    SetShopkeeper(PNJ_CIUDAD_ANNUFAM("elearca"));
    SetIndoors(1);
    SetIntLight(75);
    SetIntSmell("El aire es irrespirable, a causa del calor de la forja.\n");
    SetIntNoise(SF(cmd_escuchar));
    AddExit("sur",HAB_HERRERIA_ANNUFAM("herreria_01"));
    AddExit("este",HAB_HERRERIA_ANNUFAM("herreria_03"));
    AddExit("sudeste",HAB_HERRERIA_ANNUFAM("herreria_04"));
	SetCloseTime(S_CLOSED_AT_NIGHT);
	SetMainRoom(HAB_HERRERIA_ANNUFAM("herreria_01"));
	SetLastDest(HAB_UNGRIM_ANNUFAM("ungrim_08"));

	AddArticle(ARMA_CENTRO_ANNUFAM("alabarda"), REFRESH_REMOVE, 1+random(3));
	AddArticle(ARMA_CENTRO_ANNUFAM("cadena"), REFRESH_REMOVE, 1+random(3));
	AddArticle(ARMA_CENTRO_ANNUFAM("daga"), REFRESH_REMOVE, 1+random(3));
	AddArticle(ARMA_CENTRO_ANNUFAM("espada"), REFRESH_REMOVE, 1+random(3));
	AddArticle(ARMA_CENTRO_ANNUFAM("florete"), REFRESH_REMOVE, 1+random(3));
	AddArticle(ARMA_CENTRO_ANNUFAM("hacha_guerreros"), REFRESH_REMOVE, 1+random(3));
	AddArticle(ARMA_CENTRO_ANNUFAM("lanza"), REFRESH_REMOVE, 1+random(3));
	AddArticle(ARMA_CENTRO_ANNUFAM("latigo"), REFRESH_REMOVE, 1+random(3));
	AddArticle(ARMA_CENTRO_ANNUFAM("mangual"), REFRESH_REMOVE, 1+random(3));
	AddArticle(ARMA_CENTRO_ANNUFAM("manopla"), REFRESH_REMOVE, 1+random(3));
	AddArticle(ARMA_CENTRO_ANNUFAM("maza"), REFRESH_REMOVE, 1+random(3));
	AddArticle(ARMA_CENTRO_ANNUFAM("sable"), REFRESH_REMOVE, 1+random(3));
	AddArticle(ARMA_CENTRO_ANNUFAM("vara"), REFRESH_REMOVE, 1+random(3));
}

string cmd_escuchar()
{
    object herrero;
    if ((herrero = present("maestro_herrero",to_object(HAB_HERRERIA_ANNUFAM("herreria_04")))) && living(herrero))
    {
        return "Escuchas el golpeteo de algo met�lico en direcci�n sudeste.\n";
    }

	return "Extra�amente no escuchas nada.\n";
}
