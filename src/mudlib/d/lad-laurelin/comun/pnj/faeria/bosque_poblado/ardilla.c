/***
Fichero: ardilla.c
Autor: kastwey@simauria
Descripción: una ardilla para el bosque de Siempreunidos.
Creación: 19/12/2004
***/

#include "path.h"
#include <gremios.h>

inherit NPC;

create()
{
    ::create();
   SetStandard("una ardilla","animal",([GC_TORPE:4+random(4)]),2);
    SetHands(({({"pata delantera izquierda",0, 2}),
               ({"pata delantera derecha", 0, 2})}));
        SetLong("Es una simpática ardilla que te mira desconfiada.\n");
    SetWhimpy(QueryHP());
    SetMsgOut("huye asustada");
    InitChats(6,({"La ardilla mueve la cola.\n",
    "La ardilla escarba en la tierra.\n",
    "La ardilla te mira inquieta.\n"}));
}
