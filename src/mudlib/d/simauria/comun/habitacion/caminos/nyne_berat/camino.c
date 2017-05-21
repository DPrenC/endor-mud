/*
FICHERO: camino.c
CREACION: 10-09-2001 [B] Bomber@simauria.upv.es
DESCRIPCION: Generico para el camino que va desde Berat hasta
            la aduana al principio del bosque de Nyne. Adaptado
            del camino de Nandor a Gorat, de Maler creo.
*/

#include "./path.h"
#include <properties.h>

inherit SIM_ROOM;

create()
{
    ::create();
    SetIndoors(0);
    SetLocate("el camino Nyne-Berat");

    SetIntShort("el camino Nyne-Berat");

    switch (random(4)){
        case 0:
            SetIntLong("Estás en el camino que va desde Nyne a Berat. Es una senda que transcurre"
            " en medio de un frondoso bosque. Te aconsejaría que andaras con cuidado por"
            " lo que pueda pasar.\n");
            break;
        case 1:
            SetIntLong("Estás en el camino que une Nyne con Berat. Es una senda poco transitada a "
            "pie, pues es una zona poco segura, por eso  se puede observar que está "
            "bastante mal señalizado.\n");
            break;
        case 2:
                SetIntLong("Estás en el camino que enlaza la ciudad de Nyne con Berat."
            " Es un camino poco seguro, por lo que no es recomendable pararse mucho "
            "tiempo en él.\n");
            break;
        case 3:
            SetIntLong("En estos momentos estas en el camino que va de Nyne a Berat. "
            "El camino transcurre por un frondoso bosque "
	        "donde debe haber infinidad de animales que no puedes ver, pero que sientes "
	        "que están ahí.\n");
	    break;
    }
    if(d8()==1)
        AddItem(PNJ("camino/salteador"), REFRESH_REMOVE);
}
