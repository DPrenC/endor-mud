/* Archivo:         vi�edo32.c
Autor:           Yalin y Lug
Descripci�n:     vi�edos en la aldea de Sloch
Fecha:           30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al este, un muro cierra el paso, mientras que al norte ves la "
        "pared trasera de una casa. En las dem�s direcciones se extiende el vi�edo.\n");
    AddDetail(({"muro","tapia","valla"}), "Es un muro de unos 2 metros de "
        "altura, hecho de piedra, para impedir el paso de los perros y los "
        "ni�os que juegan en la pradera vecina.\n");
    AddDetail(({"pared","casa"}),"No ves m�s que una pared de adobe, lisa y sin ventanas.\n");
    AddExit("sur", SHERALD("campo/vinyedo22"));
    AddExit("oeste", SHERALD("campo/vinyedo31"));
    AddItem(PNJ("sherek/aldea/guardian"),REFRESH_DESTRUCT,1);
}
