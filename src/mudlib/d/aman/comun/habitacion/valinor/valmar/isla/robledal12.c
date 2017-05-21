/****************************************************************************************
 ARCHIVO:       robledal12.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCI�N:   Robledal en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("el robledal");
    SetIntLong("Los viejos robles se asoman a trav�s de la niebla blanquecina y h�meda "
        "que envuelve a la isla. Las ramas de unos y otros se trenzan entre si haciendo "
        "muy dif�cil seguir otro camino que no sea el sendero.\n");
    AddDetail("niebla", ".\n");
    AddDetail("ramas", "Profusas y f�rtiles ramas se curvan como si imitaran largos "
         "brazos esquel�ticos. Est�n vestidas con telara�as.\n");
    AddDetail(({"telara�as", "telaranyas"}), "Forman un tejido espeso y de aspecto "
        "sedoso. Est�n llenas de peque�as gotitas de agua.\n\n");
    AddDetail("suelo", "No ves el suelo en el que pisas a causa de la niebla.\n");
    AddDetail(({"robles", "viejos robles"}), "Parecen altos, est�n repletos de hojas "
        "secas y otras nuevas que empiezan a crecer.\n");
    AddDetail("sendero", "Se trata de un min�sculo camino de color oscuro, est� lleno de "
        "piedrecillas.\n");

    SetIntSmell("Un olor dulz�n y penetrante, fruto de la descomposici�n de la materia "
        "vegetal, y del olor desprendido por los �rboles y plantas.\n");
    SetIntNoise("Escuchas ligeros crujidos de ramas.\n");

    AddExit("noreste", HAB_BOSQUE_ISLA("robledal17.c"));
    AddExit("sur", HAB_BOSQUE_ISLA("robledal08.c"));
}
