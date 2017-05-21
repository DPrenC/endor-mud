
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un dormitorio");
    SetIntLong(
    "Una gran cama de la madera mas noble domina la habitaci�n, sobre ella puedes "
    "ver un gran cuadro de una bella dama vestida con ropajes p�rpuras.\n Toda la "
    "estancia esta reluciente, prueba del buen trabajo de los criados.\n");
    SetIntSmell("La habitaci�n est� perfumada con deliciosos aromas.\n");
    SetIntBright(45);
    AddDetail("cuadro",
    "Representa a una dama muy bella perteneciente a la alta sociedad. Quiz� "
    "sea un retrato de alguna antigua noble del castillo.\n");
    AddDetail("cama",
    "Es de madera noble y es enorme. Casi 3 metros de ancho.\n");
    AddExit("norte", "./pasillo2");
    AddDoor("norte", "una puerta dorada",
    "Es una puerta de madera, aunque tiene alg�n tratamiento especial, pues su color "
    "dorado no debe de ser natural.\n",
    ({"puerta", "puerta de madera", "puerta dorada", "puerta del norte"}));
    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("esposa_noble"), REFRESH_DESTRUCT);
    AddItem(PNJCASTILLO("caniche"), REFRESH_DESTRUCT);
}
