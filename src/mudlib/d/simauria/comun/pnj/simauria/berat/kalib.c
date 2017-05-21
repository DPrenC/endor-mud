/*
DESCRIPCION : tendero Kalib
FICHERO     : /d/simauria/comun/pnj/simauria/berat/kalib.c
MODIFICACION: 4-11-99 [Icaro];2-6-00 [Maler] eliminados retornos de carro, susti-
tuido AddId por SetIds
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
#include <guild.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Kalib","humano",([ GC_NINGUNO:15 ]),GENERO_MASCULINO);
    AddAdjective("joven");
    SetIds(({"tendero","kalib","tendero kalib"}));
    SetShort("el tendero Kalib");
    SetLong("Es Kalib el tendero. Es un humano joven y apuesto. A juzgar por su tienda, parece "
        "que le gusta viajar. Parece muy amable y respetuoso.\n");
    Set(P_CANT_LURE,1);
    SetCitizenship("berat");
}
