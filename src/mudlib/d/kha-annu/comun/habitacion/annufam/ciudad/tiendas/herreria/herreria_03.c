/****************************************************************************
Fichero: herreria_03.c
Autor: Riberales
		[T] Tagoras
Creaci�n: 30/09/2005
Descripci�n: La parte de armaduras de la herrer�a.
[T] 06/03/2009: A�adidos los art�culos de protecci�n.
[T] 11/03/2009: A�ado puertas
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

    SetIntShort("la zona de venta de protecciones de la herrer�a de Annufam");
    SetLocate("annufam");
    SetIntLong("�sta es la zona donde podr�s adquirir las protecciones que "
               "usan en el Centro de Adiestramiento. Cuentan que estas "
               "protecciones son las m�s efectivas de Kha-annu, pero ya "
               "conoces las leyendas de los enanos. Hay un mostrador con "
               "unos papeles encima.\n");

    AddDetail("suelo",
            "Hay peque�os trozos de hierro y acero, debidos a la forja de "
            "la herrer�a. No estar�a mal que barriesen de vez en cuando.\n");

    AddDetail("mostrador",
            "Ves un mostrador met�lico donde el enano responsable de las "
            "armaduras deja sus anotaciones. Hay unos papeles encima.\n");


    AddDetail(({"papel de mostrador","papeles de mostrador",
            "nota de mostrador"}),
            "Es una nota donde Fagan apunta los pedidos. Mejor ser� que la leas.\n");


    AddReadMsg(({"nota de mostrador","papel de mostrador",
                 "papeles de mostrador"}),
               W("*** Pedidos de armaduras. ***\n"
                 "Corte de belthain:\n"
                 "5 escudos.\n"
                 "3 corazas.\n"
                 "6 cascos.\n\n"
                 "Centro De Adiestramiento:\n"
                 "10 corazas.\n"
                 "7 cascos.\n"
                 "8 escudos.\n"
                 "6 sandalias.\n\n***                       ***\n"));


    SetShopkeeper(PNJ_CIUDAD_ANNUFAM("fagan"));
    SetIndoors(1);
    SetIntLight(75);
    SetIntSmell(W("Apenas puedes percibir nada con la congesti�n debida a las "
                  "altas temperaturas de la herrer�a.\n"));
    SetIntNoise(SF(cmd_escuchar));
    AddExit("sur",HAB_HERRERIA_ANNUFAM("herreria_04"));
    AddExit("oeste",HAB_HERRERIA_ANNUFAM("herreria_02"));
    AddExit("suroeste",HAB_HERRERIA_ANNUFAM("herreria_01"));
	SetCloseTime(S_CLOSED_AT_NIGHT);
    SetMainRoom(HAB_HERRERIA_ANNUFAM("herreria_01"));
    SetLastDest(HAB_UNGRIM_ANNUFAM("ungrim_08"));

	AddArticle(PROT_CENTRO_ANNUFAM("casco_guerrero"), REFRESH_REMOVE, 1+random(3));
	AddArticle(PROT_CENTRO_ANNUFAM("coraza_guerreros"), REFRESH_REMOVE, 1+random(3));
	AddArticle(PROT_CENTRO_ANNUFAM("escudo"), REFRESH_REMOVE, 1+random(3));
	AddArticle(PROT_CENTRO_ANNUFAM("sandalias_soldados"), REFRESH_REMOVE, 1+random(3));
	AddArticle(PROT_CENTRO_ANNUFAM("uniforme_soldados"), REFRESH_REMOVE, 1+random(3));
}

int QueryHerreria_03()
{
    return 1;
}

string cmd_escuchar()
{
    object herrero;
    if ((herrero = present("maestro_herrero",to_object(HAB_HERRERIA_ANNUFAM
        ("herreria_04")))) && living(herrero))
    {
        return "Escuchas el golpeteo de algo met�lico en direcci�n sur.\n";
    }
	return "Extra�amente no escuchas nada.\n";
}
