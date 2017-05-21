/****************************************************************************
Fichero: torre1_09.c
Autor: Ratwor
Fecha: 30/12/2007
Descripción: la torre noroeste del castillo.
****************************************************************************/

#include "./path.h"

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
    AddExit("norte", "./torre1_10");
    AddExit("noroeste", "./escalera1_3");
    AddExit("oeste", "./torre1_12");
}

