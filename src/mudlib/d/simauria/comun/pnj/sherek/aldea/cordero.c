/****************************************************************************
Fichero: /d/simauria/comun/pnj/sherek/aldea/cordero.c
Autor: Lug y Yalin
Fecha: 16/01/2007
Descripción: Corderos para la granja de la aldea.
****************************************************************************/

#include "path.h"
#include <guild.h>
#include <properties.h>

inherit NPC;

create()
{
    ::create();
    SetStandard("un cordero","oveja",([ GC_TORPE:5+d4() ]),GENERO_MASCULINO);
    SetShort("un cordero");
    SetLong("Es un suave y delicado corderito, que corretea por el "
        "establo, en espera de que su madre le permita mamar.\n");
    AddId("cordero");
    SetWeight(5000);
    SetNoGet("El cordero huye de tus manazas.\n");
    InitChats(5,
        ({"El cordero te mira con ojos tristes.\n",
        "El cordero bala de hambre.\n",
        "El cordero busca a su madre.\n"}));
}
