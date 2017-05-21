/*
DESCRIPCION  : Paso de Akkbar
FICHERO      : /d/akallab/comun/habitacion/akallab/akkbar/camino/akkbar02.c
MODIFICACION : 11-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit AK_ROOM;

create()
{
    ::create();
   SetIntShort("el paso de Akkbar");
    SetIntLong("El viento sopla frío con fuerza aquí en el fondo del "
        "desfiladero que es el paso de Akkbar. El camino del Este que avanza "
        "a través de él se halla encajonado por altas montañas cubiertas de "
        "nieves perpetuas. Un estrecho desfiladero se abre al nordeste de "
        "aquí.\n");
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
    AddExit("nordeste",AKKBAR_CAMINO("akkbar08"));
    AddExit("sudeste",AKKBAR_CAMINO("akkbar03"));
    AddExit("oeste",AKKBAR_CAMINO("akkbar01"));
}
