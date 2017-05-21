/*****************************************************************************************
 ARCHIVO:       robledal35.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("los pies de una colina");
    SetIntLong("Estás bajo las retorcidas ramas del bosque de la Isla de los Druidas. "
        "Los árboles son altos, de corteza rugosa, casi negra, con hojas de forma "
        "ovalada del mismo color oscuro, y nudosas raíces que se alzan desde el suelo "
        "como rodillas peladas. De las retorcidas ramas cuelga una maraña verdosa "
        "de espesa hiedra.\n");
    AddDetail("suelo", "En el suelo abundan los frutos caídos, grandes como cabezas de "
        "ardillas.\n");
    AddDetail("ramas", "Recuerdan, al tocarse en la altura, la cúpula de un pequeño "
        "santuario.\n");
    AddDetail(({"árboles", "arboles"}), "El viento hace que sus copas se unan formando "
        "una inmensa bóveda de verdura.\n");
    AddDetail("corteza", "Es muy gruesa y reticulada, parece la piel de un viejo "
        "caballo.\n");
    AddDetail("hojas", "Son cortas y tienen una pelusa suave y corta por debajo.\n");
    AddDetail("raices", "son gruesas, retorcidas y están llenas de musgo.\n");

    AddExit("norte", HAB_BOSQUE_ISLA("robledal37.c"));
    AddExit("este", HAB_BOSQUE_ISLA("robledal36.c"));
    AddExit("oeste", HAB_BOSQUE_ISLA("robledal34.c"));
}
