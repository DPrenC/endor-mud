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
   SetIntShort("un puente sobre el r�o Kuneii");
    SetIntLong("Est�s sobre un ancho puente de piedra que permite atravesar "
        "el caudaloso r�o Kuneii que avanza hacia el fondo del valle en el "
        "este. Es un puente de varios ojos con gruesos pilares firmemente "
        "asentados en el cauce del r�o. A lo lejos se escucha el ruido de "
        "unas cataratas.\n");
    AddDetail(({"puente","puente de piedra"}),"Se haya en buen estado, "
        "aunque ya se nota el efecto de la humedad en �l.\n");
    AddDetail(({"r�o","kuneii","r�o kuneii","r�o Kuneii"}),"El r�o Kuneii "
        "recorre este valle de este a oeste. Es un r�o caudaloso plagado de "
        "r�pidos que hacen que no sea navegable. Nace en el vecino valle de "
        "Zarkam y a trav�s de las Cataratas de Nurr atraviesa las Monta�as "
        "Negras y entra en el valle. Desemboca al sur de la ciudad de Azzor.\n");
    SetIntNoise("A lo lejos se escucha el ruido de unas cataratas.\n");
    AddExit("norte",BOSQUE_TALEK("camino17"));
    AddExit("sur",BOSQUE_TALEK("camino15"));
}
