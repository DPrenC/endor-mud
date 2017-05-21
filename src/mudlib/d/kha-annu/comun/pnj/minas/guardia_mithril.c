/****************************************************************************
Fichero: guardia_mithril.c
Autor: Riberales
Fecha: 05/02/2006
Descripci�n: El guardi�n enano de las minas, secci�n mt.
****************************************************************************/


#include "path.h"
#include <properties.h>
#include <guild.h>

 inherit PNJ_MINAS("guardia_base");

 create()
 {
    ::create();


    SetStandard("un guardi�n enano","enano",([GC_GUERRERO: 92+random(6)]),GENDER_MALE);

    SetShort("un guardi�n enano");

    SetLong("Es uno de los guardias de la ciudad de Kha-annu enviados a las "
            "minas para su seguridad, pues son casi inimaginables los tesoros "
            "que esconden. �ste en particular, por los motivos de su coraza, "
            "dir�as que es responsable de la seguridad de la tercera "
            "planta.\n");

    AddWalkZones(HAB_TERCERA_MINAS(""));

    AddItem(ARMA_MINAS("hacha_guardia"),REFRESH_REMOVE,([
            P_LONG: "Es el hacha reglamentaria de los guardianes de la mina "
                    "de Kha-annu. Un hacha de acero, con su empu�adura "
                    "ba�ada en mithril, as� como la cabeza de la misma.\n",
            P_WC: 9]),SF(wieldme));

    AddItem(PROT_MINAS("coraza_guardia"),REFRESH_REMOVE,([
            P_LONG: "Es la armadura reglamentaria de los guardias que "
                    "patrullan por las minas enanas. Es una coraza de acero, "
                    "bastante resistente a simple vista, y decorada con unos "
                    "extra�os s�mbolos forjados con mithril.\n",
            P_AC: 10]),SF(wearme));
}
