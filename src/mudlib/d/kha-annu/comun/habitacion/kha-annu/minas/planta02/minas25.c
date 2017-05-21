/**************************************************************************
fichero: minas25.c
Autor: Riberales
Creación: 11/11/05
Descripción: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"


inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("la segunda planta de las minas");
    SetIntLong("Te encuentras en el segundo nivel de las minas enanas de Kha-"
               "Annu, en una de sus galerías. Observas que aquí hay una "
               "escalerilla que asciende al piso superior. La galería sigue "
               "en dirección noroeste y sur.\n");


    DetalleParedes();

    AddDetail(({"escalera","escalerilla"}),
                "Es una pequeña escalera metálica que comunica este nivel con "
                "el superior.\n");

    AddDetail(({"hueco","agujero"}),
                "Es un agujero hecho en la piedra, que comunica este nivel "
                "con el de arriba.\n");

    AddExit("noroeste",HAB_SEGUNDA_MINAS("minas26"));
    AddExit("sur",HAB_SEGUNDA_MINAS("minas24"));
    AddExit("arriba",HAB_PRIMERA_MINAS("minas04"));
    AddGuardia();
}
