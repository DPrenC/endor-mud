/****************************************************************************
Fichero: entrada.c
Autor: Riberales
Fecha: 14/02/2006
Descripción: Entrada del gremio de kisalas. Remodelación espacial total.
Notas: [R] No tenía ni fecha, así que le he puesto la actual.
modificación:
08/05/2007, [Y] (Yalin): añado una fuente.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <sounds.h>
inherit INTERIOR_BASE;

create()
{
    ::create();
    SetIntShort("la entrada al gremio de las kisalas");
    SetIntLong("Estás en la entrada al Gremio de las KISALAS. Se trata de una "
               "estancia grande, labrada en piedra y llena de bajorrelieves "
               "que simbolizan la historia de la fundadora de la Orden: Shalei "
               "Kisala. En la pared de esta sala, aparte de los relieves que la "
               "adornan, existen unas enormes espirales fosforescentes que son "
               "las que iluminan el lugar. En el suelo hay un mosaico con el "
               "símbolo de las Kisalas. Hacia el sur, puedes ver la salida "
               "del gremio.\n");


    AddDetail(({"relieve","bajorrelieve","relieves","bajorrelieves"}),
                "Son relieves que representan diferentes momentos históricos "
                "de las Kisalas.\n");

    AddDetail(({"piedras","piedras verdes"}),
        "Podrían ser esmeraldas, pero no crees que estuvieran ya ahí si lo fueran...\n");

    AddDetail(({"grabado","grabados"}),
                "Son unos grabados que ilustran la vida de las Kisalas.\n");

    AddItem(AM_OBJETO("fuente"));
    SetSoundEnvironment(SND_AMBIENTES("agua_fuente"));

    AddExit("sur",LAGO("embarcadero"));
    AddExit("noroeste",AM_VESTIBULO("vest3"));
    AddExit("norte",AM_VESTIBULO("vest4"));
    AddExit("oeste",AM_VESTIBULO("vest1"));
    AddExit("nordeste",AM_VESTIBULO("vest5"));
    AddExit("este",AM_VESTIBULO("vest2"));
}
