/****************************************************************************
Fichero: arena9.c
Autor: Kastwey
Fecha: 19/02/2006
Descripci�n: Arena de las kisalas
****************************************************************************/

#include "path.h"

inherit SUELO_ARENA;

create()
{
    ::create();

    SetIntLong("Aqu� el bosque contin�a casi en todas direcciones. Hacia el "
               "norte te adentras m�s hacia el coraz�n del mismo, mientras que al "
               "sur puedes divisar la costa y el lago Zinn, que rodea todo el "
               "per�metro de este islote.\n");

    AnadeDetalleLago("sur");

    AddExit("este","arena10");
    AddExit("oeste","arena1");
    AddExit("norte","arena11");
    AddExit("nordeste","arena12");
    AddExit("sur","arena7");
    AddExit("sudeste","arena8");
    AddExit("suroeste","arena4");

}


