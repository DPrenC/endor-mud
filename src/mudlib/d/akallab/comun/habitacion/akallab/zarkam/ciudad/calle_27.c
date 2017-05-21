/*
DESCRIPCION : barrio de los artesanos
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_27.c
MODIFICACION: 24-11-98 [Angor@Simauria] Creacion
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
    SetIntShort("el barrio de los artesanos");
    SetIntLong("Has llegado a un cruce de calles en el Barrio de los Artesanos formado por una "
        "ancha calle que avanza de norte a sur y otra que parte desde aquí hacia el este. En "
        "la casa que queda al oeste vive un conocido zapatero.\n");
    AddDetail(({"casa","zapateria","zapatería"}),"En el bajo edificio que queda al oeste de "
        "aquí, está la zapatería de Sebte. Este conocido zapatero tiene acondicionada la "
        "planta baja de su casa como un taller en el que trabaja y vende sus productos.\n");
    AddDetail(({"barrio","Barrio","barrio de los artesanos","Barrio de los Artesanos"}),"Te "
        "encuentras en el Barrio de los Artesanos, una zona al nordeste de la ciudad, donde se "
        "encuentran los talleres en los que trabajan los artesanos de esta ciudad, y en los "
        "que suelen vender sus productos y ofrecer sus servicios.\n");
    SetIntNoise("Oyes el ajetreo tipico de una ciudad.\n");
    SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
    SetLocate("ciudad de Zarkam");
    SetIndoors(0);
    AddExit("norte",Z_CIUDAD("calle_26"));
    AddExit("oeste",Z_TIENDA("zapateria"));
    AddExit("este",Z_CIUDAD("calle_30"));
    AddExit("sur",Z_CIUDAD("calle_28"));
    AddDoor("oeste","la puerta de la zapatería",
        "Es una gruesa puerta de madera labrada, fuerte y resistente.\n",
        ({"puerta","puerta de zapateria","puerta de zapatería","puerta de la zapateria",
            "puerta de la zapatería","puerta oeste"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({({"Intentas abrir la puerta, y al no poder, la miras y ves "
                "un cartel:\n'Cerrado toda la noche.'\n","Tratas de abrir la puerta en "
                "la oscuridad, pero no logras encontrar la manija.\n"}),({"@nombre@ trata de "
                "entrar en la zapatería, pero se da cuenta de que cierra durante la noche.\n",
                "Oyes a alguien removerse, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"}),
                P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}
