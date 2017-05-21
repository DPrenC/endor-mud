/**************************************************************************
fichero: minas21.c
Autor: Riberales
Creaci�n: 2/1/06
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"


inherit HAB_TERCERA_MINAS("tercera_base");

        create()
{
    ::create();

    SetIntShort("un cruce de galer�as");
    SetIntLong("Has llegado a otro de los miles de cruces de t�neles y "
               "galer�as que hay en estas minas enanas. Observas unas "
               "antorchas incrustadas en la roca para darle un poco de "
               "claridad al lugar. La galer�a que se dirige al nordeste "
               "parece ser bastante transitada, pues el suelo se ve m�s "
               "gastado, al igual que la del suroeste. Sin embargo, la que va "
               "al sudeste parece ser m�s virgen.\n");

    DetalleParedes();
    DetalleAntorchas();


    AddExit("nordeste",HAB_TERCERA_MINAS("minas22"));
    AddExit("sudeste",HAB_TERCERA_MINAS("minas20"));
    AddExit("suroeste",HAB_TERCERA_MINAS("minas02"));

    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT);
}



