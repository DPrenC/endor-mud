/*****************************************************************************************
 ARCHIVO:       robledal35.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCI�N:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("los pies de una colina");
    SetIntLong("Est�s bajo las retorcidas ramas del bosque de la Isla de los Druidas. "
        "Los �rboles son altos, de corteza rugosa, casi negra, con hojas de forma "
        "ovalada del mismo color oscuro, y nudosas ra�ces que se alzan desde el suelo "
        "como rodillas peladas. De las retorcidas ramas cuelga una mara�a verdosa "
        "de espesa hiedra.\n");
    AddDetail("suelo", "En el suelo abundan los frutos ca�dos, grandes como cabezas de "
        "ardillas.\n");
    AddDetail("ramas", "Recuerdan, al tocarse en la altura, la c�pula de un peque�o "
        "santuario.\n");
    AddDetail(({"�rboles", "arboles"}), "El viento hace que sus copas se unan formando "
        "una inmensa b�veda de verdura.\n");
    AddDetail("corteza", "Es muy gruesa y reticulada, parece la piel de un viejo "
        "caballo.\n");
    AddDetail("hojas", "Son cortas y tienen una pelusa suave y corta por debajo.\n");
    AddDetail("raices", "son gruesas, retorcidas y est�n llenas de musgo.\n");

    AddExit("norte", HAB_BOSQUE_ISLA("robledal37.c"));
    AddExit("este", HAB_BOSQUE_ISLA("robledal36.c"));
    AddExit("oeste", HAB_BOSQUE_ISLA("robledal34.c"));
}
