/****************************************************************************
Fichero: arena12.c
Autor: Kastwey
Fecha: 19/02/2006
Descripción: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
    SetIntLong("La isla acaba al este, dando paso al lago que la rodea. "
               "Puedes seguir bordeando esta parte de la costa si vas hacia el "
               "norte o hacia el sur, o adentrarte más en el bosque si vas en "
               "dirección oeste.\n");

    AnadeDetalleLago("este");
    AddExit("oeste","arena11");
    AddExit("norte","arena14");
    AddExit("noroeste","arena13");
    AddExit("sur","arena10");
    AddExit("suroeste","arena9");

}


