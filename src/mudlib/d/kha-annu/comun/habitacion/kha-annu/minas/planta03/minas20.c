/**************************************************************************
fichero: minas20.c
Autor: Riberales
Creaci�n: 2/1/06
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"


inherit HAB_TERCERA_MINAS("tercera_base");

        create()
{
    ::create();

    SetIntShort("el transcurso de una galer�a");
    SetIntLong("Te encuentras dentro de una galer�a en la tercera planta de "
               "las minas enanas de Kha-annu. Hay un par de antorchas "
               "dispuestas en la pared, mas debido a la humedad del lugar, "
               "est�n apagadas. Observas otras al noroeste, en lo que te "
               "parece un cruce de t�neles.\n");

    DetalleParedes();
    AddDetail(({"antorcha","antorchas"}),
                "Son unas antorchas que sirven para dar luz al lugar, pero "
                "debido a la humedad de la zona, est�n apagadas.\n");




    AddExit("noroeste",HAB_TERCERA_MINAS("minas21"));
    AddExit("nordeste",HAB_TERCERA_MINAS("minas23"));
    AddExit("sudeste",HAB_TERCERA_MINAS("minas19"));
    AddGuardia();
    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
}
