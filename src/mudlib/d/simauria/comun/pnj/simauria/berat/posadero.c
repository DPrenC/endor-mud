/*
DESCRIPCION : posadero Grenel
FICHERO     : /d/simauria/comun/pnj/simauria/berat/posadero.c
MODIFICACION: 4-11-99 [Icaro];10-6-00[Maler]quito retornos de carro;
Sustituyo AddId por SetIds pa q los coja todos;corrijo faltas
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
#include <guild.h>

inherit NPC;

create()
{
    ::create();
    SetStandard("Grenel","humano",([ GC_NINGUNO:10 ]),GENERO_MASCULINO);
    AddId(({"posadero","humano","grenel","Grenel", "viejo"}));
    SetShort("Grenel el posadero");
    SetLong("Grenel es un viejo humano que lleva toda su vida entre estas paredes. Es muy "
        "amable y respetuoso. Parece algo distraído e intranquilo.\n");
    SetCitizenship("berat");
}
