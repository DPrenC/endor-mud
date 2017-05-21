/*
DESCRIPCION  : Kabia, esposa del propietario de la fonda el "Jabali feroz"
FICHERO      : /d/akallab/comun/pnj/kabia.c
MODIFICACION : 24-04-98 [Angor@Simauria]Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Kabia","orco",15,GENERO_FEMENINO);
    SetName("Kabia");
    SetShort("Kabia, la esposa de Grogor");
    SetLong("Kabia es la esposa de Grogor, el propietario. Es una orca grande y fornida con un "
        "fuerte carácter. Es la cocinera de la fonda y siempre anda atareada de un lado a otro "
        "de la cocina atendiendo a las distintas comidas que ha de preparar a la vez.\n");
    SetAlign(-500);
    AddId(({"kabia","Kabia","cocinera","orca"}));
    InitChats(10,({"Kabia mira en una de las ollas al fuego, y remueve su contenido con un "
            "cucharón.\n",
        "Kabia añade un poco de carbón a la caldera de la cocina.\n",
        "Grogor entra en la cocina y al momento sale cargado con varias fuentes y jarras.\n",
        "Kabia pela unas patatas y las trocea para luego echarlas en una de las ollas.\n",
        "Kabia levanta la tapa de una olla, huele su contenido y la vuelve a tapar.\n",
        "Grogor grita desde la fonda: ¡Kabia!, ¿queda aún algo de guiso de ternera?\n",
        "Kabia le da media vuelta al jabalí ensartado en el asador y lo rocía con vino.\n",
        "Kabia dice: Dios, ¡qué gente más impaciente! No doy abasto.\n",
        "Una olla de las que están al fuego comienza a hervir ruidosamente.\n",
        "Kabia coge un cucharón de la tabla de los cacharros.\n",
        "Kabia lava unos platos en la pila y los deja secándose sobre un trapo.\n",
        "Grogor entra, coge unas jarras, las llena con vino de un gran tonel y se va.\n",
        "Kabia trocea una pieza de carne y mete los trozos en una de las ollas al fuego.\n",
        "Kabia dice: ¡Grogor, ven a la cocina un momento!\n"}));
}
