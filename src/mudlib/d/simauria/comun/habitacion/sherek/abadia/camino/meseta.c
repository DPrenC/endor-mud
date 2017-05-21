/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/meseta.c
Autor: Yalin
Fecha: 25/07/2009 11:42
Descripción: plataforma de acceso a la abadía
****************************************************************************/

#include "path.h"
inherit SHERAB("std/ext");

create ()
{
    ::create();
    SetIntShort("la cumbre de la montaña");
    SetIntLong("Estás en la cima de la montaña de Sherek, al final del camino que asciende del "
        "valle.\nEsto es una pequeña meseta más o menos triangular, siendo el camino el vértice "
        "sur, con los lados este y oeste ligeramente redondeados, desde los que la ladera "
        "desciende abruptamente. Sendas veredas salen de los vértices este y oeste, limitadas al "
        "sur por una balaustrada de piedra que impide la caída por las cortaduras casi a pico que "
        "se han formado, tal vez de forma artificial.\nDel centro del lado norte surge un sendero "
        "que conduce al edificio de la abadía, que se levanta imponente frente a ti.\n");
    AddExit("norte", SHERAB("camino/sendero"));
    AddExit("sur", SHERAB("camino/cam18"));
    AddExit("este",SHERAB("camino/corn1e"));
    AddExit("oeste",SHERAB("camino/corn1o"));
}
