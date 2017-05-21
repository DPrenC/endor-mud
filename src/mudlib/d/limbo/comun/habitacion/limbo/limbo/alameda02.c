/*
DESCRIPCI�N  : Paseo de la Alameda
FICHERO      : /d/limbo/comun/habitacion/limbo/limbo/alameda02.c
MODIFICACI�N : 31-01-98 [angor] Creacion.
               10-10-99 [Woo] Toqueteado...
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("el Paseo de la Alameda");
    SetIntLong("El Paseo de la Alameda realiza una suave y amplia curva en este lugar, para acabar "
        "al sur de aqu� en una gran plaza rodeada de varios edificios altos. La brisa del mar mece "
        "las ramas de los altos �lamos que flanquean el Paseo. Al oeste de aqu� observas el borde "
        "de los acantilados que forman la costa.\n");
    AddDetail(({"isla","isla Limbo","isla limbo","Limbo","limbo"}),"La isla de Limbo es el lugar "
        "m�gico de Simauria donde habitan los dioses. Gracias a ellos, es en este lugar donde las "
        "almas de los seres se encarnan y dan sus primeros pasos para vivir en este mundo.\n");
    AddDetail(({"paseo de la alameda","paseo","alameda","Alameda"}),"Es un camino que conduce "
        "desde el Camino del Sur hasta los acantilados de la costa sudeste de la isla Limbo, zona "
        "en la que se halla el Templo de Asthar.\nEl camino en s� est� recubierto de una fina "
        "grava y est� flanqueado por dos largas filas de altos �lamos. Las ramas de estos esbeltos "
        "�rboles se mueven suavemente con la brisa que sube desde la costa.\n");
    SetIntNoise("Oyes el ruido de las olas chocando contra los acantilados.\n");
    SetIntSmell("Hmm.. el aire es fresco y limpio.\n");
    SetLocate("isla Limbo");
    SetIndoors(0);
    AddExit("oeste",LIMBO("alameda01"));
    AddExit("sur",TEMPLO("plaza01"));
}

