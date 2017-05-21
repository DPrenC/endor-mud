/**************************************************************************
fichero: minas12.c
Autor: Riberales
Creación: 11/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un cruce de galerías");
    SetIntLong("Has ido a parar a uno de los innumerables cruces de túneles y "
               "galerías que hay por toda la mina. En esta ocasión, observas "
               "tres claros caminos, gracias a las antorchas que descansan en "
               "la roca de la pared. Uno hacia el norte, otro hacia el "
               "suroeste y el tercero y más ancho, hacia el este.\n");

    DetalleAntorchas();
    DetalleParedes();

    AddExit("norte",HAB_SEGUNDA_MINAS("minas07"));
    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas11"));
    AddExit("este",HAB_SEGUNDA_MINAS("minas13"));
    AddGuardia();
}
