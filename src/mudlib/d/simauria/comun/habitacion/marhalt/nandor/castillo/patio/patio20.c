/****************************************************************************
Fichero: patio20.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: El patio de armas del castillo.
****************************************************************************/

#include "./path.h"

inherit CASTILLO("patio/patio_base");

create(){
    ::create();
    AddDetail(({"murallas", "muralla"}), "Las fuertes murallas que protegen el castillo "
    "cercan el patio de armas por tres de sus lados, alzándose en hileras de grandes "
    "bloques de piedra cada una de las cuales se apoya sobre otras dos, haciendo el "
    "muro mas resistente y evitando que se derrumbe por el peso.\n"
    "Una empinada y estrecha escalera comunica esta zona del patio con lo alto de la "
    "muralla.\n");
    AddDetail("escalera", "Una empinada escalera de piedra con algunos escalones a "
    "medio derrumbar que une el patio de armas con la muralla sur.\n");
    AddExit("este", "./patio21");
    AddExit("norte", "./patio18");
    AddExit("nordeste", "./patio19");
    AddExit("arriba", CASTILLO("murallas/muralla23"));
}


