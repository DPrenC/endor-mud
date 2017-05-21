/*
DESCRIPCION : en una calle de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_16.c
MODIFICACION: 17-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>
#include <materials.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit ROOM;

create()
{
    ::create();
    SetIntShort("una calle de Zarkam");
    SetIntLong("Te encuentras en una ancha calle que rodea el castillo de esta ciudad, "
        "avanzando junto a su muralla. No ves que haya ninguna entrada al castillo desde esta "
        "calle. Al oeste de aquí se halla una pequeña librería.\n");
    AddDetail(({"libreria","librería"}),"En el edificio que queda al oeste hay una librería. "
        "En ella se pueden encontrar todo tipo de libros y mapas.\n");
    AddDetail(({"calle"}),"Es una ancha calle que corre junto a las murallas del castillo de "
        "la ciudad.\n");
    AddDetail(({"muralla"}),"Es la alta pared exterior del castillo. No ves desde aquí que "
        "tenga ninguna puerta que dé a esta calle.\n");
    AddDetail(({"castillo"}),"La ciudad de Zarkam se ha construido en torno al gran castillo "
        "que observas al este de aquí. En él vive el governador orco que el emperador ha "
        "elegido para dirigir esta provincia. El castillo es una inmensa mole de piedra mas "
        "alta que cualquiera de los edificios que lo rodean. Sobre él se alza una alta torre, "
        "desde la que se vigila el valle constantemente.\n");
    AddDetail(({"torre"}),"Se alza sobre el castillo.\n");
    SetIntNoise("Oyes el ajetreo tipico de una ciudad.\n");
    SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
    SetLocate("ciudad de Zarkam");
    SetIndoors(0);
    AddExit("oeste",Z_TIENDA("libreria"));
    AddExit("norte",Z_CIUDAD("calle_17"));
    AddExit("sur",Z_CIUDAD("calle_14"));
    AddDoor("oeste","la puerta de la librería",
        "Es una gruesa puerta de madera labrada, fuerte y resistente.\n",
        ({"puerta","puerta de libreria","puerta de librería","puerta de la libreria",
            "puerta de la librería","puerta oeste"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({({"Intentas abrir la puerta, y al no poder, la miras y ves "
                "un cartel:\n'Cerrado toda la noche.'\n","Tratas de abrir la puerta en "
                "la oscuridad, pero no logras encontrar la manija.\n"}),({"@nombre@ trata de "
                "entrar en la librería, pero se da cuenta de que cierra durante la noche.\n",
                "Oyes a alguien removerse, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"}),
                P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}
