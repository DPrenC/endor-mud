/*****************************************************************************************
 ARCHIVO:       bosque60.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCIÓN:   Bosque de las Hadas.
 COMENTARIOS:   Añadir detalles
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

create()
{
    if(::create()) return 1;

    SetIntShort("torno a un estanque");
    SetIntLong("Estás a orillas de un estanque bordeado de florecillas silvestres. La "
        "superficie del agua se ondula en diminutas olas espumosas, lo cual no deja de "
        "sorprenderte. Es como si una presencia invisible estuviese jugando a removerla. "
        "Los colores son cambiantes, desde un pálido azul hasta un refulgente rojizo "
        "pasando por un misterioso gris. Te das cuenta de que las hojas de los árboles "
        "que rodean este lugar, se van transformando a la vez que los colores del "
        "estanque.\n");
    AddDetail("estanque", ".\n");
    AddDetail(({"florecillas", "flores", "florecillas silvestres"}), ".\n");
    AddDetail(({"agua", "superficie", "olas"}), ".\n");
    AddDetail("hojas", ".\n");
    AddDetail(({"árboles", "arboles"}), ".\n");

    AddExit("sur", HAB_BOSQUE_HADAS("bosque55.c"));
}
