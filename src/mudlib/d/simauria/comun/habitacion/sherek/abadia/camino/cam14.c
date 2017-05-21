/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/abadia/camino/cam14.c
Autor: Yalin
Fecha: 25/06/2009 22:49
Descripci�n: Camino de monta�a hacia la abad�a
****************************************************************************/

#include "path.h"
inherit SHERAB("std/camino");

create ()
{
    ::create();
    SetIntLong(QueryIntLong()+"El trazado contin�a en direcci�n nordeste, alej�ndose de la "
        "cantera que queda al sur, acerc�ndose algo m�s a la ribera del Kandal, mientras prosigue "
        "su ascenso hacia la abad�a situada en la cima.\n");
    AddExit("nordeste", SHERAB("camino/cam15"));
    AddExit("suroeste", SHERAB("camino/cam13"));
}
