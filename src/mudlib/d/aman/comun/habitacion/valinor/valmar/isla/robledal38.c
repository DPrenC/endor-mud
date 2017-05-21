/*****************************************************************************************
 ARCHIVO:       robledal38.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCI�N:   Colina en el Robledal.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("la Colina Iluminada");
    SetIntLong("Te encuentras en la loma de la Colina. No es el punto m�s alto ya que "
        "hacia el oeste se elevan un conjunto de rocas. La vegetaci�n es inexistente, "
        "y no hay indicios de niebla. Hacia el nordeste contemplas dos enormes robles "
        "blancos cuyas raices y ramas forman un arco.\n");
    AddDetail(({"rocas", "conjunto de rocas"}), "Desprenden una tenue luz azulada.\n");
    AddDetail(({"robles", "enormes robles", "robles blancos"}), "No parecen robles "
        "comunes sino alguna otra especie m�s extra�a.\n");
    AddDetail(({"raices", "ramas", "arco"}), "Las raices aparecen m�gicamente desde el "
        "suelo, y ascienden entram�ndose con las ramas formando un gran arco.\n");
    SetIntSmell("Huele a nueces.\n");
    SetIntNoise("Se oye un leve rumor de hojas.\n");
    SetIndoors(0);

    AddExit("noreste", HAB_BOSQUE_ISLA("robledal41_jardin.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal37.c"));
}
