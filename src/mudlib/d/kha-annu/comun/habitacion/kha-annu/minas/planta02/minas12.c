/**************************************************************************
fichero: minas12.c
Autor: Riberales
Creaci�n: 11/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("un cruce de galer�as");
    SetIntLong("Has ido a parar a uno de los innumerables cruces de t�neles y "
               "galer�as que hay por toda la mina. En esta ocasi�n, observas "
               "tres claros caminos, gracias a las antorchas que descansan en "
               "la roca de la pared. Uno hacia el norte, otro hacia el "
               "suroeste y el tercero y m�s ancho, hacia el este.\n");

    DetalleAntorchas();
    DetalleParedes();

    AddExit("norte",HAB_SEGUNDA_MINAS("minas07"));
    AddExit("suroeste",HAB_SEGUNDA_MINAS("minas11"));
    AddExit("este",HAB_SEGUNDA_MINAS("minas13"));
    AddGuardia();
}
