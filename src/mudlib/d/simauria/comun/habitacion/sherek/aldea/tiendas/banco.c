/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/casas/banco
Autor: Lug y Yalin
Fecha: 25/04/2007
Descripción: Banco en la aldea de Sloch
****************************************************************************/

#include "path.h"
inherit BANK;

create ()
{
    ::create();
    SetLocate("la aldea de Sloch");
    SetBankName("sloch");
    SetKeeper(PNJ("sherek/aldea/banquero"), REFRESH_DESTRUCT,1);
    AddItem(PNJ("sherek/aldea/guardian2"),REFRESH_DESTRUCT,2);
    AddExit("sudeste",SHERALD("calles/plazoleta"));
}
