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
    SetIntLong("Frente a ti pasa el caudaloso río Kuneii. Observas como se "
        "aleja hacia el este en dirección al fondo del valle de Azzor "
        "dejando atrás este bosque.\n"+QueryIntLong());
    AddDetail(({"río","kuneii","río kuneii","río Kuneii"}),"El río Kuneii "
        "recorre este valle de este a oeste. Es un río caudaloso plagado de"
        "rápidos que hacen que no sea navegable. Nace en el vecino valle de "
        "Zarkam y a través de las Cataratas de Nurr atraviesa las Montañas "
        "Negras y entra en el valle. Desemboca al sur de la ciudad de Azzor.\n");
    SetIntSmell("Hueles el fresco aroma del bosque y la humedad del río.\n");
    AddExit("oeste",BOSQUE_TALEK("bosque62"));
    AddExit("sur",BOSQUE_TALEK("bosque59"));
    AddExit("suroeste",BOSQUE_TALEK("bosque58"));
}
