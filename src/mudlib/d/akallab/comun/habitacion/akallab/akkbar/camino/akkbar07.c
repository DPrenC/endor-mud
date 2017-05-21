/*
DESCRIPCION  : Salida al valle de Azzor
FICHERO      : /d/akallab/comun/habitacion/akallab/akkbar/camino/akkbar07.c
MODIFICACION : 11-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>
inherit AK_ROOM;

//los PNJ no pasan
int ir_e()
{
    if (TP->QueryIsPlayer()) return TP->move(BOSQUE_TALEK("camino00"),M_GO);
    return 1;
}

create()
{
    ::create();
   SetIntShort("la salida del paso de Akkbar");
    SetIntLong("En este lugar el camino del Este se adentra en el paso de "
        "Akkbar. Este angosto paso avanza encajonado atravesando la "
        "cordillera de las Montañas Negras, cuyas altas cumbres cubiertas de "
        "nieves perpetuas parecen ser mudos testigos de tus movimientos. Un "
        "viento helado aúlla con fuerza al cruzar el desfiladero.\n");
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
    AddExit("suroeste",AKKBAR_CAMINO("akkbar06"));
    AddExit("este",SF(ir_e));
}
