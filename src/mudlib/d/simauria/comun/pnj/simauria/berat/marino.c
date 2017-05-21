/*
DESCRIPCION : marino
FICHERO     : /d/simauria/comun/pnj/simauria/berat/marino.c
MODIFICACION: 4-11-99 [Jorus];10-6-00 [Maler] eliminados retornos de carro,
sustituidos los defines del sys .h
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <combat.h>
#include <properties.h>

inherit NPC;

create() {
    ::create();

    SetStandard("un marino","humano",20+d3(),GENDER_MALE);
    SetShort("un marino");
    SetLong("Ves a un marino que esta pasando su tiempo libre paseando por Berat.\n"
    " Parece de constitución fuerte, las tareas del mar le habrán servido para "
    "endurecerse físicamente.\n");
    SetCitizenship("berat");
    SetGoChance(40);

    AddId(({"humano","marino","marinero"}));
    AddWalkZones(SIMA("berat"));
}
