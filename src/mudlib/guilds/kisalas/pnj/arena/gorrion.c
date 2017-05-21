/****************************************************************************
Fichero: gorrion.c
Autor: Kastwey
Fecha: 01/03/2006
Descripción: Un gorrión para la arena de las Kisalas
****************************************************************************/

#include <damage.h>
#include <gremios.h>
#include <properties.h>
#include "./path.h"

inherit ANIMAL_BASE;

create()
{
    ::create();
    SetStandard("un gorrión","gorrion",([ GC_TORPE: 1]),GENDER_MALE);
    SetShort("un gorrión");
    SetLong("Es un pequeño gorrión de plumaje grisáceo. Se pasa el tiempo "
            "dando saltitos de un lugar a otro y piando sin parar.\n");

    AddId(({"gorrion","gorrión","pequeño gorrion","pequeño gorrión","pequenyo "
            "gorrion","pequenyo gorrión","pajaro","pájaro"}));
    AddAdjective(({"pequenyo", "pequeño", "gracioso"}));
    SetSize(P_SIZE_SMALL);
    SetHands(({({"pico",TD_PENETRACION,1})}));
    SetWeight(500);
    AddWalkZones(AM_ARENA(""));
    SetGoChance(50);
    SetNoGet("El gorrión levanta el vuelo por un momento y se vuelve a posar lejos de ti.\n");
    InitChats(3,({"El gorrión mira nervioso a todos lados.\n",
                  "El gorrión picotea alguna cosa.\n",
                  "El gorrión alza el vuelo y se vuelve a posar un poco más tarde.\n",
                  "El gorrión te mira curioso.\n"}));
}
