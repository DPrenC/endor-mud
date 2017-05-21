/****************************************************************************
Fichero: thualin_0.c
Autor: Kastwey
Creación: 21/08/2005
Descripción: Fin de la calle Thualin
****************************************************************************/

#include "./path.h"

inherit HAB_THUALIN_ANNUFAM("thualin_base");

public void create()
{
    ::create();
    SetIntShort("la esquina este de la calle Thualin");
    SetIntLong(W("Te encuentras al final de la Calle Thualin. Esta discurre "
                 "al oeste, mientras que al sur un pasaje te conduce a la "
                 "calle Ungrim, donde se encuentran todos los comercios de "
                 "Annufam. Arriba del pasaje ves una de las habitaciones de "
                 "la posada de la ciudad. También puedes ver un par de "
                 "antorchas que iluminan esta parte de la calle cuando es "
                 "necesario.\n"));

    AddAntorchas();

    AddDetail("pasaje",W("Es un pasaje que comunica esta calle con la calle "
                         "Ungrim. Parece que está en penumbras.\n"));

    AddDetail(({"habitacion","habitación","habitacion de la posada","arriba"}),
              W("Es una de las habitaciones de la posada de la ciudad. Desde "
                "aquí sólo ves la ventana y no alcanzas a observar lo que "
                "hay en el interior.\n"));

    AddExit("oeste",HAB_THUALIN_ANNUFAM("thualin_03"));
    AddExit("sur",HAB_CALLES_ANNUFAM("pasaje_01.c"));

}
