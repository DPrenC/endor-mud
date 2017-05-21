/****************************************************************************
 sendero2.cFichero:
Autor: Kastwey
Creaci�n: 24/07/2005
Descripci�n: Sendero hacia la ciudad de Annufam
****************************************************************************/
#include "./path.h"

inherit HAB_SENDERO_ANNUFAM("sendero_base");

public void create()
{
    ::create();
    SetIntShort("un peque�o sendero");
    SetIntLong(W("Sigues caminando por un sendero en las monta�as de "
                 "Kha-annu. En este punto la vegetaci�n es a�n m�s "
                 "frondosa, y los pinos y hayas te impiden ver m�s all� de "
                 "tu sombra. La peque�a senda se abre en direcci�n oeste "
                 "y sudeste.\n"));
    AddExit("sudeste",HAB_SENDERO_ANNUFAM("sendero1"));
    AddExit("oeste",HAB_SENDERO_ANNUFAM("sendero3"));
}

