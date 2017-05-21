/****************************************************************************
Fichero: calle17.c
Autor: Ratwor
Fecha: 01/11/2006
Descripción:  El pasaje que une la calle principal con la calle Narwhald.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("la aldea de Nandor");
    SetIntShort("un pasaje");
    SetIntLong("Este pasaje, ubicado entre los dos edificios más importantes de la villa,"
        " que son la casa de tributos al este y el cuartel general del gremio de guerreros al"
        " oeste, une de norte a sur la plaza de Nandor con la calle Narwhald.\n");
    SetIntNoise("Escuchas el sonido de la gente de la plaza del sur.\n");
    SetIndoors(0);
    AddDetail(({"cuartel","cuartel general", "edificio del oeste"}), "Es la "
        "sede principal del gremio de guerreros, la puerta la tiene al otro lado en la plaza del sur.\n");
    AddDetail(({"casa de tributos", "edificio del este"}), "Es la casa de tributos, "
    "cuyo edificio tiene la entrada por la plaza del pueblo.\n");
    AddDetail(({"edificio","edificios"}), "Hay dos edificios, uno al este y otro al oeste.\n");
    AddExit("norte","./calle16");
    AddExit("sur","./calle41n");
}
