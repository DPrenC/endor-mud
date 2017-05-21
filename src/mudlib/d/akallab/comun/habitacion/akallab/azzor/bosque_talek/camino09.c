/*
DESCRIPCION  : Camino del Este a traves del bosque de Talek
FICHERO      : camino09.c
MODIFICACION : 10-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit BOSQUE_TALEK("camino");

create()
{
    ::create();
   SetIntLong("Continúas avanzando por el Camino del Este que atraviesa el "
        "bosque. Observas como la brisa mece suavemente las ramas de los "
        "altos robles que flanquean esta parte del camino. Junto al camino "
        "se encuentra el viejo tronco de un árbol caído ya hace tiempo. El "
        "camino continúa hacia el este y hacia el noroeste.\n");
    AddDetail(({"tronco","viejo tronco","robles","hueco"}),"Junto al camino "
        "se encuentra el tronco caído de un árbol. Está medio podrido por lo "
        "que supones que debe llevar ahí bastante tiempo. Su grosor es de "
        "casi un metro, por lo que debió pertenecer a un gran árbol. Puedes "
        "ver un par de jóvenes robles compitiendo por el hueco donde antes "
        "crecía ese árbol.\n");
    AddExit("noroeste",BOSQUE_TALEK("camino08"));
    AddExit("este",BOSQUE_TALEK("camino10"));
    AddExit("norte",BOSQUE_TALEK("bosque32"));
    AddExit("sur",BOSQUE_TALEK("bosque23"));
}
