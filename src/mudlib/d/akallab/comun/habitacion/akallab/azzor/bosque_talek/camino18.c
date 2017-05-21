/*
DESCRIPCION  : camino a traves del bosque de Talek
FICHERO      : camino18.c
MODIFICACION : 13-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntLong("El camino continúa avanzando por el interior del bosque "
        "hacia el sur y hacia el noroeste. Este bosque es bastante frondoso "
        "y húmedo en esta zona. Junto al camino se encuentra el viejo tocón "
        "de un árbol talado hace mucho tiempo.\n");
    AddDetail(({"tocón","tocon","viejo tocón","viejo tocon"}),"El tocón es "
        "la parte baja del tronco que está unida a las raíces del árbol. "
        "Alguien debió talar un gran árbol que crecía junto al camino y "
        "ahora solo su tocón recuerda que alguna vez estuvo aquí. Seguro que "
        "algún cansado viajero lo ha usado como asiento más de una vez.\n");
    AddExit("nordeste",BOSQUE_TALEK("camino19"));
    AddExit("suroeste",BOSQUE_TALEK("camino17"));
    AddExit("oeste",BOSQUE_TALEK("bosque65"));
    AddExit("este",BOSQUE_TALEK("bosque66"));
}
