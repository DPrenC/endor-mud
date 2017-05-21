/* Archivo:         faisan.c
* Descripción:      Faisán para la granja de Sloch.
* Autor:            Yalin y Lug.
* Fecha:            18/05/2006
*/

#include "path.h"
#include <properties.h>
#include <guild.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("un faisán","faisán",([ GC_TORPE:10 ]),GENERO_MASCULINO);
    SetShort("un faisán");
    SetLong("Es un ave similar a la gallina, pero algo más pequeña. Su cola es larga y termina "
            "en punta. Posee plumas de un color verde brillante y azulado en la cabeza y cuello, "
            "con dos círculos rojos alrededor de los ojos. Su cuello se encuentra rodeado por "
            "plumas blancas de menor tamaño, a modo de collar. El cuerpo es de un color "
            "marrón con manchas negras.\n");
    AddId(({"faisán","faisan"}));
    SetMaxHP(87);
    SetHP(QueryMaxHP());
    SetInt(1);
    SetStr(9);
    SetDex(10);
    SetHands(({({"pico",3,1})}));
    SetWeight(4000);
    SetNoGet("El faisán sale volando.\n");
    InitChats(5,({"El faisán estira el cuello y mira en todas direcciones.\n",
                "El faisán revolotea.\n",
                "El faisán picotea algo que hay en el suelo.\n",
                "El faisán se atusa el plumaje.\n"}));
}
