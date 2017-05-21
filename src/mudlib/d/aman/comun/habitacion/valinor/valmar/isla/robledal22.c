/*****************************************************************************************
 ARCHIVO:       robledal22.c
 AUTOR:         Ztico
 FECHA:         03-05-2005
 DESCRIPCIÓN:   Gruta en la Isla de los druidas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_ISLA;

create()
{
    if(::create()) return 1;

    SetIntShort("una sala con estalactitas");
    SetIntLong("Cientos de haces de luz arrancan destellos de las formaciones "
        "escultóricas que te rodean. Delicadas filigranas y espléndidos arcos configuran "
        "un decorado singular y luminoso. Sin duda, es una tarea que la naturaleza ha "
        "tardado en realizar miles de años.\n");
    AddDetail(({"haces", "haces de luz"}), "No está muy claro de donde salen, tal es la "
        "magia de este bosque.\n");
    AddDetail("destellos", "Aparecen en los húmedos conos y se esparcen por toda la "
        "estancia.\n");
    AddDetail(({"formaciones", "formaciones escultóricas", "estalactitas"}), "Penden del "
        "techo como agujas. Las hay de todos los tamaños y de todas las formas.\n");
    AddDetail(("delicadas filigranas", "filigranas"), "Son adornos naturales, y aparecen "
        "por las paredes, el suelo y en las estalactitas.\n");
    AddDetail(({"espléndidos arcos", "arcos", "columnas", "cavidades"}), "Hay algunas "
        "estalactitas que se unen con sus estalagmitas formando columnas, arcos y "
        "cavidades por doquier.\n");
    AddDetail("techo", "Es muy brillante y de él caen pequeñas gotas de agua.\n");
    AddDetail("suelo", "En el suelo se han formado pequeños charcos.\n");

    SetIntSmell("Huele a cal húmeda.\n");
    SetIntNoise("Oyes un goteo continuo.\n");

    SetIndoors(1);
    SetIntBright(20);

    AddExit("noroeste", HAB_BOSQUE_ISLA("robledal26.c"));
    AddExit("noreste", HAB_BOSQUE_ISLA("robledal28.c"));
}
