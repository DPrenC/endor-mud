/**************************************************************************
fichero: minas03.c
Autor: Riberales
Creaci�n: 21/12/05
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");



create()
{
    ::create();

    SetIntShort("las minas de Kha-annu");
    SetIntLong("Te encuentras en un cruce de galer�as. Un par de antorchas "
               "colocadas en las rocas del norte te permiten observar un "
               "t�nel al sur, otro al noroeste, y un tercero m�s angosto al "
               "suroeste. Parece que esta es una zona donde a�n queda "
               "mineral.\n");

    DetalleParedes();
    DetalleAntorchas();
    AddItem(OTRO_MINAS("carretilla_vacia"));


    AddExit("sur",HAB_TERCERA_MINAS("minas02"));
    AddExit("suroeste",HAB_TERCERA_MINAS("minas04"));
    AddExit("noroeste",HAB_TERCERA_MINAS("minas05"));

    AddGuardia();
    AddItem(PNJ_MINAS("kender_minero"),REFRESH_DESTRUCT);
}

