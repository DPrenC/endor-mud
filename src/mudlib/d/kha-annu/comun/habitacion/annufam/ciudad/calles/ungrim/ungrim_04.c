/****************************************************************************
Fichero: ungrim_04.c
Autor: Kastwey
		[T] Tagoras
Creaci�n: 22/08/2005
Descripci�n: Esquina este de la calle Ungrim
[T] 05/01/2012: Areglo typos y la descripci�n
****************************************************************************/

#include "./path.h"

inherit BASE_CIUDAD_ANNUFAM;

public void create()
{
    ::create();
    SetIntShort("el extremo este de la calle Ungrim");
    SetIntLong("Has ido a parar al extremo oriental de la calle "
               "Ungrim. Toda esta calle, llena de comercios y tabernas, "
               "contin�a en direcci�n oeste. Por otra parte, en "
               "direcci�n norte ves un pasaje que supones te llevar� a la "
               "calle Thualin. Tambi�n puedes ver un par de antorchas que "
               "iluminan esta parte de la ciudad cuando es necesario.\n");
    AddSuelo();
    AddAntorchas();
    AddDetail(({"norte","pasaje"}),
              "Este pasaje comunica la calle en la que te encuentras con "
              "la calle Thualin. Por lo visto, no penetra mucha luz en �l.\n");
    AddExit("oeste",HAB_UNGRIM_ANNUFAM("ungrim_03"));
    AddExit("norte",HAB_CALLES_ANNUFAM("pasaje_02"));
}
