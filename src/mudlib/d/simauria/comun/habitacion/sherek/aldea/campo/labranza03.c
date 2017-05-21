/* Archivo        labranza02.c
Autor:         Yalin y Lug
Fecha:         14/05/2006
Descripción:   campos de cultivo de la aldea (proyecto)
*/

#include "path.h"
inherit SHERALD("campo/huerta");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el norte y el este continúan los campos "
        "de cultivo. Hacia el este está la calle que cruza la granja, y, al "
        "sur, puedes ver los muros del molino de agua de la aldea.\n");
    AddDetail(({"pared"}),"Es la pared de un molino de agua que mueve el "
        "río Kandal.\nEstá construída con maderos fuertemente ensamblados.\n");
    AddDetail(({"molino"}),"Si quieres verlo mejor has de salir a la calle y "
        "luego ir al sur.\n");
    AddExit("norte", SHERALD("campo/labranza00"));
    AddExit("oeste", SHERALD("granja/granja02"));
    AddExit("este", SHERALD("campo/labranza04"));
    AddItem(PNJ("sherek/aldea/guardian"),REFRESH_DESTRUCT,1);
}
