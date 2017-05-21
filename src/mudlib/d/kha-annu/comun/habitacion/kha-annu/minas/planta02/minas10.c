/**************************************************************************
fichero: minas10.c
Autor: Riberales
Creación: 9/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"
#include <moving.h>
#include <materials.h>

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un recodo de las minas");
    SetIntLong("Estás en un tramo de la mina donde se produce un pronunciado "
               "cambio en dirección sudeste, por lo que, sumado al bajo techo,"
               " te hace pensar que esta parte ha sido abierta sin mucha "
               "contemplación, y que puede que los enanos hayan pasado por "
               "alto algún cúmulo de mineral en la roca de las paredes.\n");


    SetTipo(M_PLATA);
    DetalleVeta();

    AddExit("norte",HAB_SEGUNDA_MINAS("minas09"));
    AddExit("sudeste",HAB_SEGUNDA_MINAS("minas11"));
    AddGuardia();
}

public void notify_enter (mixed from, int method, mixed extra)
{
    ::notify_enter(from,method,extra);
    if (!PO || method != M_GO || extra != "sur" || PO->querySize()<2) return ;
    tell_object(PO,"Caminas con cuidado de no pegarte contra el techo.\n");
    return ;
}

