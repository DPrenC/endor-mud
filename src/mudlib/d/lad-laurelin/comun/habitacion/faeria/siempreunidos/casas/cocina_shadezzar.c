/***
Fichero: cocina_shadezar.c
autor: kastwey@simauria
Descripci�n: La cocina de la casa de Shadezzar.
Creaci�n: 07/12/2004
***/

#include "path.h"
#include <moving.h>
#include <properties.h>

inherit STD_FAERIA("hab_siempreunidos");

create()
{
    object especia, mueble;
    ::create();
    SetIntShort("una cocina");
    SetIntLong(W("Te encuentras en la cocina de la casa de Shadezzar.\n"
    "Es una peque�a estancia que �nicamente contiene lo indispensable para cocinar: un peque�o fog�n y unos cuantos cacharros. Adem�s, puedes ver un mueble repleto de hierbas y especias.\n"));
    SetOficina(HAB_PUESTO("casas/casa_shadezzar"));
    SetIndoors(1);
    SetIntBright(25);
    AddDetail(({"fog�n", "fogon", "fuego"}), "Es un peque�o fuego de le�a que sirve para cocinar.\n");
    AddDetail(({"cacharros", "sarten", "olla", "cuchar�n", "cucharon"}), "Son cacharros de los que se pueden encontrar en una cocina. Aunque est�n algo oxidados, todab�a pueden servir perfectamente.\n");
    AddItem("/obj/chest", REFRESH_HOME, ([
    P_SHORT:"un mueble",
    P_LONG:"Es un mueble para guardar especias.\n",
    P_SIZE:P_SIZE_LARGE,
    P_IDS:({"armario", "armarito", "mueble"}),
    P_NOTAKE:1,
    P_NOGET:1]), 1);
    if (mueble = present("mueble", TO))
    {
    	especia = clone_object("/obj/herb");
        especia->SetShort("un poco de tomillo");
        especia->SetLong("Es una especia para dar m�s sabor a las comidas.\n");
        especia->SetIds(({"tomillo"}));
        especia->SetClass("saciante");
        especia->SetValue(200);
        especia->move(mueble);
        especia = clone_object("/obj/herb");
        especia->SetShort("un poco de or�gano");
        especia->SetLong("Es un poco de or�gano");
        especia->SetIds(({"oregano", "or�gano"}));
        especia->SetClass("saciante");
        especia->SetWeight(100);
        especia->SetValue(200);
        especia->move(mueble);
        especia = clone_object("/obj/herb");
        especia->SetShort("unas bolitas de pimienta negra");
        especia->SetLong("Son algunas bolitas de pimienta negra.\n");
        especia->SetClass("saciante");
        especia->SetIds(({"pimienta", "pimienta negra", "bolitas de pimienta"}));
        especia->SetWeight(50);
        especia->SetValue(200);
        especia->move(mueble);
    }
    AddExit("oeste", HAB_PUESTO("casas/casa_shadezzar"));
}
