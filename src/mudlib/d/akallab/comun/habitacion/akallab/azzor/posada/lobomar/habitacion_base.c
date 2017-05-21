/*
DESCRIPCION : Habitación base de posada de Azzor
FICHERO     : /d/akallab/comun/habitacion/akallab/azzor/posada/lobomar/habitacion_base.c
MODIFICACION:
10-12-05 [Riberales] Creacion
16-09-07 [Angor] Descripcion cambiada. Movido gran parte del codigo comun de las 
         habitaciones a esta base
*/

#include "path.h"
#include <moving.h>

inherit ROOM;

public create()
{
    ::create();
    SetIntShort("una habitación de la posada");
    SetLocate("ciudad de Azzor");
    SetIntBright(45);
    SetIntLong(
    "Estas en una de las habitaciones de la posada, un dormitorio bastante "
    "sencillo con un camastro y un crujiente piso de madera. En la pared hay "
    "colgado un viejo cuadro.\n");

    AddDetail(({"cama","camastro"}),
                "Es un camastro hecho de paja y con sábanas recubriéndolo. No "
                "es que sea muy cómodo, pero se dormirá bien en él.\n");

}

public void notify_enter(mixed from, int method, mixed extra)
{

    if (!PO || method != M_GO) return ::notify_enter(from,method,extra);
    tell_room(environment(PO),"Se abre la puerta y "+ CAP(PO->QueryRealName())+
                 " entra, cerrando a sus espaldas.\n",({PO}));
    return ::notify_enter(from,method,extra);
}

public void notify_leave(mixed to,int method,mixed extra)
{
    if (!PO || method != M_GO) return ::notify_leave(to,method,extra);
    tell_object(PO,"Abres la puerta y sales de la habitación.\n");
    tell_room(TO,CAP(TNAME) + " abre la puerta y sale de la "
                 "habitación.\n",({PO}));
    return ::notify_leave(to,method,extra);
}
