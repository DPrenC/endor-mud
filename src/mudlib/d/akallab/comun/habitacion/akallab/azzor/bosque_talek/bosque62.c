/*
DESCRIPCION  : bosque de Talek
FICHERO      : bosque61.c
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
    SetIntLong("Te hallas en la orilla del río Kuneii que divide este bosque "
        "en dos a su paso.\n" + QueryIntLong());
    AddDetail(({"río","kuneii","río kuneii","río Kuneii"}),"El río Kuneii "
        "recorre este valle de este a oeste. Es un río caudaloso plagado de "
        "rápidos que hacen que no sea navegable. Nace en el vecino valle de "
        "Zarkam y a través de las Cataratas de Nurr atraviesa las Montañas "
        "Negras y entra en el valle. Desemboca al sur de la ciudad de Azzor.\n");
    SetIntSmell("Hueles un fresco aroma a lavanda...\n");
    AddExit("oeste",BOSQUE_TALEK("bosque61"));
    AddExit("este",BOSQUE_TALEK("bosque63"));
}

