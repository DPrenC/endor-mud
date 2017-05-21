/*
DESCRIPCION :  herrero
FICHERO     : herrero.c
MODIFICACION: 17-07-00 [Maler] Creacion
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <rooms.h>
#include <properties.h>
inherit NPC;

create()
{
    ::create();
   SetStandard("goral","humano",25,GENERO_MASCULINO);
    SetShort("Goral");
    SetLong("Goral es un humano bastante bajo. Sus poderosos músculos se tensan cada vez que "
        "coje alguna pesada arma de la estantería, para mostrársela a algún posible comprador.\n");
    SetIds(({"armero","goral","herrero","tendero"}));
    SetAggressive(0);
    Set(P_CANT_LURE,1);
    SetAlign(0);
}
