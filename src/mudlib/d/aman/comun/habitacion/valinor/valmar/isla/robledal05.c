/*****************************************************************************************
 ARCHIVO:       robledal05.c
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

    SetIntShort("los alrededores de la posada");
    SetIntLong("Por doquier la urdimbre de las lianas envuelve a pequeños montículos. A "
        "tu alrededor el ambiente es confuso por causa de una espesa canícula que no te "
        "permite observar con detalle. Pese a eso, divisas los muros de piedra de la "
        "posada situados hacia el norte y hacia el este.\n");
    AddDetail("suelo", "Su trazado es especialmente irregular y observas pequeños "
        "senderos probablemente formados por animalillos.\n");
    AddDetail("copas", "Son tan densas que apenas permiten el paso de finísimos rayos de "
        "luz.\n");
    AddDetail("urdimbre", "Las lianas se entrelazan formando una malla casi "
        "impracticable.\n");
    AddDetail(({"canícula", "canicula", "niebla"}), "Es muy espesa, sólo te permite ver "
        "lo que tienes más cerca.\n");
    AddDetail(("muros", "posada"), "Son los muros de la posada, son de piedra y muy "
        "altos.\n");
    AddDetail(({"robles", "altos robles"}), "La corteza de sus troncos es blanquecina y "
        "están repletos de nudos.\n");
    AddDetail("lianas", "La niebla sólo te permite comprobar que su textura está tintada "
        "de verde. Forman finas columnas y enrevesadas redes por cualquier rincón.\n");
    AddDetail(({"montículos", "monticulos"}), "Son como pequeñas colinas pobladas de "
        "matas y pequeñas plantas.\n");
    AddDetail(({"matas", "plantas"}), "Están esparcidas por el suelo.\n");

    SetIntSmell("Un olor dulzón y penetrante, fruto de la descomposición de la materia "
        "vegetal, y del olor desprendido por los árboles y plantas.\n");
    SetIntNoise("Escuchas ligeros crujidos de ramas.\n");

    AddExit("oeste", HAB_BOSQUE_ISLA("robledal04.c"));
    AddExit("sureste", HAB_BOSQUE_ISLA("robledal01.c"));
}
