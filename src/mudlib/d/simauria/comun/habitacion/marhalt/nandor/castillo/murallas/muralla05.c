/****************************************************************************
Fichero: muralla05.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: En la muralla del castillo.
****************************************************************************/

#include "./path.h"
#include <properties.h>
inherit CASTILLO("murallas/muralla_base");

create(){
    ::create();
    SetIntLong("Te encuentras sobre el adarbe de la muralla norte del castillo.\n"
    "Al frente se sitúa la ladera menos empinada y accesible de la colina, y mas allá "
    "el gran bosque de Cored. Por todo ello, la muralla fue construída en piedra maciza "
    "en sus tres metros de anchura, dotada de unas robustas almenas y rematada en cada "
    "extremo por dos fuertes torreones redondos: el de Cónor al este y el de la "
    "Inmolación al oeste.\n"
    "Toda la parte norte del castillo, muralla, torreones y puertas, son de "
    "construcción mas antigua que el resto de la fortaleza, y detalles como la forma de "
    "las almenas o el tamaño de los bloques y su colocación muy ajustada dan la "
    "impresión de que las manos que levantaron esta zona eran mas hábiles y tenían mas "
    "conocimientos de arquitectura que quienes edificaron el resto del castillo.\n"
    "Encajada contra la muralla hay una pequeña catapulta que defiende esta sección "
    "del muro.\n");
    AddDetail("puertas", "Las puertas del castillo se sitúan justo en el centro de la "
    "muralla norte. Se adelantan ligeramente con respecto a la muralla, y la parte alta "
    "está defendida por una garita volada a cada lado, lo que les da un aspecto de "
    "gran solidez.\n");
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

    AddItem(THING, REFRESH_REMOVE,
    ([P_SHORT: "una pequeña catapulta",
    P_LONG: "ES una pequeña catapulta "
    "de poco alcance encajada contra las almenas y bastante descuidada. Está formada "
    "por un bastidor horizontal de madera rectangular apoyado en el suelo sobre el que "
    "se sujeta una pieza similar en posición vertical, cuya utilidad es la de frenar el "
    "brazo propulsor, un madero ligero pero fuerte rematado en una especie de cuchara "
    "metálica algo oxidada donde se cargan los proyectiles, que mediante la fuerza de "
    "torsión aportada por unas gruesas cuerdas retorcidas, sale disparado lanzando su "
    "carga en una trayectoria ascendente.\n",
    P_WEIGHT: 1000000, P_GENDER: GENDER_FEMALE,
    P_IDS: ({"pequeña catapulta", "pequena catapulta", "catapulta"})]));
    AddItem(THING, REFRESH_REMOVE,
    ([P_SHORT: "un bloque de piedra",
        P_LONG: "Es un pequeño bloque de piedra que debió de sobrar de alguna de las "
            "murallas y ahora se utiliza como proyectil para las catapultas.\n",
        P_WEIGHT: 9000, P_IDS: ({"piedra", "bloque de piedra", "bloque"})]), d8());
    AddExit("este", "./muralla06");
    AddExit("oeste", "./muralla04");
}


