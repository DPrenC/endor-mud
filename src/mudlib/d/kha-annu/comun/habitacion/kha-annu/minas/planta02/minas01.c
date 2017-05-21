/**************************************************************************
fichero: minas01.c
Autor: Riberales
Creaci�n: 9/11/05
Descripci�n: Room en segunda planta de las minas.
**************************************************************************/


#include "path.h"

inherit HAB_SEGUNDA_MINAS("segunda_base");



create()
{
    ::create();

    SetIntShort("la segunda planta de las minas");
    SetIntLong("Te encuentras en el nivel intermedio de estas minas. En esta "
               "zona la humedad ya va ganando importancia, aunque a�n puedes "
               "respirar con normalidad. Observas una escalerilla y un t�nel "
               "en direcci�n este.\n");


    DetalleParedes();

    AddDetail(({"escalera","escalerilla"}),
                "Es una peque�a escalera met�lica que comunica este nivel con "
                "el superior.\n");

    AddDetail(({"hueco","agujero"}),
                "Es un agujero hecho en la piedra, que comunica este nivel "
                "con el inmediatamente superior.\n");

    AddExit("arriba",HAB_PRIMERA_MINAS("minas26"));
    AddExit("este",HAB_SEGUNDA_MINAS("minas02"));
    AddGuardia();
}
