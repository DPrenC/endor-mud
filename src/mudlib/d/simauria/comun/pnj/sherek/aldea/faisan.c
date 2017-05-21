/* Archivo:         faisan.c
* Descripci�n:      Fais�n para la granja de Sloch.
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
    SetStandard("un fais�n","fais�n",([ GC_TORPE:10 ]),GENERO_MASCULINO);
    SetShort("un fais�n");
    SetLong("Es un ave similar a la gallina, pero algo m�s peque�a. Su cola es larga y termina "
            "en punta. Posee plumas de un color verde brillante y azulado en la cabeza y cuello, "
            "con dos c�rculos rojos alrededor de los ojos. Su cuello se encuentra rodeado por "
            "plumas blancas de menor tama�o, a modo de collar. El cuerpo es de un color "
            "marr�n con manchas negras.\n");
    AddId(({"fais�n","faisan"}));
    SetMaxHP(87);
    SetHP(QueryMaxHP());
    SetInt(1);
    SetStr(9);
    SetDex(10);
    SetHands(({({"pico",3,1})}));
    SetWeight(4000);
    SetNoGet("El fais�n sale volando.\n");
    InitChats(5,({"El fais�n estira el cuello y mira en todas direcciones.\n",
                "El fais�n revolotea.\n",
                "El fais�n picotea algo que hay en el suelo.\n",
                "El fais�n se atusa el plumaje.\n"}));
}
