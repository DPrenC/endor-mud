/* Archivo        pastos03.c
   Autor:         Yalin y Lug
   Fecha:         14/05/2006
   Descripción:   pastos de la granja de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("pastos/pastos");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al sureste puedes ver la parte trasera de la "
        "casa de los administradores. En las demás direcciones se extienden "
        "los pastos.\n");
    AddDetail(({"empalizada","valla","sur"}),"es una empalizada bastante "
        "alta que impide el paso de los animales hacia el sembrado.\n");
    AddDetail(({"casa","oeste","casa de los administradores"}),"es una casa "
        "bastante grande construida en piedra y pintada de blanco. Tiene "
        "planta baja y piso superior y está ligeramente alzada sobre el "
        "nivel del suelo, lo que te indica que aquí suele haber inundaciones.\n");
    AddExit("norte", SHERALD("pastos/pastos06"));
    AddExit("sur", SHERALD("pastos/pastos00"));
    AddExit("oeste", SHERALD("pastos/pastos04"));
    AddExit("este", SHERALD("pastos/pastos02"));
    pongo();
}
