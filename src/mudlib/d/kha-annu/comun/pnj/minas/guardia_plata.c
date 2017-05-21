/****************************************************************************
Fichero: guardia_plata.c
Autor: Riberales
Fecha: 05/02/2006
Descripción: El guardián enano de las minas, sección plata.
****************************************************************************/


#include "path.h"
#include <properties.h>
#include <guild.h>

inherit PNJ_MINAS("guardia_base");

create()
{
    ::create();


    SetStandard("un guardián enano","enano",([GC_GUERRERO: 83+random(6)]),GENDER_MALE);

    SetShort("un guardián enano");
    SetLong("Es uno de los guardias de la ciudad de Kha-annu enviados a las "
            "minas para su seguridad, pues son casi inimaginables los tesoros "
            "que esconden. Éste en particular, por los motivos de su coraza, "
            "dirías que se encarga de la seguridad de la segunda planta.\n");

    AddWalkZones(HAB_SEGUNDA_MINAS(""));
    AddItem(ARMA_MINAS("hacha_guardia"),REFRESH_REMOVE,([
            P_LONG: "Es el hacha reglamentaria de los guardianes de las minas "
                    "enanas. Un hacha de acero, y en esta ocasión, con su "
                    "cabeza y su empuñadura bañados en plata.\n",
            P_WC: 8]),SF(wieldme));
    AddItem(PROT_MINAS("coraza_guardia"),REFRESH_REMOVE,([
            P_LONG: "Es la armadura reglamentaria de los guardias que "
                    "patrullan por las minas enanas. Es una coraza de acero, "
                    "bastante resistente a simple vista, y decorada con unos "
                    "extraños símbolos de la plata más brillante que jamás "
                    "hayas visto.\n",
            P_AC: 8]),SF(wearme));
}
