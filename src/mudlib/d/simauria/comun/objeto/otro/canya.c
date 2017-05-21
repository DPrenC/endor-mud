/****************************************************************************
Fichero: canya.c
Autor: Buh
Fecha: 24/09/2007
Descripci�n: Una ca�a de pescar.
****************************************************************************/

#include <properties.h>
inherit THING;

create() {
    ::create();
    SetShort("una ca�a de pescar");
    SetLong("Es una mediana ca�a de pescar, que apenas llega a los dos metros de "
    "longitud, con su hilo y su anzuelo. Fina y ligera, pero suficiente para capturar "
    "unas piezas peque�as.\n");
    AddId(({"ca�a","ca�a de pescar","canya","canya de pescar"}));
    SetWeight(950);
    SetValue(3000);
}
