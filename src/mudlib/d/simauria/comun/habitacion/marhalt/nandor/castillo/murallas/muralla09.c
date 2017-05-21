/****************************************************************************
Fichero: muralla09.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: En la muralla del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("murallas/muralla_base");

create(){
    ::create();
    SetIntShort("la muralla, al este de la puerta del castillo");
        SetIntLong("Ésta sección de la muralla se adelanta sobre el foso en un pequeño "
    "baluarte que protege las puertas. En esta parte es algo mas alta, accediéndose a "
    "ella por tres grandes escalones de piedra. Debido a ello, las almenas, mas "
    "reforzadas, están algo mas elevadas que el resto. Con el objetivo de tener mayor "
    "número de puestos de tiro para los arqueros, se ha levantado una pequeña garita "
    "almenada justo encima, a la cual se accede por una escalera de mano.\n"
    "Al este se encuentran las poleas que maniobran el puente levadizo protegidas por "
    "un muro y un estrecho tejadillo y mas allá se localiza una garita similar a la que "
    "se halla sobre ti.\n");
    AddDetail("escalera", "Una sencilla escalera de madera que comunica la garita con "
    "el adarbe.\n");
    AddDetail("garita", "Apoyada sobre el muro frontal dotado de saeteras que sustituye "
    "a las almenas para ofrecer mayor protección, y sobre un pontón trasero de madera, "
    "se ha levantado una rudimentaria garita volada o torrecilla almenada, desde la "
    "cual los arqueros obtienen un excelente puesto de tiro para cubrir el puente "
    "levadizo, e incluso la muralla circundante hasta los torreones.\n"
    "Está construída con piedra de baja calidad y en forma algo descuidada,  "
    "contrastando con la perfección del resto de la obra, lo cual sugiere que se trata de un "
    "añadido posterior.\n");
    AddDetail("bosque", "Al norte del camino de Marhalt, se extiende el bosque de "
    "Cored, una oscura masa de añosos árboles de aspecto ominoso.\n");
    AddDetail(({"colina", "ladera", "declive"}), "Al norte del castillo la ladera de la "
    "colina desciende en un declive poco pronunciado y cubierto de hierba, por el cual "
    "discurre el sendero trillado que al pie de la elevación se une al camino norte de "
    "Marhalt.\n");
    AddDetail("almenas", "Es un fuerte muro de piedra rematado por unos fustes "
    "rectangulares entre los cuales hay huecos para facilitar la defensa de la muralla.\n"
    "El antepecho de esta parte de las almenas, sobresale de forma perceptible hacia "
    "fuera, para dificultar la escalada de qien pretenda penetrar por aquí en el castillo.\n");

    AddExit("sur", "./muralla10");
    AddExit("oeste", "./muralla08");
    AddExit("arriba", "./garita_este");
}


