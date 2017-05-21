/*
DESCRIPCION  : camino a traves del bosque de Talek
FICHERO      : camino16.c
MODIFICACION : 13-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntShort("un puente sobre el río Kuneii");
    SetIntLong("Estás sobre un ancho puente de piedra que permite atravesar "
        "el caudaloso río Kuneii que avanza hacia el fondo del valle en el "
        "este. Es un puente de varios ojos con gruesos pilares firmemente "
        "asentados en el cauce del río. A lo lejos se escucha el ruido de "
        "unas cataratas.\n");
    AddDetail(({"puente","puente de piedra"}),"Se haya en buen estado, "
        "aunque ya se nota el efecto de la humedad en él.\n");
    AddDetail(({"río","kuneii","río kuneii","río Kuneii"}),"El río Kuneii "
        "recorre este valle de este a oeste. Es un río caudaloso plagado de "
        "rápidos que hacen que no sea navegable. Nace en el vecino valle de "
        "Zarkam y a través de las Cataratas de Nurr atraviesa las Montañas "
        "Negras y entra en el valle. Desemboca al sur de la ciudad de Azzor.\n");
    SetIntNoise("A lo lejos se escucha el ruido de unas cataratas.\n");
    AddExit("norte",BOSQUE_TALEK("camino17"));
    AddExit("sur",BOSQUE_TALEK("camino15"));
}
