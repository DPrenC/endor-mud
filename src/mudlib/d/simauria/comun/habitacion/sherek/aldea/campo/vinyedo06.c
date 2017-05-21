/* Archivo:         vi�edo06.c
Autor:            Yalin y Lug
Descripci�n:     vi�edos en la aldea de Sloch
Fecha:           30/05/2006
*/

#include "path.h"
inherit SHERALD("campo/vinyedo");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el este te impide el paso la maleza del "
        "bajo monte, al sur est� el cauce del r�o Kandal. En las dem�s "
        "direcciones contin�an los vi�edos.\n");
    SetIntNoise("Escuchas el fuerte ru�do del agua al correr por entre las "
        "rocas del cauce del r�o Kandal.\n");
    AddDetail(({"rio","r�o","cauce","sur"}),"Ves el cauce pedregoso "
        "del r�o Kandal, la corriente baja con fuerza y hace bastante "
        "estruendo.\n");
    AddDetail(({"este","monte","bajo monte","maleza"}),"es una espesura de arbustos "
        "y malezas que no te dejan avanzar m�s all� de donde est�s.\n");
    AddExit("oeste", SHERALD("campo/vinyedo05"));
    AddExit("norte", SHERALD("campo/vinyedo04"));
    AddItem(PNJ("sherek/aldea/aldeanoc"),REFRESH_DESTRUCT,2);
}
