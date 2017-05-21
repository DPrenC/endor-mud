/* Archivo:         vi�edo05.c
Autor:           Yalin y Lug
Descripci�n:      vi�edos en la aldea de Sloch
Fecha:            30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el oeste y el sur te impide el paso el "
        "cauce del r�o Kandal. En las dem�s direcciones contin�an los vi�edos.\n");
    SetIntNoise("Escuchas el fuerte ru�do del agua al correr por entre las "
        "rocas del cauce del r�o Kandal.\n");
    AddDetail(({"rio","r�o","cauce","oeste","sur"}),"Ves el cauce "
        "pedregoso del r�o Kandal, que viene del noroeste, y hace aqu� una "
        "curva para continuar hacia el este, bordeando la aldea. La "
        "corriente baja con fuerza y hace bastante estruendo.\n");
    AddExit("este", SHERALD("campo/vinyedo06"));
    AddExit("norte", SHERALD("campo/vinyedo03"));
}
