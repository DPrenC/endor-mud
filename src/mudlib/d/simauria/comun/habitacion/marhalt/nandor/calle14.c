/****************************************************************************
Fichero: calle14.c
Autor: Ratwor
Fecha: 01/11/2006
Descripción:  La calle Narwhald.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit SIM_ROOM;

create()
{
    ::create();
    SetLocate("Aldea de Nandor");
    SetIntShort("la calle Narwhald");
    SetIntLong("Continúa la calle Narwhald hacia el este y el suroeste con sus siempre "
        "presentes plantas y guijarros.\n El local del norte parece una sastrería, "
        "mientras que al sur desentona una destartalada cabaña, que tiene pinta de ser "
        "un almacén de algo.\n");
    SetIntNoise("Por esta zona no se escucha nada fuera de lo normal.\n");
    SetIntSmell("Un fuerte olor a pieles parece provenir de la sastrería del norte.\n");
    SetIndoors(0);
    AddDetail(({"guijarros","suelo"}), "Unos redondeados y brillantes guijarros cubren el"
        " suelo de la calle.\n");
    AddDetail(({"plantas","maceteros", "flores"}),
        "Distintas plantas y maceteros inundan la calle:\n concretamente por esta zona "
        "predominan unos curiosos cipreses pequeñitos, aunque están acompañados de laureles.\n");
    AddDetail(({"cipreses","ciprés", "Cipres", "laurel", "laureles"}), "Son pequeños para"
        " lo típico de su especie.\n");
    AddDetail(({"cartel","letrero"}), "Pertenece a la tienda del norte.\n");
    AddReadMsg(({"letrero","cartel"}), "'Sastrería'\n");
    AddDetail(({"tienda", "sastreria", "sastrería"}), "Venden ropa, pero mejor entra "
        "a verlo.\n");
    AddDetail(({"cabaña", "almacen", "almacén"}), "Nada importante, solo una casucha de "
        "madera que desentona un poco con el resto de la calle.\n");
    AddExit("suroeste","./calle15");
    AddExit("este","./calle13");
    AddExit("norte","./tiendas/sastreria");
    AddDoor("norte", "la puerta de la sastrería",
    "Es la puerta que da entrada a la sastrería.\n",
    ({"puerta", "puerta de la sastrería", "puerta de la sastreria"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}
