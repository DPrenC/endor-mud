/****************************************************************************
Fichero: guardia_hierro
Autor: Riberales
Fecha: 05/02/2006
Descripci�n: El guardi�n enano de las minas, secci�n hierro.
****************************************************************************/


#include "path.h"
#include <properties.h>
#include <guild.h>

inherit PNJ_MINAS("guardia_base");

create()
{
    ::create();


    SetStandard("un guardi�n enano","enano",([GC_GUERRERO: 75+random(6)]),GENDER_MALE);

    SetShort("un guardi�n enano");

    SetLong("Es uno de los guardias de la ciudad de Kha-annu enviados a las "
            "minas para su seguridad, pues son casi inimaginables los tesoros "
            "que esconden. �ste en particular, por su coraza, dir�as que se "
            "encarga de la primera planta.\n");

    //AddWalkZones(HAB_PRIMERA_MINAS(""));
    AddWalkZones("/d/kha-annu/comun/habitacion/kha-annu/minas/planta01");

    AddItem(ARMA_MINAS("hacha_guardia"),REFRESH_REMOVE,([
            P_LONG: "Es el hacha reglamentaria de los guardianes de la mina. "
                    "Un hacha de acero, y en este caso, sin ning�n tipo de "
                    "distintivo.\n",
            P_WC: 7]),SF(wieldme));

    AddItem(PROT_MINAS("coraza_guardia"),REFRESH_REMOVE,([
            P_LONG: "Es la armadura reglamentaria de los guardias que "
                    "patrullan por las minas enanas. Es una coraza de acero, "
                    "bastante resistente a simple vista, y en este caso sin "
                    "ning�n tipo de decoraci�n.\n",
            P_AC: 7]),SF(wearme));
}
