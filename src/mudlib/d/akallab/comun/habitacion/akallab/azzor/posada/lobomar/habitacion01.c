/*
DESCRIPCION : Habitación de la posada de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/posada/lobomar/habitacion01.c
MODIFICACION:
07-12-05 [Riberales] Creacion
16-09-07 [Angor] Movido gran parte del codigo comun a la habitacion base
*/

#include "path.h"
#include <moving.h>
#include <properties.h>
#include <combat.h>
#include <lock.h>

inherit AZ_POSADA("lobomar/habitacion_base");

public create()
{
    object ob, armario;
    ::create();

    AddDetail(({"cuadro","pintura"}),
    "En la pintura observas un barco pesquero en mitad de una fuerte tempestad.\n");

    AddItem("/obj/chest",REFRESH_REMOVE,([
            P_SHORT: "un armario",
            P_LONG: "Es un armario bastante grande, donde los inquilinos de "
                    "las habitaciones dejan sus pertenencias.\n",
            P_INT_SHORT: "un armario",
            P_INT_LONG: "en un armario",
            P_IDS: ({"armario","mueble","gran armario"}),

            P_SIZE: P_SIZE_LARGE,
            P_NOGET: 1]));

    if (armario = (present("armario")))
    {
        armario->SetLockState(LOCK_OPEN);
        ob = clone_object(ARMOUR);
        ob->SetShort("unos pantalones");
        ob->SetLong("Son unos pantalones de tela bastante elásticos y que "
                    "que seguro serán  muy cómodos.\n");
        ob->SetIds(({"pantalones","pantalon","pantalón"}));
        ob->SetArmourType(AT_PANTALONES);
        ob->SetAC(3);
        ob->SetMaterial(M_TELA);
        ob->SetSize(P_SIZE_MEDIUM);
        ob->SetWeight(400);
        ob->move(armario);
        ob = clone_object(ARMOUR);
        ob->SetShort("una camisa de cuero");
        ob->SetLong("Es una elegante camisa de cuero negro, aunque Una de las "
                    "mangas tiene un corte.\n");
        ob->SetIds(({"camisa","camisa de cuero"}));
        ob->SetArmourType(AT_ARMOUR);
        ob->SetAC(3);
        ob->SetMaterial(M_CUERO);
        ob->SetSize(P_SIZE_MEDIUM);
        ob->SetWeight(630);
        ob->move(armario);
        armario->SetLockState(LOCK_CLOSED);
    }

    AddExit("sur",AZ_POSADA("lobomar/descansillo"));
}

