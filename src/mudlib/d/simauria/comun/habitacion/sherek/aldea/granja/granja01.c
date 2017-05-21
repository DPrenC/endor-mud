/* Archivo        granja01.c
   Autor:         Yalin y Lug
   Fecha:         12/05/2006
   Descripción:   Calle de la granja de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("granja/granja");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al norte asciende la calle, mientras que "
        "continúa su descenso hacia el sur. al este hay unos campos de "
        "labranza y al oeste puedes ver un establo. Al noreste ves la casa de "
        "los administradores.\n");
    AddDetail(({"casa","este","casa de los administradores"}),"es una casa "
        "bastante grande construida en piedra y pintada de blanco. Tiene "
        "planta baja y piso superior y está ligeramente alzada sobre el "
        "nivel del suelo, lo que te indica que aquí suele haber inundaciones.\n");
    AddDetail(({"campos","labranza","campos de labranza"}),"Son las tierras "
        "pertenecientes a la granja donde se cultivan varios tipos de "
        "cereales.\n");
    AddDetail(({"cereales","cereal"}),"Hay trigo, mijo, cebada y algún otro "
        "que no reconoces.\n");
    AddDetail(({"trigo","mijo","cebada"}),"Un simple tipo de cereal "
        "cultivado en el campo.\n");
    AddExit("norte", SHERALD("granja/granja00"));
    AddExit("sur", SHERALD("granja/granja02"));
    AddExit("este", SHERALD("campo/labranza00"));
    AddExit("oeste", SHERALD("granja/establo01"));
}
