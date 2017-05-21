/**************************************************************************
fichero: minas12.c
Autor: Riberales
Creaci�n: 26/12/05
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("el coraz�n de las minas enanas");
    SetIntLong("Permaneces en lo m�s rec�ndito de estas minas enanas, y el "
               "aire cada vez est� m�s viciado, unido a una fuerte humedad. "
               "Te parece escuchar un extra�o murmullo a tus pies, aunque "
               "quiz� sea ya producto de tu estancia en estas oscuras "
               "galer�as.\n");

    DetalleParedes();

    SetIntNoise("Reconoces lo que parece um murmullo de agua justo a tus "
                "pies.\n");

    AddExit("norte",HAB_TERCERA_MINAS("minas11"));
    AddExit("sudeste",HAB_TERCERA_MINAS("minas13"));
    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT);
}

