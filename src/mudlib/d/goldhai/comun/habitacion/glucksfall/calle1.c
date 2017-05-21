#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit GROOM;

create()
{
    ::create();
    SetIntShort("la avenida Djorn");
    SetIntLong("Te encuentras en la parte norte de la avenida Djorn de Glucksfall. Al Norte "
        "est� la posada de la ciudad, un lugar bastante cutre y solitario. Al Noroeste y al "
        "Este ves las entradas a las torres que te permiten subir por las murallas, mientras "
        "que al oeste hay una herrer�a.\n");
    SetIndoors(0);
    AddExit("noroeste","torre1");
    AddExit("sur","calle2");
    AddExit("norte","posada");
    AddExit("este","torre2");
    AddExit("oeste","herreria");
    AddDoor("oeste","la puerta de la herrer�a",
        "Es una gruesa puerta de hierro, como era de esperar en un sitio como �ste. Por "
        "supuesto, aqu� nadie se f�a de nadie.\n",
        ({"puerta","puerta oeste","puerta de herrer�a","puerta de la herrer�a"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND:SND_SUCESOS("cerrar_metalica"),
        P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_metalica"),
        P_MATERIAL:M_HIERRO,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
    AddItem(PNJ("glucksfall/sapor"),REFRESH_DESTRUCT);
    SetLocate("Glucksfall");
}
