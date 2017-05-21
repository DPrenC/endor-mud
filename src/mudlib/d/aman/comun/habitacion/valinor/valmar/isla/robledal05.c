/*****************************************************************************************
 ARCHIVO:       robledal05.c
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

    SetIntShort("los alrededores de la posada");
    SetIntLong("Por doquier la urdimbre de las lianas envuelve a peque�os mont�culos. A "
        "tu alrededor el ambiente es confuso por causa de una espesa can�cula que no te "
        "permite observar con detalle. Pese a eso, divisas los muros de piedra de la "
        "posada situados hacia el norte y hacia el este.\n");
    AddDetail("suelo", "Su trazado es especialmente irregular y observas peque�os "
        "senderos probablemente formados por animalillos.\n");
    AddDetail("copas", "Son tan densas que apenas permiten el paso de fin�simos rayos de "
        "luz.\n");
    AddDetail("urdimbre", "Las lianas se entrelazan formando una malla casi "
        "impracticable.\n");
    AddDetail(({"can�cula", "canicula", "niebla"}), "Es muy espesa, s�lo te permite ver "
        "lo que tienes m�s cerca.\n");
    AddDetail(("muros", "posada"), "Son los muros de la posada, son de piedra y muy "
        "altos.\n");
    AddDetail(({"robles", "altos robles"}), "La corteza de sus troncos es blanquecina y "
        "est�n repletos de nudos.\n");
    AddDetail("lianas", "La niebla s�lo te permite comprobar que su textura est� tintada "
        "de verde. Forman finas columnas y enrevesadas redes por cualquier rinc�n.\n");
    AddDetail(({"mont�culos", "monticulos"}), "Son como peque�as colinas pobladas de "
        "matas y peque�as plantas.\n");
    AddDetail(({"matas", "plantas"}), "Est�n esparcidas por el suelo.\n");

    SetIntSmell("Un olor dulz�n y penetrante, fruto de la descomposici�n de la materia "
        "vegetal, y del olor desprendido por los �rboles y plantas.\n");
    SetIntNoise("Escuchas ligeros crujidos de ramas.\n");

    AddExit("oeste", HAB_BOSQUE_ISLA("robledal04.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal01.c"));
}
