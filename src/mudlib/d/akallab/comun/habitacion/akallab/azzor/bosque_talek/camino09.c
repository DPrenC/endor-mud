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
   SetIntLong("Contin�as avanzando por el Camino del Este que atraviesa el "
        "bosque. Observas como la brisa mece suavemente las ramas de los "
        "altos robles que flanquean esta parte del camino. Junto al camino "
        "se encuentra el viejo tronco de un �rbol ca�do ya hace tiempo. El "
        "camino contin�a hacia el este y hacia el noroeste.\n");
    AddDetail(({"tronco","viejo tronco","robles","hueco"}),"Junto al camino "
        "se encuentra el tronco ca�do de un �rbol. Est� medio podrido por lo "
        "que supones que debe llevar ah� bastante tiempo. Su grosor es de "
        "casi un metro, por lo que debi� pertenecer a un gran �rbol. Puedes "
        "ver un par de j�venes robles compitiendo por el hueco donde antes "
        "crec�a ese �rbol.\n");
    AddExit("noroeste",BOSQUE_TALEK("camino08"));
    AddExit("este",BOSQUE_TALEK("camino10"));
    AddExit("norte",BOSQUE_TALEK("bosque32"));
    AddExit("sur",BOSQUE_TALEK("bosque23"));
}
