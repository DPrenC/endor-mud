/****************************************************************************
Fichero: thualin_02.c
Autor: Kastwey
Creaci�n: 27/07/2005
Descripci�n: Calle Thualin
****************************************************************************/

#include "./path.h"

inherit HAB_THUALIN_ANNUFAM("thualin_base");

public void create()
{
    ::create();
    SetIntShort("la calle Thualin");
    SetIntLong(W("Contin�as caminando por la Calle Thualin, que sigue por "
                 "toda la pared sur del Centro de Adiestramiento. Al sur "
                 "puedes ver la vivienda de la familia del posadero de "
                 "la ciudad, posada que divisas al este. Tambi�n puedes ver "
                 "un par de antorchas que iluminan esta parte de la calle "
                 "cuando es necesario.\n"));

    AddDetail(({"casa","pared sur","sur"}),
              W("Es la casa de la familia que regenta la posada de la "
                "ciudad. Arriba observas una de las habitaciones de dicha "
                "posada. La entrada se encuentra m�s al este.\n"));

    AddAntorchas();
    AddSuelo();

    AddExit("oeste",HAB_THUALIN_ANNUFAM("thualin_01"));
    AddExit("este",HAB_THUALIN_ANNUFAM("thualin_03"));
    AddExit("sur",
            (:write(W("La casa del posadero est� cerrada. Si lo que quieres "
                      "es hablar con �l, quiz�s lo encuentres en la "
                      "posada.\n"));
              return 1;:));

}