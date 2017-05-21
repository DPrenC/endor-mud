/* Archivo:         labranza13.c
Autor:           Yalin y Lug
Descripci�n:     Cultivos en la granja de la aldea de Sloch
Fecha:           26/05/2006
*/

#include "path.h"
inherit SHERALD("campo/cereal");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"El sembrado est� cerrado por un muro al oeste. "
        "Puedes moverte por los campos en las dem�s direcciones.\n");
    AddDetail(({"muro","tapia","valla"}), "Es un muro de unos 2 metros de "
        "altura, hecho de piedra, para impedir el paso de los perros y los "
        "ni�os que juegan en la pradera vecina.\n");
    AddExit("sur", SHERALD("campo/labranza14"));
    AddExit("norte", SHERALD("campo/labranza12"));
    AddExit("este", SHERALD("campo/labranza09"));
}
