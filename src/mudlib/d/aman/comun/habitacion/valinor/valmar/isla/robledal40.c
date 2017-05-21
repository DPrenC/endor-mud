/*****************************************************************************************
 ARCHIVO:       robledal40.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Colina en el Robledal.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("la Colina Iluminada");
    SetIntLong("Estás en la parte este de la Colina. En este punto la vegetación es muy "
        "escasa. Hacia el noroeste, dos grandes robles blancos se alzan con esplendor. "
        "Entre los robles se ha formado un arco perfecto.\n");
    AddDetail(({"robles", "grandes robles", "robles blancos"}), "No parecen robles "
        "comunes sino alguna otra especie más extraña.\n");
    AddDetail(({"raices", "ramas", "arco"}), "Varias raices aparecen mágicamente desde el "
        "suelo, y ascienden entramándose con las ramas formando un gran arco.\n");
    SetIntSmell("Huele a nueces.\n");
    SetIntNoise("Se oye un leve rumor de hojas.\n");
    SetIndoors(0);

    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal41_jardin.c"));
    AddExit("suroeste", HAB_BOSQUE_ISLA("robledal37.c"));
}
