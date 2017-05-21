/*
DESCRIPCION  : Paso de Akkbar
FICHERO      : /d/akallab/comun/habitacion/akallab/akkbar/camino/akkbar03.c
MODIFICACION : 11-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit AK_ROOM;

create()
{
    ::create();
   SetIntShort("el paso de Akkbar");
    SetIntLong("Las altas monta�as te contemplan en silencio mientras "
        "avanzas por el paso de Akkbar. A trav�s de este desfiladero el "
        "camino del Este comunica el valle de Zarkam con los territorios "
        "costeros de Azzor. Observas como el viento arrastra las nieves "
        "perpetuas de las altas cumbres formando ventiscas all� arriba. Un "
        "estrecho desfiladero se abre al sur de aqu�.\n");
    AddDetail(({"desfiladero","paso","paso del akkbar","paso de Akkbar","montanyas","montanyas Negras"}),
        "El paso de Akkbar es el nombre que recibe el paso a trav�s de las "
        "monta�as Negras en el que te encuentras. Estas monta�as separan el "
        "valle de Zarkam de los territorios orcos del valle de Azzor que se "
        "hallan en la costa este de la pen�nsula de Aguliuk. Pese a ser un "
        "lugar peligroso, el paso de Akkbar es el camino mas corto y por "
        "ello mas usado para cruzar estas monta�as.\n");
    AddDetail(({"camino","camino del este","camino del Este","Camino del Este"}),
        "Es un importante camino que comunica el valle de Zarkam con los "
        "territorios del valle de Azzor en la costa este de la pen�nsula "
        "orca de Aguliuk.\n");
    SetIntNoise("El viento a�lla con fuerza.\n");
    SetIntSmell("El aire est� enrarecido por la altura.\n");
    SetLocate("paso de Akkbar");
    SetIndoors(0);
    AddExit("noroeste",AKKBAR_CAMINO("akkbar02"));
    AddExit("sur",AKKBAR_CAMINO("akkbar11"));
    AddExit("este",AKKBAR_CAMINO("akkbar04"));
}
