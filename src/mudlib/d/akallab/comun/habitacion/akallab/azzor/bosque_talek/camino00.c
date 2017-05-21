/*
DESCRIPCION  : Camino del Este a traves del bosque de Talek
FICHERO      : camino00.c
MODIFICACION : 04-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>
inherit BOSQUE_TALEK("camino");

//los PNJ no pasan
int ir_o()
{
    if (TP->QueryIsPlayer()) return TP->move(BOSQUE_TALEK("camino00"),M_GO);
    return 1;
}

create()
{
    ::create();
   SetIntLong("El Camino del Este asciende cada vez m�s a medida que se "
        "aleja del bosque de Talek y se acerca al paso de Akkbar entre las "
        "monta�as Negras. Desde aqu� puedes ya observar la mayor parte del "
        "valle y el inmenso tama�o que tiene el bosque. Sopla un viento fr�o "
        "desde las monta�as.\n");
    AddDetail(({"desfiladero","paso","paso de Akkbar"}),"El paso de Akkbar "
        "es el nombre que recibe un paso a trav�s de las monta�as Negras. "
        "Estas monta�as separan el valle de Zarkam de los territorios orcos "
        "del valle de Azzor que se hallan en la costa este de la pen�nsula de "
        "Aguliuk.\nPese a ser un lugar peligroso, el paso de Akkbar es el "
        "camino mas corto y por ello mas usado para cruzar esas monta�as.\n");
    AddExit("oeste",AKKBAR_CAMINO("akkbar07"));
    AddExit("sudeste",BOSQUE_TALEK("camino01"));
}
