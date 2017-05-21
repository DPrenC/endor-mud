/**************************************************************************
fichero: minas16.c
Autor: Riberales
Creación: 27/12/05
Descripción: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("una bifurcación de túneles");
    SetIntLong("Has llegado a otro de los cruces de galerías y túneles de las "
               "minas. El camino principal discurre de nordeste a suroeste, "
               "mientras que observas un desvío en dirección noroeste. El "
               "murmullo del agua sigue presente en el lugar, y el frío y "
               "humedad del mismo también.\n");

    DetalleParedes();

    SetIntNoise("Reconoces lo que parece um murmullo de agua justo a tus "
                "pies.\n");


    AddExit("suroeste",HAB_TERCERA_MINAS("minas15"));
    AddExit("noroeste",HAB_TERCERA_MINAS("minas14"));
    AddExit("nordeste",HAB_TERCERA_MINAS("minas17"));
    AddGuardia();
}

