/* Archivo        pastos01.c
   Autor:         Yalin y Lug
   Fecha:         14/05/2006
   Descripci�n:   pastos de la granja de la aldea (proyecto)
*/


#include "path.h"
inherit SHERALD("pastos/pastos");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Al sur ves una empalizada que separa este "
        "lugar de los campos de cultivo y al este puedes ver el r�o; hacia "
        "el norte y hacia el oeste contin�an los pastos.\n");
    SetIntNoise("Oyes la corriente del r�o, el canto de alg�n p�jaro y los "
        "animales mientras pacen.\n");
    AddDetail(({"rio","r�o","este"}),"Ves el r�o Kandal que todav�a no "
        "adquiere las proporciones que tendr� en las llanuras m�s cerca del "
        "mar. En esta zona describe cerradas curvas entre las rocas y la "
        "corriente es bastante fuerte.\n");
    AddDetail(({"empalizada","valla","sur"}), "es una empalizada bastante "
        "alta que impide el paso de los animales hacia el sembrado.\n");
    AddExit("norte", SHERALD("pastos/pastos02"));
    AddExit("oeste", SHERALD("pastos/pastos00"));
    pongo();
}
