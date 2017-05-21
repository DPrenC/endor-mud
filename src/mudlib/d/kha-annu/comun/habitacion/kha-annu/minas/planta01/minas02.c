/**************************************************************************
fichero: minas02.c
Autor: Riberales
Creación: 22/10/05
Descripción: Room en primera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();
    SetIntShort("las minas enanas");
    SetIntLong("Estás en las minas enanas. Tanto en la pared "
               "norte como en la sur observas un par de antorchas que permiten"
               " dar un poco de luz al lugar. La galería continúa de este a "
               "oeste.\n");

    DetalleParedes();
    DetalleAntorchas();


    AddExit("oeste",HAB_PRIMERA_MINAS("minas03"));
    AddExit("este",HAB_PRIMERA_MINAS("minas01"));
    AddGuardia();
}
