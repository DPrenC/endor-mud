/****************************************************************************
Fichero: /d/akallab/comun/habitacion/akallab/azzor/bosque_talek/camino.c
Autor: Lug y Yalin
Fecha: 22/06/2007
Descripci�n: Fichero base para el camino del este.
****************************************************************************/
#include "path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("el camino del este en el bosque de Talek");
    AddDetail(({"bosque","bosque de Talek"}),"Es un inmenso bosque que se "
        "extiende en la parte suroeste del valle de Azzor, hasta el mismo "
        "pie de las monta�as. Es un bosque denso y algo sombr�o.\nEl Camino "
        "del Este lo atraviesa de este a oeste.\n");
    AddDetail(({"camino","camino del este"}),"Es un importante camino que "
        "comunica el valle de Zarkam con los territorios del valle de Azzor "
        "en la costa este de la pen�nsula orca de Aguliuk.\n");
    SetIntNoise("Oyes el canto de los p�jaros.\n");
    SetIntSmell("Hueles el fresco aroma del bosque.\n");
    SetLocate("valle de Azzor");
    SetIndoors(0);
}
