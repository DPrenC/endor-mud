/****************************************************************************************
 ARCHIVO:       robledal12.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("el robledal");
    SetIntLong("Los viejos robles se asoman a través de la niebla blanquecina y húmeda "
        "que envuelve a la isla. Las ramas de unos y otros se trenzan entre si haciendo "
        "muy difícil seguir otro camino que no sea el sendero.\n");
    AddDetail("niebla", ".\n");
    AddDetail("ramas", "Profusas y fértiles ramas se curvan como si imitaran largos "
         "brazos esqueléticos. Están vestidas con telarañas.\n");
    AddDetail(({"telarañas", "telaranyas"}), "Forman un tejido espeso y de aspecto "
        "sedoso. Están llenas de pequeñas gotitas de agua.\n\n");
    AddDetail("suelo", "No ves el suelo en el que pisas a causa de la niebla.\n");
    AddDetail(({"robles", "viejos robles"}), "Parecen altos, están repletos de hojas "
        "secas y otras nuevas que empiezan a crecer.\n");
    AddDetail("sendero", "Se trata de un minúsculo camino de color oscuro, está lleno de "
        "piedrecillas.\n");

    SetIntSmell("Un olor dulzón y penetrante, fruto de la descomposición de la materia "
        "vegetal, y del olor desprendido por los árboles y plantas.\n");
    SetIntNoise("Escuchas ligeros crujidos de ramas.\n");

    AddExit("noreste", HAB_BOSQUE_ISLA("robledal17.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("robledal08.c"));
}
