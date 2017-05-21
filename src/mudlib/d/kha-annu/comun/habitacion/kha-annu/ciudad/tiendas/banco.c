/****************************************************************************
Fichero: /d/kha-annu/comun/habitacion/kha-annu/ciudad/tiendas/banco.c
Autor: Lug y Yalin
Fecha: 29/04/2007
Descripción: Oficina de la hermandad de banqueros en Kha-annu
****************************************************************************/
#include "path.h"
inherit BANK;

create()
{
    ::create();
    SetLocate("la ciudad de Kha-annu");
    SetIntShort("el banco de Kha-annu");
    SetIntLong("Ésta es la oficina bancaria de "
        "la ciudad de Kha-annu.\nAquí puedes abrir o cancelar una cuenta, "
        "así como gestionarla si la tienes: ingresar o retirar dinero, "
        "comprobar su estado, etc.\n");
    SetIntBright(50);
    SetKeeper(PNJ("banquero"));
    SetBankName("kha-annu");
    SetAssociatedRooms("./taquillas");
    SetLastDest(CIUDAD+"kilok5");
    SetNotifyExits(({"oeste"}));
    AddExit("oeste",CIUDAD+"kilok5");
    AddExit("sur","./taquillas");
}

