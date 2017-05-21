/* Archivo        pastos04.c
   Autor:         Yalin y Lug
   Fecha:         14/05/2006
   Descripci�n:   pastos de la granja de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("pastos/pastos");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al sur puedes ver un lateral de la casa de "
        "los administradores. En las dem�s direcciones se extienden los "
        "pastos y, hacia el oeste est� la salida al camino.\n");
    AddDetail(({"casa","sur","casa de los administradores"}),"es una casa "
        "bastante grande construida en piedra y pintada de blanco. Tiene "
        "planta baja y piso superior y est� ligeramente alzada sobre el "
        "nivel del suelo, lo que te indica que aqu� suele haber inundaciones.\n");
    AddExit("norte", SHERALD("pastos/pastos05"));
    AddExit("oeste", SHERALD("calles/caminogranja06"));
    AddExit("este", SHERALD("pastos/pastos03"));
    pongo();
}
