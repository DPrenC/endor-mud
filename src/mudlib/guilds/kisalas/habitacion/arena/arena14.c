/****************************************************************************
Fichero: arena14.c
Autor: Kastwey
Fecha: 19/02/2006
Descripci�n: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();
    SetIntLong("Los �rboles crecen casi hasta el mismo borde del agua que "
               "queda al este, aprovechando cada cent�metro de terreno. Puedes "
               "continuar bordeando la costa en direcci�n norte o sur, o adentrarte "
               "en el bosque si vas hacia el oeste.\n");

    AnadeDetalleLago("este");

    AddExit("oeste","arena13");
    AddExit("norte","arena16");
    AddExit("noroeste","arena15");
    AddExit("sur","arena12");
    AddExit("suroeste","arena11");

}


