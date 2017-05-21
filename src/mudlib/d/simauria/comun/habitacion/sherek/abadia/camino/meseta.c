/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/meseta.c
Autor: Yalin
Fecha: 25/07/2009 11:42
Descripci�n: plataforma de acceso a la abad�a
****************************************************************************/

#include "path.h"
inherit SHERAB("std/ext");

create ()
{
    ::create();
    SetIntShort("la cumbre de la monta�a");
    SetIntLong("Est�s en la cima de la monta�a de Sherek, al final del camino que asciende del "
        "valle.\nEsto es una peque�a meseta m�s o menos triangular, siendo el camino el v�rtice "
        "sur, con los lados este y oeste ligeramente redondeados, desde los que la ladera "
        "desciende abruptamente. Sendas veredas salen de los v�rtices este y oeste, limitadas al "
        "sur por una balaustrada de piedra que impide la ca�da por las cortaduras casi a pico que "
        "se han formado, tal vez de forma artificial.\nDel centro del lado norte surge un sendero "
        "que conduce al edificio de la abad�a, que se levanta imponente frente a ti.\n");
    AddExit("norte", SHERAB("camino/sendero"));
    AddExit("sur", SHERAB("camino/cam18"));
    AddExit("este",SHERAB("camino/corn1e"));
    AddExit("oeste",SHERAB("camino/corn1o"));
}
