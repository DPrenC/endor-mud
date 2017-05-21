/* Archivo: /d/simauria/comun/habitacion/sherek/aldea/casas/casagranja00.c
* Descripción: explanada frente a la casa del administrador.
* Autor: Lug y Yalin.
*/

#include "path.h"
inherit SHERALD("abroom");

create()
{
    ::create();
    SetPreIntShort("frente a");
    SetIntShort("la casa del administrador");
    SetIntLong("Esto es una explanada delante de la casa de administración de "
        "la granja.\nAquí es donde, los días señalados, se recoge el pago en "
        "especias, productos que servirán para el consumo de los monjes de "
        "la abadía, y que son entregados como parte del tributo.\nAl este se "
        "halla la casa, mientras que al oeste vuelves a la granja.\n");
    SetIntSmell("Llega el olor de la granja y los campos cercanos.\n");
    SetIntNoise("Sólo se oye a lo lejos los golpes de azadón de los trabajos "
        "del campo.\n");
    AddDetail(({"este","casa"}), "Desde aquí sólo puedes ver la pared "
        "frontal y la puerta de entrada.\n");
    AddDetail(({"pared","pared frontal"}), "Una pared echa con ladrillos y "
        "pintada de blanco con cal.\n");
    AddDetail(({"puerta","puerta de entrada"}), "Una puerta de madera con el "
        "escudo de Sherek pintado, y la palabra 'ADMINISTRACIÓN', igualmente "
        "pintada sobre la madera.\n");
    AddDetail(({"escudo"}), "Es la imagen de una mujer, con una serpiente "
        "enroscada en su brazo derecho, a la que decapita con una daga que "
        "sostiene en su mano izquierda.\n");
    AddItem(PNJ("sherek/aldea/guardian2"),REFRESH_DESTRUCT,1);
    AddExit("este", SHERALD("casas/casagranja01"));
    AddExit("oeste", SHERALD("granja/granja00"));
}
