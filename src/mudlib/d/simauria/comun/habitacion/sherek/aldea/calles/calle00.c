/*
Archivo        calle00.c
Autor:         Yalin y Lug
Fecha:         04/05/2006
Descripci�n:   Calle de la aldea (proyecto)
*/

#include "path.h"
#include <properties.h>
#include <materials.h>
#include <nightday.h>
#include <door.h>
inherit SHERALD("calles/calle");

create()
{
    ::create();
    SetIntLong(QueryIntLong()+"Hacia el este hay una peque�a taberna, al "
        "oeste est� el camino que sale de la aldea, al norte sale un "
        "caminito hacia el cementerio y al sur contin�a la calle.\n");
    AddDetail(({"norte", "cementerio"}), "El peque�o cementerio donde se da "
        "sepultura a los que mueren aqu�.\n");
    AddDetail(({"taberna","tasca","bar","este"}),"Es un peque�o local "
        "utilizado por los aldeanos como tienda y bar al mismo tiempo.\n");
    AddExit("este", SHERALD("tiendas/taberna"));
    AddExit("oeste", SHERALD("calles/sendero03"));
    AddExit("sur", SHERALD("calles/calle01"));
    AddExit("norte", SHERALD("calles/caminocem"));
    AddDoor("este","la puerta de la taberna",
        "Es una vieja puerta de madera bastante estropeada, pero con la guardia patrullando la "
            "calle, no es probable que nadie intente forzarla, y por otra parte, aqu� hay poco "
            "que robar.\n",
        ({"puerta","puerta este","puerta de taberna","puerta de la taberna"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_CLOSE_TIME:({ND_PREDAWN,ND_DAWN,ND_SUNRISE}),
            P_DOOR_CANT_OPEN_MSG:({({"La taberna est� cerrada. Hasta ma�ana tendr�s que beber "
                "en la fuente.\n","Tratas de abrir la puerta en la oscuridad, pero no "
                "encuentras la manija.\n"}),({"@nombre@ pensaba comer o beber algo, pero la "
                "taberna est� cerrada.\n","Oyes a alguien removerse, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"})]));
    AddItem(PNJ("sherek/aldea/guardian"),REFRESH_DESTRUCT,1);
}
