/***
Fichero: elemental_mayor.c
autor: kastwey@simauria
Descripción: Elemental para los conjus de Siempreunidos
No me molaba que usasen el monster de los players,
que metía un montón de código innecesario para lo que yo lo quiero.
Creación: 22/12/2004
15/01/2005: Pongo un tiempo de vida de 180 segundos, como el de los conjuratas de to la vida
***/

#include "path.h"
#include <living.h>

inherit NPC;

create()
{
    ::create();
   SetStandard("un elemental de fuego mayor","frirel",50,GENDER_NEUTER);
    AddId("elemental");
    AddId("elemental de fuego");
    AddId("elemental de fuego mayor");
    call_out("destruir",180);
}


public int QueryElemental() { return 1; }
public int QueryIsElementalFaeria() { return 1; }

void destruir()
{
    DropHeart(HEART_USER);
    DropHeart(HEART_HEAL);
    tell_room(environment(),"Un elemental huye y desaparece.\n");
    remove();
}
