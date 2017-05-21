/*****************************************************************************************
 ARCHIVO:       robledal22.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCI�N:   Gruta en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("una sala con estalactitas");
    SetIntLong("Cientos de haces de luz arrancan destellos de las formaciones "
        "escult�ricas que te rodean. Delicadas filigranas y espl�ndidos arcos configuran "
        "un decorado singular y luminoso. Sin duda, es una tarea que la naturaleza ha "
        "tardado en realizar miles de a�os.\n");
    AddDetail(({"haces", "haces de luz"}), "No est� muy claro de donde salen, tal es la "
        "magia de este bosque.\n");
    AddDetail("destellos", "Aparecen en los h�medos conos y se esparcen por toda la "
        "estancia.\n");
    AddDetail(({"formaciones", "formaciones escult�ricas", "estalactitas"}), "Penden del "
        "techo como agujas. Las hay de todos los tama�os y de todas las formas.\n");
    AddDetail(("delicadas filigranas", "filigranas"), "Son adornos naturales, y aparecen "
        "por las paredes, el suelo y en las estalactitas.\n");
    AddDetail(({"espl�ndidos arcos", "arcos", "columnas", "cavidades"}), "Hay algunas "
        "estalactitas que se unen con sus estalagmitas formando columnas, arcos y "
        "cavidades por doquier.\n");
    AddDetail("techo", "Es muy brillante y de �l caen peque�as gotas de agua.\n");
    AddDetail("suelo", "En el suelo se han formado peque�os charcos.\n");

    SetIntSmell("Huele a cal h�meda.\n");
    SetIntNoise("Oyes un goteo continuo.\n");

    SetIndoors(1);
    SetIntBright(20);

    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal26.c"));
    AddExit("noreste", HAB_BOSQUE_ISLA("robledal28.c"));
}
