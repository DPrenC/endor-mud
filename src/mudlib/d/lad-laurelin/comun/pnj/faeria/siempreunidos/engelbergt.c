/****
Fichero: engelbergt.c
Autor: kastwey@simauria
Descripción: El posadero del siempreunidos.
Creación: 03/12/2004
***/

#include "path.h"
#include <combat.h>
#include <properties.h>

inherit STD_FAERIA("pnj_base_faeria");

create()
{
    ::create();
   SetStandard("engelbergt", "elfo", 15+random(6), 1);
    AddId("posadero_faeria");
    AddId("posadero");
    SetShort("Engelbergt, el posadero");
    SetLong(W("Engelbergt es el posadero del pueblo.\n"
    "Es un elfo alto, más alto incluso que la mayoría de los elfos. Tiene una melena que le cae por encima de los hombros.\n"));
    SetLongDesprecio(QueryLong() + "Cuando te mira, notas como su cara se transforma en un rictus de odio.\n");
    AddItem("/std/armour", REFRESH_REMOVE,
        ([
            P_SHORT: "un amuleto",
            P_LONG: "Es un amuleto, hecho con el colmillo de algún animal. Este amuleto identifica a quien lo lleve como miembro del gremio de guardabosques.\n",
            P_ARMOUR_TYPE: AT_AMULETO,
            P_AC: 0,
            P_VALUE: 100,
            P_GENDER: 1
        ]), SF(wearme));
}
