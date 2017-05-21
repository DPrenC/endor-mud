/**************************************************************************
fichero: minas26.c
Autor: Riberales
Creaci�n: 2/1/06
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/

#include "path.h"
#include <properties.h>
#include <materials.h>


inherit HAB_TERCERA_MINAS("tercera_base");


        create()
{

    ::create();

    SetIntShort("el final de una galer�a");
    SetIntLong("Has llegado al final de uno de los t�neles de las minas "
               "enanas, sin lugar a duda, el m�s peque�o. Esta zona se "
               "ensancha un poco, pues parece que se detuvieron a picar e "
               "intentar extraer mineral, y por lo que ves, no se lo llevaron "
               "todo. El estrecho t�nel se encuentra al este.\n");

    SetTipo(M_MITHRIL);
    DetalleVeta();


    AddExit("oeste",HAB_TERCERA_MINAS("minas25"));
    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT,([P_GO_CHANCE:0]));
}

