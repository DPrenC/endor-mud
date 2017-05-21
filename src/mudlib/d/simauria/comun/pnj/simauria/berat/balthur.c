/*
DESCRIPCION : tabernero Balthur
FICHERO     : /d/simauria/comun/pnj/simauria/berat/balthur.c
MODIFICACION: 4-11-99 [Icaro];2-06-00 [Maler]eliminados los retornos de carro.
Sustituido el inherit de /std/npc a NPC definido en el sys
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Balthur","humano",13,GENERO_MASCULINO);
    SetShort("El tabernero Balthur");
    SetLong("Puedes ver a Balthur, el obeso tabernero de la taberna Rosa De Los Vientos. "
        "Parece muy agradable y entrañable. Aun así no le gustan los folloneros.\n");
    SetIds(({"humano","Balthur","tabernero","tabernero balthur"}));
    SetCitizenship("berat");
    Set(P_CANT_LURE,1);
}
