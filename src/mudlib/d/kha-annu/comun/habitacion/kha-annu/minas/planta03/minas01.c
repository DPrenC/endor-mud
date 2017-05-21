/**************************************************************************
fichero: minas01.c
Autor: Riberales
Creaci�n: 21/12/05
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_TERCERA_MINAS("tercera_base");



create()
{
    ::create();

    SetIntShort("el tercer nivel de las minas de Kha-annu");
    SetIntLong("Te encuentras en la planta m�s profunda de las minas de "
               "Kha-annu. Observas unas escaleras que ascienden al nivel "
               "superior, y el comienzo de una galer�a al norte. Aqu� la "
               "humedad es muy pronunciada y la sensaci�n de fr�o reina en el "
               "ambiente.\n");

    DetalleParedes();
    AddDetail(({"escalerilla","escalera"}),
                "Es una peque�a escalera met�lica que comunica este nivel con "
                "el inferior.\n");

    AddDetail(({"hueco","agujero"}),
                "Es un agujero hecho en la piedra, que comunica este nivel "
                "con el superior.\n");

    AddExit("arriba",HAB_SEGUNDA_MINAS("minas30"));
    AddExit("norte",HAB_TERCERA_MINAS("minas02"));
    AddGuardia();
}
