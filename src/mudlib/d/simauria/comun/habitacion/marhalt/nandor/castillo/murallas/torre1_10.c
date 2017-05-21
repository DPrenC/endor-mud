/****************************************************************************
Fichero: torre1_10.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: la torre noroeste del castillo.
****************************************************************************/

#include "./path.h"
#include <properties.h>
inherit CASTILLO("murallas/alto_torre");
create(){
    ::create();
    SetIntShort("la parte superior del torreón de la Inmolación");
    SetIntLong("Estás en la parte alta del torreón de la Inmolación, un amplio espacio "
    "almenado, en cuyo centro desemboca la escalera que asciende de la primera planta.\n"
    "Desde esta zona se tiene una amplia vista del castillo y las tierras que lo "
    "rodean, con el bosque de Cored al norte, y la aldea de nandor al este. Aquí se "
    "puede dar cavida a gran cantidad de defensores, que en caso de asedio defenderían "
    "desde su altura las puertas y murallas circundantes.\n");
    AddDetail("almenas", "Es un fuerte muro de piedra rematado por unos fustes "
    "rectangulares entre los cuales hay huecos para facilitar la defensa de la muralla.\n"
    "El antepecho de las almenas, sobresale de forma perceptible hacia "
    "fuera, para dificultar la escalada de qien pretenda penetrar por aquí en el castillo.\n");
    AddDetail("suelo", "El suelo está formado por pesadas losas de piedra  que "
    "aparecen ennegrecidas y carcomidas como si el fuego las hubiera dañado.\n");
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

    AddExit("sur", "./torre1_09");
    AddExit("oeste", "./torre1_11");
    AddExit("suroeste", "./escalera1_3");
}

