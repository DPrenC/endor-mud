/****************************************************************************
Fichero: conejo.c
Autor: Kastwey
Fecha: 01/03/2006
Descripci�n: Un conejo para la arena de las Kisalas
****************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>
#include <damage.h>

inherit ANIMAL_BASE;

create()
{
    ::create();
    SetStandard("un conejo","conejo",([ GC_TORPE: 2]),GENDER_MALE);
    SetShort("un peque�o conejo");
    SetLong("Es un peque�o y encantador conejito blanco. Te mira con sus ojos curiosos.\n");
    AddId(({"conejo", "conejito"}));
    SetAds(({"peque�o","pequenyo","blanco","encantador"}));
    SetSize(P_SIZE_SMALL);
    SetHands( ({ ({"mordisco",TD_PENETRACION,2}) }) );
    SetWeight(2000);
    SetGoChance(30);
    SetNoGet("El conejo da un salto y se aleja de ti.\n");
    InitChats(3,({"El peque�o conejo mordisquea un poco de hierba.\n",
                  "El peque�o conejo olisquea el aire como si presintiera alg�n peligro.\n",
                  "El peque�o conejo mira temeroso a su alrededor.\n"}));
}
