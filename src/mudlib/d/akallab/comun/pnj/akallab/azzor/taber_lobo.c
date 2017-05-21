/*
DESCRIPCION : La tabernera de la posada Lobo de Mar
FICHERO     : /d/akallab/comun/pnj/akallab/azzor/taber_lobo.c
MODIFICACION:
06-12-05 [Riberales] Creacion
16-09-07 [Angor] Rehecha
*/

#include "path.h"
#include <properties.h>
#include <combat.h>
inherit NPC;

create()
{
    ::create();
    seteuid(getuid());
    SetStandard("Molly", "orco",30,GENERO_FEMENINO);
    SetName("Molly");
    SetShort("Molly la tabernera");
    SetLong("Molly es la joven orca tabernera de la posada Lobo de Mar. Es corpulenta, "
        "descarada y malhablada. Viste un delantal sobre un ajustado vestido de cuero que "
        "marca aún más sus grandes pechos. Sus orejas están llenas de pendientes y lleva un "
        "piercing en el labio. Una cicatriz en su mejilla, muestra que está acostumbrada a "
        "tratar con rudos marinos y a lidiar con los borrachos que se resisten a dejar la "
        "taberna a la hora de cerrar.\n");
    SetIds(({"molly","tabernera","la tabernera","orca"}));
    InitChats(4,({"Molly gruñe: ¡Maldita sea Sally la gorda y su taberna, me roba todos mis "
            "clientes!\n",
        "Molly limpia la barra con un paño.\n",
        "Molly escupe en un vaso y pasa a limpiarlo con un paño.\n",
        "Molly abre la espita de un gran barril y llena una jarra.\n",
        "Molly recoge varias jarras vacías de la barra.\n",
        "La tabernera te mira.\n"}));
    AddItem(ARMOUR,REFRESH_REMOVE,([
        P_SHORT: "un delantal",
        P_LONG: "Es un delantal de tela muy ordinario, pero que protege de manchas a su "
            "portador.\n",
        P_IDS: ({"delantal"}),
        P_ARMOUR_TYPE: AT_CORAZA,
        P_AC: 2,
        P_MATERIAL: M_TELA,
        P_WEIGHT:170]),
        SF(wearme));
}
