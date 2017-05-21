/**************************************************************************
fichero: minas15.c
Autor: Riberales
Creaci�n: 26/12/05
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("las galer�as de las minas enanas");
    SetIntLong("Te encuentras en el �ltimo nivel de estas minas de Kha-annu. "
               "Te da la impresi�n de que esta es la zona m�s h�meda de toda "
               "la mina, y el murmullo del agua te sigue acompa�ando, aunque "
               "con m�s intensidad. El t�nel sigue al noroeste y al "
               "nordeste.\n");

    DetalleParedes();


    AddExit("nordeste",HAB_TERCERA_MINAS("minas16"));
    AddExit("noroeste",HAB_TERCERA_MINAS("minas13"));
    AddGuardia();
    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
}

