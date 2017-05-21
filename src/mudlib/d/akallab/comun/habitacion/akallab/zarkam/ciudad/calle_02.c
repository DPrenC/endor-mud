/*
DESCRIPCION : calle mayor de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_02.c
MODIFICACION: 07-03-98 [Angor@Simauria] Creacion
              11-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit ROOM;

create()
{
    ::create();
    SetIntShort("la calle mayor de Zarkam");
    SetIntLong("Continúas avanzando por la calle mayor de la ciudad de Zarkam. El pavimento de "
        "la calle no está en muy buen estado pero no parece importar a nadie. Hasta aquí llega "
        "el olor a pan recién hecho desde la panadería que se encuentra en la planta baja del "
        "edificio que queda al este de aquí. Es apetitoso. Por un gran rótulo que cuelga sobre "
        "su fachada, te das cuenta de que el edificio del oeste es la fonda El Jabalí Feroz.\n");
    AddDetail(({"pavimento"}),"Algunas de las losas de piedra que pavimentan esta calle están "
        "rotas, debido posiblemente al paso de carros pesados. Dado el estado de la calle, "
        "juzgas que a los habitantes de este lugar no les preocupa demasiado este hecho.\n");
    AddDetail(({"panaderia","panadería"}),"Está en el bajo del edificio que queda al este.\n");
    AddDetail(({"fonda"}),"Es el edificio que queda al oeste. Has oído decir que se come bien "
        "a precios moderados y que el ambiente es agradable.\n");
    SetIntNoise("Se oye el ajetreo típico de una ciudad.\n");
    SetIntSmell("Hmm.. el aire es más bien frío por la altura.\n");
    SetLocate("ciudad de Zarkam");
    SetIndoors(0);
    AddExit("norte",Z_CIUDAD("calle_03"));
    AddExit("oeste",Z_TIENDA("fonda"));
    AddExit("este",Z_TIENDA("panaderia"));
    AddExit("sur",Z_CIUDAD("calle_01"));
    AddDoor("oeste","la puerta de la fonda",
        "Es una gruesa puerta de madera bien pulida, pintada de un bonito tono azul y adornada "
            "con gruesos clavos de bronce.\n",
        ({"puerta","puerta oeste","puerta de fonda","puerta de la fonda"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA,P_DOOR_CANT_OPEN_MSG:({({"La fonda está cerrada, no es ésta hora "
            "para comer.\n","Tratas de abrir la puerta en la oscuridad, pero no consigues "
            "encontrar la manija.\n"}),({"@nombre@ debe tener hambre, intentaba ir a la fonda "
            "pero se da cuenta de que está cerrada.\n","Oyes a alguien removerse, jurando en "
            "la oscuridad.\n"}),"Parece que alguien trata de abrir la puerta.\n"}),
            P_DOOR_CLOSE_TIME : ({ND_NIGHT,ND_PREDAWN,ND_DAWN,ND_SUNRISE,ND_PRENOON})]));
    AddDoor("este","la puerta de la panadería",
        "Es una gruesa puerta de madera labrada, fuerte y resistente.\n",
        ({"puerta","puerta de panaderia","puerta de panadería","puerta de la panaderia",
            "puerta de la panadería","puerta este"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({({"Intentas abrir la puerta, y al no poder, la miras y ves "
                "un cartel:\n'Cerrado toda la noche.'\n","Tratas de abrir la puerta en "
                "la oscuridad, pero no logras encontrar la manija.\n"}),({"@nombre@ trata de "
                "entrar en la panadería, pero se da cuenta de que cierra durante la noche.\n",
                "Oyes a alguien removerse, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"}),
                P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}
