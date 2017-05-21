/* Archivo:         viñedo07.c
Autor:           Yalin y Lug
Descripción:     viñedos en la aldea de Sloch
Fecha:           30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Un muro de piedra cierra el paso al sur y al "
        "este. En las demás direcciones se extiende el viñedo.\n");
    AddDetail(({"muro","tapia","valla"}),"Es un muro de unos 2 metros de "
        "altura, hecho de piedra, para impedir el paso de los perros y los "
        "niños que juegan en la pradera vecina.\n");
    AddExit("norte", SHERALD("campo/vinyedo12"));
    AddExit("oeste", SHERALD("campo/vinyedo01"));
}
