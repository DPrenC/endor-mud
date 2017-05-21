/****************************************************************************
Fichero: pasaje_thualin_ungrim.c
Autor: Kastwey
Creación: 21/08/2005
Descripción: Pasaje que comunica la calle Thualin con la Ungrim
****************************************************************************/

#include "./path.h"
#include <nightday.h>

#define NOCHE ({ND_NIGHT,ND_PREDAWN,ND_DAWN,ND_SUNRISE})

inherit BASE_CIUDAD_ANNUFAM;


string DescPasaje()
{
    string diferencia;
    if (member(NOCHE,SERVER->QueryState()) >= 0)
    // es de noche
    {
        diferencia = "La oscuridad aquí es casi total, atenuada únicamente "
                     "por las luces que proyectan antorchas cercanas.\n";
    }
    else
    {
        diferencia = "Es bastante oscuro, a pesar de la luz diurna "
                     "que se filtra desde el norte.\n";
    }
    return W("Caminas por un pasaje entre las calles Thualin y Ungrim. " +
             diferencia + "Al norte sales a la calle Thualin, mientras que "
             "al sur continúa el callejón.\n");
}


public void create()
{
    ::create();
    SetIntShort("un pasaje");
    SetIntLong(#'DescPasaje);

    SetIndoors(1);
    SetIntBright(10);
    AddSuelo();

    AddExit("norte",HAB_THUALIN_ANNUFAM("thualin_04"));
    AddExit("sur",HAB_CALLES_ANNUFAM("pasaje_02"));

}
