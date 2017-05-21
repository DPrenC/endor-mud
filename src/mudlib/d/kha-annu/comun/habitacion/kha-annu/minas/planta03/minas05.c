/**************************************************************************
fichero: minas05.c
Autor: Riberales
Creación: 22/12/05
Descripción: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"
#include <materials.h>
#include <properties.h>

inherit HAB_TERCERA_MINAS("tercera_base");


create()
{
    ::create();

    SetIntShort("un túnel de las minas enanas");
    SetIntLong("Te encuentras en la tercera planta en las minas enanas de "
               "Kha-annu, rodeado de una pesada humedad, que hace que "
               "respires con bastante dificultad. En las rocas del norte, Te "
               "parece observar un poco de mineral sin extraer. La galería "
               "sigue hacia el sudeste y hacia el oeste, mientras que al "
               "suroeste se abre un pequeño túnel.\n");

    SetTipo(M_MITHRIL);
    DetalleVeta();



    AddExit("sudeste",HAB_TERCERA_MINAS("minas03"));
    AddExit("oeste",HAB_TERCERA_MINAS("minas06"));
    AddExit("suroeste",HAB_TERCERA_MINAS("minas08"));

    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT,([P_GO_CHANCE:0]),1);
}

