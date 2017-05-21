/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque56.c
MODIFICACION : 13-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_TALEK("bosque");

create()
{
    ::create();
   SetIntShort("la orilla del río");
    SetIntLong("Te encuentras en la orilla del río Kuneii que cruza este "
        "bosque de Talek.\n"+QueryIntLong()+"Al oeste de aquí, un puente "
        "de piedra permite cruzar el río.\n");
    AddDetail(({"puente","puente de piedra"}),"Al oeste de aquí, un puente "
        "de piedra permite cruzar el río.\n");
    AddDetail(({"río","kuneii","río kuneii","río Kuneii"}),"El río Kuneii "
        "recorre este valle de este a oeste. Es un río caudaloso plagado de "
        "rápidos que hacen que no sea navegable. Nace en el vecino valle de "
        "Zarkam y a través de las Cataratas de Nurr atraviesa las Montañas "
        "Negras y entra en el valle. Desemboca al sur de la ciudad de Azzor.\n");
    SetIntSmell("Hueles un fresco aroma a lavanda...\n");
    AddExit("nordeste",BOSQUE_TALEK("bosque61"));
    AddExit("suroeste",BOSQUE_TALEK("camino15"));
    AddExit("este",BOSQUE_TALEK("bosque57"));
}

