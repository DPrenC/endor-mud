/**************************************************************************
fichero: minas24.c
Autor: Riberales
Creaci�n: 31/10/05
Descripci�n: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("un t�nel");
    SetIntLong("Te hallas por las minas enanas. Desde hace tiempo, la "
               "�nica compa�era de fatigas es tu sombra, y s�lo cuando hay "
               "antorchas que produzcan su presencia. �ste es un ejemplo, "
               "pues un par de ellas dan luminosidad a esta curva del t�nel, "
               "que se extiende en direcci�n este y sur.\n");

    AddDetail("sombra","Observas tu silueta estampada contra la roca de las "
              "paredes\n");

    DetalleAntorchas();
    DetalleParedes();

    AddExit("sur",HAB_PRIMERA_MINAS("minas25"));
    AddExit("este",HAB_PRIMERA_MINAS("minas23"));
    AddGuardia();
}

