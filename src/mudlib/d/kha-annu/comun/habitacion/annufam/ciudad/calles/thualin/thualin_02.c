/****************************************************************************
Fichero: thualin_02.c
Autor: Kastwey
Creación: 27/07/2005
Descripción: Calle Thualin
****************************************************************************/

#include "./path.h"

inherit HAB_THUALIN_ANNUFAM("thualin_base");

public void create()
{
    ::create();
    SetIntShort("la calle Thualin");
    SetIntLong(W("Continúas caminando por la Calle Thualin, que sigue por "
                 "toda la pared sur del Centro de Adiestramiento. Al sur "
                 "puedes ver la vivienda de la familia del posadero de "
                 "la ciudad, posada que divisas al este. También puedes ver "
                 "un par de antorchas que iluminan esta parte de la calle "
                 "cuando es necesario.\n"));

    AddDetail(({"casa","pared sur","sur"}),
              W("Es la casa de la familia que regenta la posada de la "
                "ciudad. Arriba observas una de las habitaciones de dicha "
                "posada. La entrada se encuentra más al este.\n"));

    AddAntorchas();
    AddSuelo();

    AddExit("oeste",HAB_THUALIN_ANNUFAM("thualin_01"));
    AddExit("este",HAB_THUALIN_ANNUFAM("thualin_03"));
    AddExit("sur",
            (:write(W("La casa del posadero está cerrada. Si lo que quieres "
                      "es hablar con él, quizás lo encuentres en la "
                      "posada.\n"));
              return 1;:));

}