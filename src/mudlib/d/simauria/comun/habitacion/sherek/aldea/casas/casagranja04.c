/* Archivo: /d/simauria/comun/habitacion/sherek/aldea/casas/casagranja04.c
* Descripci�n: Comedor en el piso alto de la casa de administraci�n.
* Autor: Lug y Yalin.
*/
#include "path.h"
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("el comedor");
    SetIntLong("Aqu� es donde el administrador sube a comer, y donde comen "
        "tambi�n los guardias, cuando el administrador ha terminado.\nHay "
        "una mesa con un sill�n, para el administrador, y 4 sillas con un "
        "brazo ancho, donde comen los guardias.\nAl oeste se encuentra la "
        "cocina, mientras que al este hay un dormitorio.\n");
    AddDetail(({"escaleras", "escalera"}), "es una escalera de madera "
        "bastante ancha que desciende desde aqu� hasta la planta baja del "
        "edificio, y asciende hacia el desv�n.\n");
    AddDetail(({"silla","sillas"}), "Las sillas son de madera barnizada, con "
        "un brazo a la derecha, lo suficientemente ancho como para posar "
        "un plato.\n");
    AddDetail(({"sillon","sill�n"}), "Es un confortable sill�n de brazos, con "
        "el asiento mullido y forrado de terciopelo negro.\n");
    AddDetail(({"mesa"}), "Es una mesa cuadrada, de madera de roble y "
        "cubierta con un mantel blanco.\n");
    AddDetail(({"mantel"}), "Est� tejido con fino lino blanco.\n");
    AddDetail(({"suelo","entarimado","tablones"}), "El suelo es un "
        "entarimado de tablones bien pulidos y barnizados.\n");
    AddDetail(({"pared", "paredes"}), "las paredes aqu� est�n revestidas de "
        "madera hasta media altura, el resto es piedra pintada de azul.\n");
    AddDetail(({"techo"}), "Es un techo de madera no muy alto sostenido por "
        "fuertes vigas que lo cruzan de lado a lado.\n");
    AddDetail(({"viga", "vigas"}), "Son gruesos troncos pulidos y pintados "
        "que soportan el peso de la planta superior de la casa. De una de "
        "ellas cuelga una l�mpara de aceite.\n");
    AddDetail(({"lampara","l�mpara"}), "Es una l�mpara de aceite de fino "
        "cristal y de bronce que sirven para iluminar la gran estancia en la "
        "que estamos cuando no hay luz natural.\n");
    AddItem(PNJ("sherek/aldea/guardian2"),REFRESH_DESTRUCT,1);
    AddExit("oeste", SHERALD("casas/casagranja05"));
    AddExit("este", SHERALD("casas/casagranja06"));
    AddExit("abajo", SHERALD("casas/casagranja01"));
    AddExit("arriba", SHERALD("casas/casagranja07"));
}
