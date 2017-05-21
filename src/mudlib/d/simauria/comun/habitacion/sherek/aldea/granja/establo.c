/****************************************************************************
Fichero: /d/simauria/comun/habitacion/sherek/aldea/granja/establo.c
Autor: Lug y Yalin
Fecha: 14/01/2007
Descripci�n: Base para los establos de la granja de la aldea.
****************************************************************************/

#include "path.h"
inherit SHERALD("ceroom");

create()
{
    ::create();
    SetIntShort("un establo en la granja de la aldea de Sloch");
    SetIntLong("Est�s dentro de uno de los establos de la granja. Son unas "
        "estancias bastante grandes donde es recogido todo el ganado una vez "
        "que llega la noche, o donde se estabula durante los inviernos.\n"
        "Adosados a las paredes est�n los pesebres donde se alimenta a las "
        "reses. Al este est� la salida.\n");
    SetIntNoise("Escuchas a los animales.\n");
    SetIntSmell("Huele a animal en cautividad.\n");
    SetIntBright(20);
    AddDetail(({"techo"}), "Est� construido con paja y ca�as entretejidas.\n");
    AddDetail(({"paredes", "pared"}), "Son de gruesos maderos fuertemente "
        "ensamblados. Parecen muy s�lidas.\n");
    AddDetail(({"suelo"}), "Est� cubierto por ca�as, hierbas y espinos.\n");
    AddDetail(({"pesebre", "pesebres", "comedero", "comederos"}), "son unos "
        "recipientes rectangulares de madera adosados a los muros del "
        "establo donde se deja el alimento para los animales.\n");
}
