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
   SetIntShort("la orilla del r�o");
    SetIntLong("Frente a ti pasa el caudaloso r�o Kuneii. Observas como se "
        "aleja hacia el este en direcci�n al fondo del valle de Azzor "
        "dejando atr�s este bosque.\n"+QueryIntLong());
    AddDetail(({"r�o","kuneii","r�o kuneii","r�o Kuneii"}),"El r�o Kuneii "
        "recorre este valle de este a oeste. Es un r�o caudaloso plagado de"
        "r�pidos que hacen que no sea navegable. Nace en el vecino valle de "
        "Zarkam y a trav�s de las Cataratas de Nurr atraviesa las Monta�as "
        "Negras y entra en el valle. Desemboca al sur de la ciudad de Azzor.\n");
    SetIntSmell("Hueles el fresco aroma del bosque y la humedad del r�o.\n");
    AddExit("oeste",BOSQUE_TALEK("bosque62"));
    AddExit("sur",BOSQUE_TALEK("bosque59"));
    AddExit("suroeste",BOSQUE_TALEK("bosque58"));
}
