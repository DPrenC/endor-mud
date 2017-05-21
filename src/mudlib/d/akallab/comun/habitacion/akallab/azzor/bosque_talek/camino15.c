/*
DESCRIPCION  : camino a traves del bosque de Talek
FICHERO      : camino15.c
MODIFICACION : 13-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntShort("la orilla del río");
    SetIntLong("El camino que cruza el bosque llega aquí a la orilla del "
        "caudaloso río Kuneii. Un puente de piedra al norte de aquí permite "
        "cruzar este río que divide al bosque de Talek en dos mitades. A "
        "causa de la humedad del río, aquí el bosque es mucho más verde y "
        "frondoso. A lo lejos se escucha el ruido de unas cataratas.\n");
    AddDetail(({"puente","puente de piedra"}),"Un ancho puente de piedra "
        "permite atravesar el caudaloso río Kuneii. Es un puente de varios "
        "ojos con gruesos pilares firmemente asentados en el cauce del río. "
        "Se haya en buen estado, aunque ya se nota el efecto de la humedad "
        "en él.\n");
    AddDetail(({"río","kuneii","río kuneii","río Kuneii"}),"El río Kuneii "
        "recorre este valle de este a oeste. Es un río caudaloso plagado de "
        "rápidos que hacen que no sea navegable. Nace en el vecino valle de "
        "Zarkam y a través de las Cataratas de Nurr atraviesa las Montañas "
        "Negras y entra en el valle. Desemboca al sur de la ciudad de Azzor.\n");
    SetIntNoise("A lo lejos se escucha el ruido de unas cataratas.\n");
    AddExit("nordeste",BOSQUE_TALEK("bosque56"));
    AddExit("norte",BOSQUE_TALEK("camino16"));
    AddExit("este",BOSQUE_TALEK("camino14"));
}
