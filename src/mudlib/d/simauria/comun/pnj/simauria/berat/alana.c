/*
DESCRIPCION :  tendera alana
FICHERO     : /d/simauria/comun/pnj/simauria/berat/alana.c
MODIFICACION: 4-11-99 [Icaro];2-06-99 [Maler] eliminados los retornos de carro
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;

create()
{
    ::create();
    SetStandard("Alana","humano",([GC_LUCHADOR: 15]),GENERO_FEMENINO);
    SetShort("Alana");
    SetLong("Alana es una humana de complexión fuerte, su mirada dulce contrasta con su tosca "
        "personalidad.\n Es la esposa del herrero Kolkson, y ahora debe de estar "
        "paseando por el pueblo.\n");
    AddId(({"mujer", "esposa", "humana"}));
    SetAlign(100);
    SetCitizenship("berat");
    SetGoChance(35);
    AddWalkZones(SIMA("berat"));
}
