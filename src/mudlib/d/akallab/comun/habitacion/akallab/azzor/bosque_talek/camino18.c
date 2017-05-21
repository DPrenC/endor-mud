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
   SetIntLong("El camino contin�a avanzando por el interior del bosque "
        "hacia el sur y hacia el noroeste. Este bosque es bastante frondoso "
        "y h�medo en esta zona. Junto al camino se encuentra el viejo toc�n "
        "de un �rbol talado hace mucho tiempo.\n");
    AddDetail(({"toc�n","tocon","viejo toc�n","viejo tocon"}),"El toc�n es "
        "la parte baja del tronco que est� unida a las ra�ces del �rbol. "
        "Alguien debi� talar un gran �rbol que crec�a junto al camino y "
        "ahora solo su toc�n recuerda que alguna vez estuvo aqu�. Seguro que "
        "alg�n cansado viajero lo ha usado como asiento m�s de una vez.\n");
    AddExit("nordeste",BOSQUE_TALEK("camino19"));
    AddExit("suroeste",BOSQUE_TALEK("camino17"));
    AddExit("oeste",BOSQUE_TALEK("bosque65"));
    AddExit("este",BOSQUE_TALEK("bosque66"));
}
