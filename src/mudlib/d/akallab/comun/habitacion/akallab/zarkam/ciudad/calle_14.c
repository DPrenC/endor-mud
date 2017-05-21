/*
DESCRIPCION : en una calle de Zarkam
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/ciudad/calle_14.c
MODIFICACION: 12-11-98 [Angor@Simauria] Creacion
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
    SetIntLong("Al oeste de aquí comienza el llamado Barrio de los Espíritus, una zona de la "
        "ciudad en la que se puede encontrar todo aquello relacionado con la magia o con la "
        "religión. Hacia el este parte una estrecha callejuela junto a la muralla del inmenso "
        "castillo que se alza en medio de la ciudad al nordeste de aquí. Al sur de aquí se "
        "encuentra una herboristería.\n");
    AddDetail(({"tienda","herboristeria","herboristería"}),"Hay una herboristería en el "
        "edificio que queda al sur de aquí. Es una tienda en la que podrás encontrar todo tipo "
        "de hierbas o pociones hechas con ellas.\n");
    AddDetail(({"callejuela"}),"Es una estrecha callejuela que corre junto a la muralla del "
        "castillo. Es bastante larga y en ella hay algunas tiendas.\n");
    AddDetail(({"muralla"}),"Es la alta pared exterior del castillo. No ves desde aquí que "
        "tenga ninguna puerta que dé a la callejuela que parte hacia el este.\n");
    AddDetail(({"castillo"}),"La ciudad de Zarkam se ha construido en torno al gran castillo "
        "que observas al noroeste de aquí. En él vive el governador orco que el emperador ha "
        "elegido para dirigir esta provincia. El castillo es una inmensa mole de piedra más "
        "alta que cualquiera de los edificios que lo rodean. Sobre él se alza una alta torre "
        "desde la que se vigila el valle constantemente.\n");
    AddDetail(({"torre"}),"Se alza sobre el castillo.\n");
    AddDetail(({"barrio","barrio de los espiritus","barrio de los Espiritus",
        "barrio de los espíritus","barrio de los Espíritus"}),"Te encuentras en el "
        "barrio de los Espíritus, una zona al suroeste de la ciudad donde se puede encontrar "
        "todo aquello relacionado con la magia o la religión de esta parte del mundo. Aquí "
        "podrías comprar un filtro de amor, rezar u ofrecer un sacrificio a alguno de los "
        "muchos dioses locales, ingresar en algún gremio que domine la magia o encontrar una "
        "fría sepultura. Las fuerzas que se mueven por esta zona son poderosas, haciendo que "
        "incluso los propios orcos, pese a su fuerte carácter, sean aquí respetuosos...\n");
    SetIntNoise("Oyes el ajetreo tipico de una ciudad.\n");
    SetIntSmell("Hmm.. el aire es mas bien frio por la altura.\n");
    SetLocate("ciudad de Zarkam");
    SetIndoors(0);
    AddExit("oeste",Z_CIUDAD("calle_13"));
    AddExit("este",Z_CIUDAD("calle_15"));
    AddExit("norte",Z_CIUDAD("calle_16"));
    AddExit("sur",Z_TIENDA("herboristeria"));
    AddDoor("sur","la puerta de la herboristería",
        "Es una gruesa puerta de madera labrada, fuerte y resistente.\n",
        ({"puerta","puerta de herboristeria","puerta de herboristería","puerta sur",
            "puerta de la herboristeria","puerta de la herboristería"}),GENDER_FEMALE,
        ([P_MATERIAL:M_MADERA, P_DOOR_OPEN_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CLOSE_SOUND:SND_SUCESOS("abrir_puerta_campanillas"),
            P_DOOR_CANT_OPEN_MSG:({({"Intentas abrir la puerta, y al no poder, la miras y ves "
                "un cartel:\n'Cerrado toda la noche.'\n","Tratas de abrir la puerta en "
                "la oscuridad, pero no logras encontrar la manija.\n"}),({"@nombre@ trata de "
                "entrar en la herboristería, pero se da cuenta de que cierra durante la noche.\n",
                "Oyes a alguien removerse, jurando en la oscuridad.\n"}),
                "Parece que alguien trata de abrir la puerta.\n"}),
                P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}

