/****************************************************************************
Fichero: canya.c
Autor: Buh
Fecha: 24/09/2007
Descripción: Una caña de pescar.
****************************************************************************/

#include <properties.h>
inherit THING;

create() {
    ::create();
    SetShort("una caña de pescar");
    SetLong("Es una mediana caña de pescar, que apenas llega a los dos metros de "
    "longitud, con su hilo y su anzuelo. Fina y ligera, pero suficiente para capturar "
    "unas piezas pequeñas.\n");
    AddId(({"caña","caña de pescar","canya","canya de pescar"}));
    SetWeight(950);
    SetValue(3000);
}
