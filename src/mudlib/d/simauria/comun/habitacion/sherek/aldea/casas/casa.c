/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/casas/casa.c
Autor: Lug y Yalin
Fecha: 13/01/2007
Descripción: Base para las casas de la aldea.
****************************************************************************/

#include "path.h"
inherit SIM_ROOM;

create ()
{
    ::create();
    SetIntShort("una pequeña casa aldeana");
    SetIntLong("Estás dentro de una de las casas de la aldea de Sloch. "
        "Estéticamente son todas muy parecidas ya que fueron levantadas "
        "pensando en su practicidad . A tu alrededor puedes ver los muebles, "
        "la chimenea y un par de ventanas.\n");
    SetIntNoise("Escuchas, apagados, los sonidos de la calle.\n");
    SetIntSmell("Hay una mezcla de olores, pero prevalecen los del hogar.\n");
    SetIntBright(40);
    AddDetail(({"mueble", "muebles"}), "Ves una mesa, unas sillas, un "
        "aparador y una cama.\n");
    AddDetail(({"cama"}), "Es una simple cama de madera con un colchón de "
        "lana y unas mantas.\n");
    AddDetail(({"colchón", "colchon"}), "Un viejo e incómodo colchón de lana "
        "de oveja.\n");
    AddDetail(({"manta", "mantas"}), "Unas mantas de tejido bruto, pero "
        "quitan el frío nocturno.\n");
    AddDetail(({"mesa"}), "Una mesa de madera sin pulir sobre cuatro troncos "
        "que hacen la función de patas.\n");
    AddDetail(({"silla", "sillas"}), "son varias sillas de madera mal "
        "construidas.\n");
    AddDetail(({"Aparador", "armario"}), "Lo usan para guardar cosas. Está "
        "bastante deteriorado por el uso y por el tiempo.\n");
    AddDetail(({"techo"}), "Es un artesonado de madera que separa la "
        "estancia del tejado de pizarra.\n");
    AddDetail(({"ventana", "ventanas"}), "Por una de ellas puedes ver la "
        "calle en la que acabas de estar y por la otra ves el pequeño huerto "
        "de la casa.\n");
    AddDetail(({"paredes", "pared"}), "Están bien encaladas y fueron "
        "construidas con mampostería.\n");
    AddDetail(({"suelo"}), "El suelo es de tierra apisonada.\n");
    AddDetail(({"chimenea", "hogar"}), "Se trata de una piedra algo más "
        "elevada que el resto del suelo, sobre la que se cocinan todos los "
        "alimentos. El humo sale por un agujero practicado en el techo.\n");
}
