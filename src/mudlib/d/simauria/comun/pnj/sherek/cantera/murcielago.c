/****************************************************************************
Fichero: /d/simauria/comun/pnj/sherek/cantera/murcielago.c
Autor: Lug y Yalin
Fecha: 09/01/2007
Descripción: Murciélago para el segundo nivel del laberinto.
****************************************************************************/
#include "path.h"
#include <properties.h>
#include <combat.h>
#include <moving.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("un murciélago","murcielago",4+d6(),GENERO_MASCULINO);
    SetShort("un murciélago");
    SetLong("Es una especie de rata, con largos dedos en las patas "
        "delanteras, unidos por una membrana, que le permite volar.\nEs de "
        "un color casi negro, que le hace casi invisible en esta oscuridad.\n");
    AddId(({"murcielago","murciélago","vampiro"}));
    SetSize(1);
    SetHP(QueryMaxHP());
    InitChats(10,({"El murciélago revolotea sobre ti.\n",
        "El murciélago lanza agudos chillidos.\n",
        "El murciélago esquiva ágilmente tu cabeza.\n",
        "El murciélago se posa en una roca.\n"}));
}

