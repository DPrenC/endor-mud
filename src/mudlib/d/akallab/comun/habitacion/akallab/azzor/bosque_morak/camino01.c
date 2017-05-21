/*
DESCRIPCION  : camino a traves del bosque de Morak
FICHERO      : camino01.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("camino");

create()
{
    ::create();
   SetIntLong("El camino contin�a su avance a trav�s del bosque. Observas "
        "c�mo la brisa mece suavemente las ramas de los altos robles que "
        "flanquean esta parte del camino. Junto al camino se encuentra el "
        "viejo tronco de un �rbol ca�do ya hace tiempo. El camino contin�a "
        "hacia el este y hacia el suroeste.\n");
    AddDetail(({"tronco","viejo tronco","robles","hueco"}),"Junto al camino "
        "se encuentra el tronco ca�do de un �rbol. Est� medio podrido por lo "
        "que supones que debe llevar ah� bastante tiempo. Su grosor es de "
        "casi un metro, por lo que debi� pertenecer a un gran �rbol. Puedes "
        "ver un par de j�venes robles compitiendo por el hueco donde antes "
        "crec�a ese �rbol.\n");
    AddExit("norte",BOSQUE_MORAK("bosque02"));
    AddExit("oeste",BOSQUE_MORAK("bosque01"));
    AddExit("sur",BOSQUE_MORAK("bosque00"));
    AddExit("este",BOSQUE_MORAK("camino02"));
    AddExit("suroeste",BOSQUE_MORAK("camino00"));
}
