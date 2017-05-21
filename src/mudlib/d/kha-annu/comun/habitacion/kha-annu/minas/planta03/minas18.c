/**************************************************************************
fichero: minas18.c
Autor: Riberales
Creación: 27/12/05
Descripción: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"



inherit HAB_TERCERA_MINAS("tercera_base");

        create()
{
    ::create();

    SetIntShort("una revuelta de las minas");
    SetIntLong("Vagas por el interior de las minas de Kha-annu, en su nivel "
               "inferior. Dos antorchas descansan en la roca de la pared y "
               "te ofrecen un poco de luz tras tanta galería en penumbra. La "
               "galería sigue al norte y al suroeste.\n");

    DetalleParedes();
    DetalleAntorchas();

    AddExit("norte",HAB_TERCERA_MINAS("minas19"));
    AddExit("suroeste",HAB_TERCERA_MINAS("minas17"));
    AddGuardia();

}


