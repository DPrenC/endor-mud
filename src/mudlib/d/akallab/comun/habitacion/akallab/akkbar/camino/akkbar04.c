/*
DESCRIPCION  : Paso de Akkbar
FICHERO      : /d/akallab/comun/habitacion/akallab/akkbar/camino/akkbar04.c
MODIFICACION : 11-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit AK_ROOM;

create()
{
    ::create();
   SetIntShort("el paso de Akkbar");
    SetIntLong("El camino del Este continúa avanzando por el fondo de este "
        "desfiladero que es el paso de Akkbar. Desde aquí abajo no puedes "
        "ver mas allá de las altas montañas cubiertas de nieves perpetuas "
        "que te rodean. Un estrecho desfiladero se abre al sudeste de aquí. "
        "Un viento helado aúlla con fuerza.\n");
    AddDetail(({"desfiladero","paso","paso del akkbar","paso de Akkbar","montanyas","montanyas Negras"}),
        "El paso de Akkbar es el nombre que recibe el paso a través de las "
        "montañas Negras en el que te encuentras. Estas montañas separan el "
        "valle de Zarkam de los territorios orcos del valle de Azzor que se "
        "hallan en la costa este de la península de Aguliuk. Pese a ser un "
        "lugar peligroso, el paso de Akkbar es el camino mas corto y por "
        "ello mas usado para cruzar estas montañas.\n");
    AddDetail(({"camino","camino del este","camino del Este","Camino del Este"}),
        "Es un importante camino que comunica el valle de Zarkam con los "
        "territorios del valle de Azzor en la costa este de la península "
        "orca de Aguliuk.\n");
    SetIntNoise("El viento aúlla con fuerza.\n");
    SetIntSmell("El aire está enrarecido por la altura.\n");
    SetLocate("paso de Akkbar");
    SetIndoors(0);
    AddExit("nordeste",AKKBAR_CAMINO("akkbar05"));
    AddExit("sudeste",AKKBAR_CAMINO("akkbar14"));
    AddExit("oeste",AKKBAR_CAMINO("akkbar03"));
    AddItem(HERBS("hierba"),REFRESH_REMOVE,1);
}
