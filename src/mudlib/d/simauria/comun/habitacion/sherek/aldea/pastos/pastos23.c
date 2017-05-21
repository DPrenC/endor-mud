/* Archivo        pastos18.c
   Autor:         Yalin y Lug
   Fecha:         14/05/2006
   Descripci�n:   pastos de la granja de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("pastos/pastos");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al este puedes ver el r�o; al norte los "
        "pastos terminan en un tupido bosque que te impide el paso. En las "
        "dem�s direcciones se extienden los pastos.\n");
    SetIntNoise("Oyes la corriente del r�o, el canto de alg�n p�jaro y los "
        "animales mientras pacen.\n");
    AddDetail(({"bosque"}),"es un bosque extremadamente espeso que impide "
        "que se pueda acceder a �l desde los pastos limit�ndolos al norte.\n");
    AddDetail(({"rio","r�o","este"}),"Ves el r�o Kandal que todav�a no "
        "adquiere las proporciones que tendr� en las llanuras m�s cerca del "
        "mar. En esta zona describe cerradas curvas entre las rocas y la "
        "corriente es bastante fuerte.\n");
    AddExit("sur", SHERALD("pastos/pastos18"));
    AddExit("oeste", SHERALD("pastos/pastos22"));
    pongo();
}
