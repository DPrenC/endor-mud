/**************************************************************************
fichero: minas26.c
Autor: Riberales
Creación: 2/1/06
Descripción: Room en tercera planta de las minas.
**************************************************************************/

#include "path.h"
#include <properties.h>
#include <materials.h>


inherit HAB_TERCERA_MINAS("tercera_base");


        create()
{

    ::create();

    SetIntShort("el final de una galería");
    SetIntLong("Has llegado al final de uno de los túneles de las minas "
               "enanas, sin lugar a duda, el más pequeño. Esta zona se "
               "ensancha un poco, pues parece que se detuvieron a picar e "
               "intentar extraer mineral, y por lo que ves, no se lo llevaron "
               "todo. El estrecho túnel se encuentra al este.\n");

    SetTipo(M_MITHRIL);
    DetalleVeta();


    AddExit("oeste",HAB_TERCERA_MINAS("minas25"));
    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT,([P_GO_CHANCE:0]));
}

