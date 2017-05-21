/*
DESCRIPCION : mozo del meson del Negro
FICHERO     : /d/akallab/comun/pnj/akallab/azzor/negro_comedor.c
MODIFICACION:
24-09-07 [Angor] Creacion
*/

#include "path.h"
#include <properties.h>
#include <guild.h>
#include <combat.h>
inherit NPC;

public create()
{
    ::create();

    seteuid(getuid());

    SetStandard("Koen", "orco",([GC_NINGUNO:15]),GENDER_MALE);
    SetShort("Koen brazoslargos");
    SetLong("Koen es un joven orco que trabaja de camarero, chico de recados y "
    "lo que se tercie en el mesón del Negro del puerto de Azzor. Es delgado y "
    "larguilucho lo que le ha valido el apodo de 'brazoslargos' por el que la "
    "mayoría lo conocen. Aunque parece algo patoso, no es nada torpe. Lleva un "
    "viejo trapo en el hombro y un delantal.\n");

    SetIds(({"Koen","camarero","orco","brazoslargos"}));

    InitChats(2,({
            "Koen corre a la cocina cargado con varios platos vacios.\n",
            "Koen llega con una gran bandeja humeante.\n",
            "Koen escupe en un vaso y pasa a limpiarlo con un trapo.\n",
            "Koen limpia unas mesas.\n",
            "Koen va a la despensa y vuelve con dos grandes jarras de cerveza.\n",
            "Koen grita: '¿Negro, nos queda pulpo?\n",
            "Koen pregunta: '¿Para quién era la ración de cebiche?\n",
            "Koen grita: '¡Oye Negro, ve preparando una de salmón!\n",
            "Koen sirve a un cliente.\n",
            "Koen le dice a un cliente: '¿Qué el vino es caro? ¡Beba agua del mar que queda ahí al lado y es más barata!\n",
            "Koen le dice a un cliente: '¿Qué? ¿era fuerte el 'mataviejas'?\n",
            "Koen te mira.\n"}));
    AddItem(ARMOUR,REFRESH_REMOVE,([
            P_SHORT: "un delantal",
            P_LONG: "Es un delantal de tela ordinario.\n",
            P_IDS: ({"delantal"}),
            P_ARMOUR_TYPE: AT_CORAZA,
            P_AC: 2,
            P_MATERIAL: M_TELA,
            P_WEIGHT:170]),
            SF(wearme));

}
