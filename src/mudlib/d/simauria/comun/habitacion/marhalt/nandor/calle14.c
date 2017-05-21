/****************************************************************************
Fichero: calle14.c
Autor: Ratwor
Fecha: 01/11/2006
Descripci�n:  La calle Narwhald.
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
    SetIntLong("Contin�a la calle Narwhald hacia el este y el suroeste con sus siempre "
        "presentes plantas y guijarros.\n El local del norte parece una sastrer�a, "
        "mientras que al sur desentona una destartalada caba�a, que tiene pinta de ser "
        "un almac�n de algo.\n");
    SetIntNoise("Por esta zona no se escucha nada fuera de lo normal.\n");
    SetIntSmell("Un fuerte olor a pieles parece provenir de la sastrer�a del norte.\n");
    SetIndoors(0);
    AddDetail(({"guijarros","suelo"}), "Unos redondeados y brillantes guijarros cubren el"
        " suelo de la calle.\n");
    AddDetail(({"plantas","maceteros", "flores"}),
        "Distintas plantas y maceteros inundan la calle:\n concretamente por esta zona "
        "predominan unos curiosos cipreses peque�itos, aunque est�n acompa�ados de laureles.\n");
    AddDetail(({"cipreses","cipr�s", "Cipres", "laurel", "laureles"}), "Son peque�os para"
        " lo t�pico de su especie.\n");
    AddDetail(({"cartel","letrero"}), "Pertenece a la tienda del norte.\n");
    AddReadMsg(({"letrero","cartel"}), "'Sastrer�a'\n");
    AddDetail(({"tienda", "sastreria", "sastrer�a"}), "Venden ropa, pero mejor entra "
        "a verlo.\n");
    AddDetail(({"caba�a", "almacen", "almac�n"}), "Nada importante, solo una casucha de "
        "madera que desentona un poco con el resto de la calle.\n");
    AddExit("suroeste","./calle15");
    AddExit("este","./calle13");
    AddExit("norte","./tiendas/sastreria");
    AddDoor("norte", "la puerta de la sastrer�a",
    "Es la puerta que da entrada a la sastrer�a.\n",
    ({"puerta", "puerta de la sastrer�a", "puerta de la sastreria"}),
    ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
    P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}
