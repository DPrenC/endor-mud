/*****************************************************************************************
 ARCHIVO:       robledal29.c
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

    SetIntShort("un puente sobre un arroyo");
    SetIntLong("Te encuentras en un firme puente de piedra sobre las aguas de un "
        "riachuelo que discurre transversalmente al sendero. A pesar de la neblina "
        "que se arremolina a tu alrededor, puedes apreciar que el arroyo desaparece "
        "bajo un grupo de rocas.\n");
    AddDetail(({"puente", "puente de piedra"}), "Es de piedra y tiene un sólo arco.\n");
    AddDetail(({"arroyo", "riachuelo"}), "No es muy ancho, pero aún así es lo "
        "suficientemente grande para que no se pueda saltar de un lado a otro.\n");
    AddDetail(({"agua", "aguas"}), "No parece que el río sea muy profundo. El agua "
        "transcurre rebotanto entre las piedras.\n");
    AddDetail("sendero", "A ambos lados del puente, el sendero continúa internándose en "
        "el bosque.\n");
    AddDetail(("rocas", "grupo de rocas"), "Forman una oscura cavidad por la que se "
        "pierde el caudal.\n");
    AddDetail(({"niebla", "neblina"}), "Todo está envuelto en una neblina casi permanente.\n");
    AddDetail("suelo", "Entre las juntas de las piedras del puente han crecido multitud "
        "de hierbajos.\n");

    SetIntSmell("Huele a hojas frescas y a humedad.\n");
    SetIntNoise("Se escucha el rumor del agua.\n");

    AddExit("sur", HAB_BOSQUE_ISLA("robledal23.c"));
    AddExit("noreste", HAB_BOSQUE_ISLA("robledal34.c"));
}
