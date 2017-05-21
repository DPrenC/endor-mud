/*
DESCRIPCION : Habitación de la posada de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/posada/lobomar/habitacion01.c
MODIFICACION:
07-12-05 [Riberales] Creacion
16-09-07 [Angor] Movido gran parte del codigo comun a la habitacion base
*/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <lock.h>

inherit AZ_POSADA("lobomar/habitacion_base");

public create()
{
    object ob, cofre;
    ::create();

    AddDetail(({"cuadro","pintura"}),
    "El cuadro representa la salida de un gran barco desde el puerto de Azzor, "
    "con una multitud de orcos en los muelles.\n");

    AddItem("/obj/chest",REFRESH_REMOVE,([
            P_SHORT: "un cofre",
            P_LONG: "Es un cofre de tamaño medio, donde los individuos que "
                    "alquilan la habitación pueden dejar sus pertenencias más "
                    "valiosas.\n",
            P_INT_SHORT: "un cofre",
            P_INT_LONG: "en un cofre",
            P_IDS: ({"cofre","mueble"}),
            P_SIZE: P_SIZE_MEDIUM,
            P_NOGET: 1]));

    if (cofre = (present("cofre")))
    {
        cofre->SetLockState(LOCK_OPEN);
        ob = clone_object("/obj/money");
        ob->AdjustMoney((["oro":5+random(2),
                          "plata":7+random(5),
                          "cobre":10+random(3)]));
        ob->move(cofre);
        ob = clone_object("/obj/torch");
        ob->move(cofre);
        cofre->SetLockState(LOCK_CLOSED);
    }

    AddExit("este",AZ_POSADA("lobomar/descansillo"));
}




