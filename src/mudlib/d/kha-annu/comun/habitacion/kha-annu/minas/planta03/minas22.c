/**************************************************************************
fichero: minas22.c
Autor: Riberales
Creación: 2/1/06
Descripción: Room en tercera planta de las minas.
**************************************************************************/



#include "path.h"
#include <materials.h>

inherit HAB_TERCERA_MINAS("tercera_base");

        create()
{
    ::create();

    SetIntShort("la tercera planta de las minas");
    SetIntLong("Te hallas en el nivel con más humedad de las minas enanas, y "
               "tanto ésta como el frío siguen haciendo acto de presencia por "
               "doquier. En la roca de una de las paredes te parece "
               "distinguir algo brillante, como mineral sin extraer. El túnel "
               "sigue al sudeste y al suroeste.\n");

    SetTipo(M_MITHRIL);
    DetalleVeta();
    AddDetail(({"brillo","brillante"}),
                "Parece que es resto de oro sin extraer.\n");



    AddExit("sudeste",HAB_TERCERA_MINAS("minas23"));
    AddExit("suroeste",HAB_TERCERA_MINAS("minas21"));
    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT);
}

