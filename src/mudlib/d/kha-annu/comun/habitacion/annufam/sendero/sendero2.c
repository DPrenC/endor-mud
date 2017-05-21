/****************************************************************************
 sendero2.cFichero:
Autor: Kastwey
Creación: 24/07/2005
Descripción: Sendero hacia la ciudad de Annufam
****************************************************************************/
#include "./path.h"

inherit HAB_SENDERO_ANNUFAM("sendero_base");

public void create()
{
    ::create();
    SetIntShort("un pequeño sendero");
    SetIntLong(W("Sigues caminando por un sendero en las montañas de "
                 "Kha-annu. En este punto la vegetación es aún más "
                 "frondosa, y los pinos y hayas te impiden ver más allá de "
                 "tu sombra. La pequeña senda se abre en dirección oeste "
                 "y sudeste.\n"));
    AddExit("sudeste",HAB_SENDERO_ANNUFAM("sendero1"));
    AddExit("oeste",HAB_SENDERO_ANNUFAM("sendero3"));
}

