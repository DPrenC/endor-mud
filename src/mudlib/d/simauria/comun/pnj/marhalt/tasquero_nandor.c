/****************************************************************************
Fichero: tasquero_nandor.c
Autor: Ratwor
Fecha: 05/11/2006
Descripción: el tabernero de la tasca de nandor
****************************************************************************/

#include <properties.h>
#include <gremios.h>
#include "./path.h"

inherit NPC;
create()
{
    ::create();
    AddId(({"tarno", "Tarno", "tabernero", "tasquero"}));
    SetStandard("Tarno", "humano", ([GC_TORPE:11]), GENDER_MALE);
    SetShort("Tarno el tabernero");
    SetLong("Tarno es una excelente persona, risueña, alegre y humilde. Su escasa "
        "corpulencia no le permitía dedicarse al campo ni a la guerra, con lo que tuvo "
        "que sacar su ingenio y buscarse la vida de una forma más cómoda, así "
        "decidió montarse esta pequeña taberna.\n Por su forma de ser tiene a sus "
        "clientes como si fueran de la familia,  y muchos de ellos se pasan allí dentro "
        "casi todo el día conversando con él.\n");
    Set(P_CANT_LURE,1);
    SetAlign(400);
    SetWeight(60000);
    SetSmell("Huele a taberna.\n");
    InitChats(3,({"Tarno limpia una mesa.\n", "tarno te mira.\n",
        "El tabernero sirve una cerveza para un cliente.\n",
        "Tarno sonríe amistosamente.\n",
        "Tarno remueve unas olivas de un cuenco.\n"}));
    InitAChats(7,({"Tarno grita.\n", "tarno se intenta tapar la cabeza.\n"}));
    SetCitizenship("nandor");
}
