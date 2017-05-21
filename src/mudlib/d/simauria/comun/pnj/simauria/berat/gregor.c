/*
DESCRIPCION : tabernero Gregor
FICHERO     : /d/simauria/comun/pnj/simauria/berat/gregor.c
MODIFICACION: 4-11-99 [Icaro];2-6-00 [Maler] sustituido /std/npc por NPC, elimi-
nados los retornos de carro
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Gregor","humano",24,GENERO_MASCULINO);
    SetShort("Gregor el tabernero");
    SetLong("Gregor es un fornido humano, de unos dos metros, con una enorme cicatriz en la "
        "cara. Se ha ganado el respeto de todos sus clientes, por lo que no sería buena idea "
        "meterse con él.\n");
    SetIds(({"Gregor","tabernero"}));
    Set(P_CANT_LURE,1);
    SetAlign(50);
    SetCitizenship("berat");
}
