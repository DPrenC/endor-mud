/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/casas/bodega04.c
Autor: Lug y Yalin
Fecha: 20/08/2006
Descripci�n: almac�n de la bodega.
****************************************************************************/

#include "path.h"
inherit SHERALD("ceroom");

public int fcoger(string str)
{
    if ((str == "barril") || (str == "barriles") || (str == "tonel") || (str == "toneles"))
    {
        write("�Pretendes romperte la espalda?\n");
        return 1;
    }
}

create()
{
    ::create();
    SetIntShort("el almac�n de la bodega");
    SetIntLong("Te hallas en una inmensa nave, fr�a y oscura, donde se "
        "almacenan los barriles de vino, para terminar su envejecimiento.\n"
        "Todo a tu alrededor son barriles, y m�s barriles, alineados contra "
        "las paredes, esperando el momento de ser sacados y vendidos, o "
        "abiertos y consumidos.\nAl este contin�a el almac�n. "
        "Una rampa conduce al piso superior, permitiendo sacar los barriles "
        "cuando el vino est� curado, bien rodando o en alg�n tipo de armaz�n "
        "rodante.\n");
    SetIntBright(20);
    SetIntSmell("Huele a vino y madera de roble.\n");
     SetIntNoise("No oyes nada, esta nave est� bien aislada, ya sabes que el "
        "vino no se lleva bien con los ruidos.\n");
    AddDetail(({"tonel","toneles","barril","barriles"}), "Los barriles son "
        "cilindros hechos de tablas curvadas, unidas por abrazaderas "
        "met�licas, y con unos c�rculos de madera cerrando sus bases. En una "
        "de ellas, hay un orificio cerrado por un corcho. Sirven para "
        "almacenar el vino.\n");
    AddRoomCmd("coger", "fcoger");
    AddExit("este", SHERALD("casas/bodega03"));
    AddExit("arriba", SHERALD("casas/bodega05"));
}
