/********************************************
*    Nombre: cueva02.c			    *
*    Localizacion: Cueva de los Trolls      *
*    Realizada por : Cajun, el ejecutor     *
*    Creado : 20-10-99                      *
*    Modificado:                            *
*********************************************/


#include "./path.h"
#include <properties.h>

inherit MARHCUEVA("cueva_base");

create () {
    ::create();
    SetIntShort("el tramo inicial de la cueva");
    SetIntLong("La gruta se adentra hacia el norte internándose en la oscura montaña,"
    " mientras que una escarpada rampa natural de varios metros hacia arriba parece "
    "llevar a alguna parte de la cueva con un leve atisgo de luz natural.\n El suelo "
    "muestra ciertas dificultades para moverse, y las paredes presentan un alto nivel "
    "de humedad, algo llama la atención en una de ellas.\n");
    SetIntSmell("Huele a una fuerte humedad y basura.\n");
    AddDetail(({"paredes", "pared", "algo"}), "Unas marcas extrañas cruzan la pared de "
        "roca de arriba a abajo, parece como si, como si, como si .......\n "
        "¡¡¡¡fueran garras!!!!\n ¡¡¡¡pero de un tamaño increiblemente grandes!!!!\n");
    AddDetail(({"humedad","agua"}),
        "la humedad que cae por las paredes ayuda a que proliferen todo tipo de hongos.\n");
    AddDetail(({"rampa", "rampa natural"}), "Es una rampa que sube a otro nivel de "
    "la cueva, pero el terreno es peligroso y escarpado.\n");
    AddExit("norte", "./cueva03");
    AddExit("arriba", "./cueva01");
}
