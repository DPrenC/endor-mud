/****************************************************************************
Fichero: ungrim_04.c
Autor: Kastwey
		[T] Tagoras
Creación: 22/08/2005
Descripción: Esquina este de la calle Ungrim
[T] 05/01/2012: Areglo typos y la descripción
****************************************************************************/

#include "./path.h"

inherit BASE_CIUDAD_ANNUFAM;

public void create()
{
    ::create();
    SetIntShort("el extremo este de la calle Ungrim");
    SetIntLong("Has ido a parar al extremo oriental de la calle "
               "Ungrim. Toda esta calle, llena de comercios y tabernas, "
               "continúa en dirección oeste. Por otra parte, en "
               "dirección norte ves un pasaje que supones te llevará a la "
               "calle Thualin. También puedes ver un par de antorchas que "
               "iluminan esta parte de la ciudad cuando es necesario.\n");
    AddSuelo();
    AddAntorchas();
    AddDetail(({"norte","pasaje"}),
              "Este pasaje comunica la calle en la que te encuentras con "
              "la calle Thualin. Por lo visto, no penetra mucha luz en él.\n");
    AddExit("oeste",HAB_UNGRIM_ANNUFAM("ungrim_03"));
    AddExit("norte",HAB_CALLES_ANNUFAM("pasaje_02"));
}
