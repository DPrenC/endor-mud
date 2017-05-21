/**************************************************************************
fichero: minas01.c
Autor: Riberales
Creación: 21/12/05
Descripción: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");



create()
{
    ::create();

    SetIntShort("el tercer nivel de las minas de Kha-annu");
    SetIntLong("Te encuentras en la planta más profunda de las minas de "
               "Kha-annu. Observas unas escaleras que ascienden al nivel "
               "superior, y el comienzo de una galería al norte. Aquí la "
               "humedad es muy pronunciada y la sensación de frío reina en el "
               "ambiente.\n");

    DetalleParedes();
    AddDetail(({"escalerilla","escalera"}),
                "Es una pequeña escalera metálica que comunica este nivel con "
                "el inferior.\n");

    AddDetail(({"hueco","agujero"}),
                "Es un agujero hecho en la piedra, que comunica este nivel "
                "con el superior.\n");

    AddExit("arriba",HAB_SEGUNDA_MINAS("minas30"));
    AddExit("norte",HAB_TERCERA_MINAS("minas02"));
    AddGuardia();
}
