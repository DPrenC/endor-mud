/*
DESCRIPCION : en una calle de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_28.c
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
    SetIntShort("una calle de Zarkam");
    SetIntLong("Aquí comienza el llamado Barrio de los Artesanos, una zona al nordeste de esta "
        "ciudad en la que los artesanos locales tienen sus talleres, donde fabrican y suelen "
        "vender sus productos. Una calle parte hacia el oeste en dirección al centro de la "
        "ciudad y otra hacia el zoco que queda al sur.\nEn el edificio que queda al este vive "
        "uno de los mejores sastres de la ciudad, dicen que viste incluso al governador de "
        "Zarkam.\n");
    AddDetail(({"sastreria","sastrería","casa"}),"La casa del sastre queda al este.\n");
    AddDetail(({"zoco"}),"La calle que parte hacia el sur conduce hacia este gran mercado que "
        "queda al sudeste de la ciudad.\n");
    AddDetail(({"barrio","Barrio","barrio de los artesanos","Barrio de los Artesanos"}),"Te "
        "encuentras en el Barrio de los Artesanos, una zona al nordeste de la ciudad donde se "
        "encuentran los talleres en los que trabajan los artesanos de esta ciudad y en los que "
        "suelen vender sus productos y ofrecer sus servicios.\n");
    SetIntNoise("Oyes el ajetreo tipico de una ciudad.\n");
    SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
    SetLocate("ciudad de Zarkam");
    SetIndoors(0);
    AddExit("oeste",Z_CIUDAD("calle_29"));
    //AddExit("sur",Z_CIUDAD("calle_"));
    AddExit("norte",Z_CIUDAD("calle_27"));
    AddExit("este",Z_TIENDA("sastreria"));
    AddDoor("este","la puerta de la sastrería",
        "Es una gruesa puerta de madera labrada, fuerte y resistente.\n",
        ({"puerta","puerta de sastreria","puerta de sastrería","puerta de la sastreria",
            "puerta de la sastrería","puerta este"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({({"Intentas abrir la puerta, y al no poder, la miras y ves "
                "un cartel:\n'Cerrado toda la noche.'\n","Tratas de abrir la puerta en "
                "la oscuridad, pero no logras encontrar la manija.\n"}),({"@nombre@ trata de "
                "entrar en la sastrería, pero se da cuenta de que cierra durante la noche.\n",
                "Oyes a alguien removerse, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"}),
                P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}
