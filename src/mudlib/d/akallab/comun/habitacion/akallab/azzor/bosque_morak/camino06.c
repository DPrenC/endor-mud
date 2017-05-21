/*
DESCRIPCION  : camino a traves del bosque de Morak
FICHERO      : camino06.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("camino");

create()
{
    ::create();
   SetIntLong("El camino continúa su avance a través del bosque. Observas "
        "cómo la brisa mece suavemente las ramas de los altos robles que "
        "flanquean esta parte del camino. Junto al camino se encuentra el "
        "viejo tronco de un árbol caído ya hace tiempo. El camino continúa "
        "hacia el oeste y hacia el nordeste.\n");
    AddDetail(({"tronco","viejo tronco","robles","hueco"}),"Junto al camino "
        "se encuentra el tronco caído de un árbol. Está medio podrido por lo "
        "que supones que debe llevar ahí bastante tiempo. Su grosor es de "
        "casi un metro, por lo que debió pertenecer a un gran árbol. Puedes "
        "ver un par de jóvenes robles compitiendo por el hueco donde antes "
        "crecía ese árbol.\n");
    AddExit("norte",BOSQUE_MORAK("bosque10"));
    AddExit("nordeste",BOSQUE_MORAK("camino07"));
    AddExit("oeste",BOSQUE_MORAK("camino04"));
    AddExit("este",BOSQUE_MORAK("bosque30"));
}
