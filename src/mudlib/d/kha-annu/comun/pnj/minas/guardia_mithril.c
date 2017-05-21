/****************************************************************************
Fichero: guardia_mithril.c
Autor: Riberales
Fecha: 05/02/2006
Descripción: El guardián enano de las minas, sección mt.
****************************************************************************/


#include "path.h"
#include <properties.h>
#include <guild.h>

 inherit PNJ_MINAS("guardia_base");

 create()
 {
    ::create();


    SetStandard("un guardián enano","enano",([GC_GUERRERO: 92+random(6)]),GENDER_MALE);

    SetShort("un guardián enano");

    SetLong("Es uno de los guardias de la ciudad de Kha-annu enviados a las "
            "minas para su seguridad, pues son casi inimaginables los tesoros "
            "que esconden. Éste en particular, por los motivos de su coraza, "
            "dirías que es responsable de la seguridad de la tercera "
            "planta.\n");

    AddWalkZones(HAB_TERCERA_MINAS(""));

    AddItem(ARMA_MINAS("hacha_guardia"),REFRESH_REMOVE,([
            P_LONG: "Es el hacha reglamentaria de los guardianes de la mina "
                    "de Kha-annu. Un hacha de acero, con su empuñadura "
                    "bañada en mithril, así como la cabeza de la misma.\n",
            P_WC: 9]),SF(wieldme));

    AddItem(PROT_MINAS("coraza_guardia"),REFRESH_REMOVE,([
            P_LONG: "Es la armadura reglamentaria de los guardias que "
                    "patrullan por las minas enanas. Es una coraza de acero, "
                    "bastante resistente a simple vista, y decorada con unos "
                    "extraños símbolos forjados con mithril.\n",
            P_AC: 10]),SF(wearme));
}
