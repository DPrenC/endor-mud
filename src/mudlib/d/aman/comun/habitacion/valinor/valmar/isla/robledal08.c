/*****************************************************************************************
 ARCHIVO:       robledal08.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCI�N:   Sendero a trav�s del robledal.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("el bosque de los druidas");
    SetIntLong("Te encuentras rodead" + AO + " de viejos robles. Algunos de ellos est�n "
        "retorcidos sobre su tronco. Otros, por el contrario, se elevan con una rectitud "
        "vertiginosa. Entre ellos, se arremolinan espinos y zarzales que crecen sin "
        "control. Hacia el sur puedes apreciar un grupo de rocas.\n");
    AddDetail(({"robles", "viejos robles"}), "Est�n cubiertos de hojas dentadas y de "
        "agallas.\n");
    AddDetail(({"hojas dentadas", "hojas"}), "Cubren las ramas de los robles y el suelo "
        "desde el que crecen �stos.\n");
    AddDetail("agallas", "Son unas bolas de color marr�n profundo, que aparecen como "
        "deformaciones en las ramas.\n");
    AddDetail(({"espinos", "zarzales"}), "La mayor�a est�n secos y se enredan unos con "
        "otros creando una barrera espinada.\n");
    AddDetail(({"rocas", "grupo de rocas"}), "Parecen de color negro y est�n bastante "
        "elevadas.\n");
    AddDetail("suelo", "Est� lleno de hojas y ramitas secas.\n");

    SetIntSmell("Un olor dulz�n y penetrante, fruto de la descomposici�n de la materia "
        "vegetal, y del olor desprendido por los �rboles y plantas.\n");
    SetIntNoise("Escuchas ligeros crujidos de ramas.\n");

    AddExit("norte", HAB_BOSQUE_ISLA("robledal12.c"));
    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal11.c"));
    AddExit("suroeste", HAB_BOSQUE_ISLA("robledal03.c"));
}
