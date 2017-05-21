/**************************************************************************
fichero: minas04.c
Autor: Riberales
Creación: 28/10/05
Descripción: Room en primera planta de las minas, bajada a la segunda.
**************************************************************************/


#include "path.h"

inherit HAB_PRIMERA_MINAS("primera_base");



create()
{
    ::create();

    SetIntShort("las minas de Kha-annu");
    SetIntLong("Te encuentras en la primera planta de las minas del reino de "
               "Kha-annu. A tu alrededor sólo ves roca y más roca. Al "
               "sur observas un arco que da a parar a un cruce de galerías, y "
               "otro túnel al noroeste, mientras que a tu lado hay una "
               "pequeña escalerilla para bajar al nivel inferior.\n");

    AddDetail(({"hueco","agujero"}),
                "Es un agujero hecho en la piedra, que comunica este nivel "
                "con el inferior.\n");

    AddDetail("arco",
              "Es un hueco hecho en la roca. Permite comunicar esta estancia "
              "con la que hay al sur.\n");

    AddDetail(({"escalerilla","escalera"}),
                "Es una pequeña escalera metálica que comunica este nivel "
                "con el inferior.\n");

    DetalleParedes();


    AddExit("abajo",HAB_SEGUNDA_MINAS("minas25"));
    AddExit("noroeste",HAB_PRIMERA_MINAS("minas06"));
    AddExit("sur",HAB_PRIMERA_MINAS("minas03"));
    AddGuardia();
}
