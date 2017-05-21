/**************************************************************************
fichero: minas04.c
Autor: Riberales
Creaci�n: 22/12/05
Descripci�n: Room en tercera planta de las minas.
**************************************************************************/


#include "path.h"
#include <materials.h>
#include <properties.h>

inherit HAB_TERCERA_MINAS("tercera_base");



create()
{
    ::create();

    SetIntShort("una estancia de las minas");
    SetIntLong("Contemplas una de las m�ltiples c�maras que hay en las minas "
               "enanas. La roca de las paredes parece estar bastante "
               "machacada, aunque puede que queden algunos restos de mineral. "
               "La �nica salida se encuentra en direcci�n nordeste, donde te "
               "parece ver una galer�a bastante ancha.\n");

    SetTipo(M_MITHRIL);
    DetalleVeta();


    AddExit("nordeste",HAB_TERCERA_MINAS("minas03"));

    AddGuardia();
    AddItem(PNJ_MINAS("minero_tercera"),REFRESH_DESTRUCT,([P_GO_CHANCE:0]),1);
}


