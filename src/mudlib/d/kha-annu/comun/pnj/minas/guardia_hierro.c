/****************************************************************************
Fichero: guardia_hierro
Autor: Riberales
Fecha: 05/02/2006
Descripción: El guardián enano de las minas, sección hierro.
****************************************************************************/


#include "path.h"
#include <properties.h>
#include <guild.h>

inherit PNJ_MINAS("guardia_base");

create()
{
    ::create();


    SetStandard("un guardián enano","enano",([GC_GUERRERO: 75+random(6)]),GENDER_MALE);

    SetShort("un guardián enano");

    SetLong("Es uno de los guardias de la ciudad de Kha-annu enviados a las "
            "minas para su seguridad, pues son casi inimaginables los tesoros "
            "que esconden. Éste en particular, por su coraza, dirías que se "
            "encarga de la primera planta.\n");

    //AddWalkZones(HAB_PRIMERA_MINAS(""));
    AddWalkZones("/d/kha-annu/comun/habitacion/kha-annu/minas/planta01");

    AddItem(ARMA_MINAS("hacha_guardia"),REFRESH_REMOVE,([
            P_LONG: "Es el hacha reglamentaria de los guardianes de la mina. "
                    "Un hacha de acero, y en este caso, sin ningún tipo de "
                    "distintivo.\n",
            P_WC: 7]),SF(wieldme));

    AddItem(PROT_MINAS("coraza_guardia"),REFRESH_REMOVE,([
            P_LONG: "Es la armadura reglamentaria de los guardias que "
                    "patrullan por las minas enanas. Es una coraza de acero, "
                    "bastante resistente a simple vista, y en este caso sin "
                    "ningún tipo de decoración.\n",
            P_AC: 7]),SF(wearme));
}
