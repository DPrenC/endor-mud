/**************************************************************************
fichero: minas16.c
Autor: Riberales
Creaci�n: 27/12/05
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("una bifurcaci�n de t�neles");
    SetIntLong("Has llegado a otro de los cruces de galer�as y t�neles de las "
               "minas. El camino principal discurre de nordeste a suroeste, "
               "mientras que observas un desv�o en direcci�n noroeste. El "
               "murmullo del agua sigue presente en el lugar, y el fr�o y "
               "humedad del mismo tambi�n.\n");

    DetalleParedes();

    SetIntNoise("Reconoces lo que parece um murmullo de agua justo a tus "
                "pies.\n");


    AddExit("suroeste",HAB_TERCERA_MINAS("minas15"));
    AddExit("noroeste",HAB_TERCERA_MINAS("minas14"));
    AddExit("nordeste",HAB_TERCERA_MINAS("minas17"));
    AddGuardia();
}

