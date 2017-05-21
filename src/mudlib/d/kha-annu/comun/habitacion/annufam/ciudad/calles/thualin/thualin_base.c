/****************************************************************************
Fichero: thualin_base.c
Autor: Kastwey
Creación: 28/07/2005
Descripción: Fichero base para la calle de Thualin... Estoy arto de escribir
             los detalles de la pared del centro de entrenamiento.
****************************************************************************/

#include "./path.h"
#include <nightday.h>

#define OSCURIDAD ({ND_NIGHT,ND_PREDAWN,ND_DAWN,ND_SUNRISE})

inherit BASE_CIUDAD_ANNUFAM;

string DescVentana()
{
    if (member(OSCURIDAD,SERVER->QueryState()) >= 0)
    // es de noche
    {
        return W("Te asomas a una de las ventanas, y observas el interior de "
                 "una sala en penumbras, iluminada por algunas antorchas. "
                 "Supones que será una de las salas donde se entrenan los "
                 "enanos en el arte de la lucha.\n");
    }
    return W("Te asomas por una de las ventanas y observas el interior de "
             "lo que supones será una de las salas donde los enanos se entrenan "
             "en el arte de la lucha.\n");
}
public void create()
{
    ::create();
    AddSuelo();

    AddDetail("pared","¿Qué pared quieres mirar en concreto?\n");

    AddDetail(({"pared norte","centro","norte"}),
               W("La pared del centro de entrenamiento es totalmente lisa y "
               "sin ningún adorno, aparte de algunas ventanas que muestran "
               "el interior del edificio. Recorre toda la calle Thualin y sólo tiene "
               "una entrada, en la Plaza Belthain.\n"));

    AddDetail(({"ventanas","ventana","ventana de la pared norte",
                "ventana norte","ventana del centro","ventana de centro"}),
              #'DescVentana);

}
