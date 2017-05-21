/**************************************************************************
fichero: minas19.c
Autor: Riberales
Creaci�n: 2/1/06
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"
#include <materials.h>


inherit HAB_TERCERA_MINAS("tercera_base");

        create()
{
    ::create();

    SetIntShort("las minas enanas de Kha-annu");
    SetIntLong("Te encuentras internado en lo m�s profundo de las minas de "
               "Kha-annu, rodeado de roca, roca y m�s roca. En una de estas "
               "rocas observas algo brillante, que podr�a ser mineral sin "
               "extraer. El camino contin�a al noroeste y al sur, donde unas "
               "antorchas iluminan el lugar.\n");


    SetTipo(M_MITHRIL);
    DetalleVeta();

    AddDetail(({"brillo","brillante"}),
                "Parece que es resto de oro sin extraer.\n");

    AddExit("noroeste",HAB_TERCERA_MINAS("minas20"));
    AddExit("sur",HAB_TERCERA_MINAS("minas18"));
    AddGuardia();
}
