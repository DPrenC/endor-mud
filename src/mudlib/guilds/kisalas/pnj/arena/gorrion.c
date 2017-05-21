/****************************************************************************
Fichero: gorrion.c
Autor: Kastwey
Fecha: 01/03/2006
Descripci�n: Un gorri�n para la arena de las Kisalas
****************************************************************************/

#include <damage.h>
#include <gremios.h>
#include <properties.h>
#include "./path.h"

inherit ANIMAL_BASE;

create()
{
    ::create();
    SetStandard("un gorri�n","gorrion",([ GC_TORPE: 1]),GENDER_MALE);
    SetShort("un gorri�n");
    SetLong("Es un peque�o gorri�n de plumaje gris�ceo. Se pasa el tiempo "
            "dando saltitos de un lugar a otro y piando sin parar.\n");

    AddId(({"gorrion","gorri�n","peque�o gorrion","peque�o gorri�n","pequenyo "
            "gorrion","pequenyo gorri�n","pajaro","p�jaro"}));
    AddAdjective(({"pequenyo", "peque�o", "gracioso"}));
    SetSize(P_SIZE_SMALL);
    SetHands(({({"pico",TD_PENETRACION,1})}));
    SetWeight(500);
    AddWalkZones(AM_ARENA(""));
    SetGoChance(50);
    SetNoGet("El gorri�n levanta el vuelo por un momento y se vuelve a posar lejos de ti.\n");
    InitChats(3,({"El gorri�n mira nervioso a todos lados.\n",
                  "El gorri�n picotea alguna cosa.\n",
                  "El gorri�n alza el vuelo y se vuelve a posar un poco m�s tarde.\n",
                  "El gorri�n te mira curioso.\n"}));
}
