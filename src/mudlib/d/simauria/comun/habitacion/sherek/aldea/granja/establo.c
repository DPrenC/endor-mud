/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/granja/establo.c
Autor: Lug y Yalin
Fecha: 14/01/2007
Descripción: Base para los establos de la granja de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("un establo en la granja de la aldea de Sloch");
    SetIntLong("Estás dentro de uno de los establos de la granja. Son unas "
        "estancias bastante grandes donde es recogido todo el ganado una vez "
        "que llega la noche, o donde se estabula durante los inviernos.\n"
        "Adosados a las paredes están los pesebres donde se alimenta a las "
        "reses. Al este está la salida.\n");
    SetIntNoise("Escuchas a los animales.\n");
    SetIntSmell("Huele a animal en cautividad.\n");
    SetIntBright(20);
    AddDetail(({"techo"}), "Está construido con paja y cañas entretejidas.\n");
    AddDetail(({"paredes", "pared"}), "Son de gruesos maderos fuertemente "
        "ensamblados. Parecen muy sólidas.\n");
    AddDetail(({"suelo"}), "Está cubierto por cañas, hierbas y espinos.\n");
    AddDetail(({"pesebre", "pesebres", "comedero", "comederos"}), "son unos "
        "recipientes rectangulares de madera adosados a los muros del "
        "establo donde se deja el alimento para los animales.\n");
}
