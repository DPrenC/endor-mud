/*
DESCRIPCION  : Paso de Akkbar
FICHERO      : /d/akallab/comun/habitacion/akallab/akkbar/camino/akkbar14.c
MODIFICACION : 11-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit AK_ROOM;

create()
{
    ::create();
   SetIntShort("el paso de Akkbar");
    SetIntLong("Avanzas por un estrecho desfiladero entre las Montañas "
        "Negras. El clima es frío, la vegetaciónn escasa y las altas "
        "montañas cubiertas de nieves perpetuas son tu única compañía. Un "
        "viento frío sopla con fuerza por el desfiladero.\n");
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
    AddExit("este",AKKBAR_CAMINO("akkbar15"));
    AddExit("noroeste",AKKBAR_CAMINO("akkbar04"));
}
