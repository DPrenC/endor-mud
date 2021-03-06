/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/pradera/pradera50.c
Autor: Lug y Yalin
Fecha: 19/08/2006
Descripci�n: pradera al sur de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("pradera/pradera");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"El muro de la granja te cierra el paso hacia el "
        "este. En las dem�s direcciones contin�a la pradera.\n");
    AddDetail(({"muro","tapia","pared"}), "Es la pared trasera de las "
        "dependencias de la granja.\n");
    AddExit("norte", SHERALD("pradera/pradera40"));
    AddExit("sur", SHERALD("pradera/pradera60"));
    AddExit("oeste", SHERALD("pradera/pradera51"));
    poner_pnj();
}
