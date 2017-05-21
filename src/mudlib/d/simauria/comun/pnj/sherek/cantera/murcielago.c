/****************************************************************************
Fichero: /d/simauria/comun/pnj/sherek/cantera/murcielago.c
Autor: Lug y Yalin
Fecha: 09/01/2007
Descripci�n: Murci�lago para el segundo nivel del laberinto.
****************************************************************************/
#include "path.h"
#include <properties.h>
#include <combat.h>
#include <moving.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("un murci�lago","murcielago",4+d6(),GENERO_MASCULINO);
    SetShort("un murci�lago");
    SetLong("Es una especie de rata, con largos dedos en las patas "
        "delanteras, unidos por una membrana, que le permite volar.\nEs de "
        "un color casi negro, que le hace casi invisible en esta oscuridad.\n");
    AddId(({"murcielago","murci�lago","vampiro"}));
    SetSize(1);
    SetHP(QueryMaxHP());
    InitChats(10,({"El murci�lago revolotea sobre ti.\n",
        "El murci�lago lanza agudos chillidos.\n",
        "El murci�lago esquiva �gilmente tu cabeza.\n",
        "El murci�lago se posa en una roca.\n"}));
}

