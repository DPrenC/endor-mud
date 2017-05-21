/*
DESCRIPCION : mercader
FICHERO     : /d/simauria/comun/pnj/simauria/berat/campes1.c
MODIFICACION: 4-11-99 [Jorus];2-6-00 [Maler] eliminados los retornos de carro.
Puestas mayúsculas en la desc;sustituido /std/npc por NPC
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>

inherit NPC;

create() {
    ::create();
    SetCitizenship("berat");
    SetStandard("una mercader","humano",10+d3(),GENDER_FEMALE);
    SetShort("una mercader");
    SetLong("Ves a una mercader que viene de realizar sus transacciones comerciales.\n");

    SetGoChance(50);
    AddWalkZones(SIMA("berat"));
    SetIds(({"humana","mercader"}));

}
