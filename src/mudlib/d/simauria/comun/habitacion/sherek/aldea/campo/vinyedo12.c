/* Archivo:         vi�edo12.c
Autor:           Yalin y Lug
Descripci�n:     vi�edos en la aldea de Sloch
Fecha:           30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al este, un muro cierra el paso. En las dem�s "
        "direcciones se extiende el vi�edo.\n");
    AddDetail(({"muro","tapia","valla"}), "Es un muro de unos 2 metros de "
        "altura, hecho de piedra, para impedir el paso de los perros y los "
        "ni�os que juegan en la pradera vecina.\n");
    AddExit("norte", SHERALD("campo/vinyedo22"));
    AddExit("sur", SHERALD("campo/vinyedo07"));
    AddExit("oeste", SHERALD("campo/vinyedo11"));
}
