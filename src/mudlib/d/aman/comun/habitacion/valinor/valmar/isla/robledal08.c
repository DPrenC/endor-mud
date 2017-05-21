/*****************************************************************************************
 ARCHIVO:       robledal08.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Sendero a través del robledal.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("el bosque de los druidas");
    SetIntLong("Te encuentras rodead" + AO + " de viejos robles. Algunos de ellos están "
        "retorcidos sobre su tronco. Otros, por el contrario, se elevan con una rectitud "
        "vertiginosa. Entre ellos, se arremolinan espinos y zarzales que crecen sin "
        "control. Hacia el sur puedes apreciar un grupo de rocas.\n");
    AddDetail(({"robles", "viejos robles"}), "Están cubiertos de hojas dentadas y de "
        "agallas.\n");
    AddDetail(({"hojas dentadas", "hojas"}), "Cubren las ramas de los robles y el suelo "
        "desde el que crecen éstos.\n");
    AddDetail("agallas", "Son unas bolas de color marrón profundo, que aparecen como "
        "deformaciones en las ramas.\n");
    AddDetail(({"espinos", "zarzales"}), "La mayoría están secos y se enredan unos con "
        "otros creando una barrera espinada.\n");
    AddDetail(({"rocas", "grupo de rocas"}), "Parecen de color negro y están bastante "
        "elevadas.\n");
    AddDetail("suelo", "Está lleno de hojas y ramitas secas.\n");

    SetIntSmell("Un olor dulzón y penetrante, fruto de la descomposición de la materia "
        "vegetal, y del olor desprendido por los árboles y plantas.\n");
    SetIntNoise("Escuchas ligeros crujidos de ramas.\n");

    AddExit("norte", HAB_BOSQUE_ISLA("robledal12.c"));
    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal11.c"));
    AddExit("suroeste", HAB_BOSQUE_ISLA("robledal03.c"));
}
