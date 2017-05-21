/* Archivo:         viñedo05.c
Autor:           Yalin y Lug
Descripción:      viñedos en la aldea de Sloch
Fecha:            30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el oeste y el sur te impide el paso el "
        "cauce del río Kandal. En las demás direcciones continúan los viñedos.\n");
    SetIntNoise("Escuchas el fuerte ruído del agua al correr por entre las "
        "rocas del cauce del río Kandal.\n");
    AddDetail(({"rio","río","cauce","oeste","sur"}),"Ves el cauce "
        "pedregoso del río Kandal, que viene del noroeste, y hace aquí una "
        "curva para continuar hacia el este, bordeando la aldea. La "
        "corriente baja con fuerza y hace bastante estruendo.\n");
    AddExit("este", SHERALD("campo/vinyedo06"));
    AddExit("norte", SHERALD("campo/vinyedo03"));
}
