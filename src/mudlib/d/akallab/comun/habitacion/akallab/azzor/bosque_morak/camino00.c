/*
DESCRIPCION  : camino a traves del bosque de Morak
FICHERO      : camino00.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("camino");

#define DESTINO GADDARO("calle06")
#include FILTRO_PNJ_ZONA

create()
{
    ::create();
   SetIntLong("Al nordeste de aquí comienza el bosque de Morak, un bosque de "
        "mediano tamaño que se extiende en la parte norte este del valle de "
        "Azzor, hasta el mismo pie de la cordillera de Kova. Es un bosque no "
        "muy denso del que los orcos, principalmente los del cercano pueblo de "
        "Gaddaro que queda al oeste de aquí, extraen madera. Al norte del "
        "bosque, al pie de las montañas se halla una cantera.\n");
    AddDetail(({"pueblo","villa","Gaddaro","gaddaro"}),"Gaddaro es el nombre "
        "del pueblo que ves hacia el oeste. Es un pequeño pueblo situado en "
        "el noroeste del valle de Azzor, en su parte alta. Sus habitantes se "
        "dedican básicamente a la agricultura y a la pesca en el cercano "
        "lago Darum.\n");
    AddExit("nordeste",BOSQUE_MORAK("camino01"));
    AddExit("suroeste",SF(FiltroPnjZona));
}
