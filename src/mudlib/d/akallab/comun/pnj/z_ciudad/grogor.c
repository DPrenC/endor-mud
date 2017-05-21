/*
DESCRIPCION  : Grogor, el propietario de la fonda el "Jabali feroz"
FICHERO      : /d/akallab/comun/pnj/grogor.c
MODIFICACION : 23-04-98 [Angor@Simauria]Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Grogor","orco",25,GENERO_MASCULINO);
    SetName("Grogor");
    SetShort("Grogor, el propietario");
    SetLong("Grogor es el propietario de la fonda el Jabalí Feroz. Es un tipo alegre aunque un "
        "poco tosco, que no para de ir de un lado a otro de la fonda atendiendo a sus clientes.\n");
    SetAlign(-500);
    AddId(({"grogor","Grogor","tabernero","camarero","mesonero","propietario","orco"}));
    InitChats(10,({"Grogor se va hacia una mesa al fondo de la fonda.\nGrogor vuelve de una "
            "mesa al fondo de la fonda.\n",
        "Grogor entra en la cocina y al momento sale cargado con varias fuentes y jarras.\n",
        "Un cliente grita: ¡Hey, Grogor, a ver cuándo vienes a atender aquí de una vez!\n",
        "Grogor dice a un cliente: ¡Marchando su comida!\n",
        "Alguien grita: ¡Que se calle ese maldito bardo de una vez!\n",
        "Grogor le dice a alguien: Un momento, lo suyo ya casi está hecho.\n",
        "Un cliente dice: ¡Grogor, esto estaba muy bueno, trae otro de lo mismo!\n",
        "Grogor te dice: Si quieres ver la lista de comidas, mira el menú.\n",
        "Alguien dice: ¡Esto está muerto! Tú, bardo, ¡cántanos alguna canción alegre!\n",
        "Grogor te dice: Tras elegir tu comida, simplemente pídela y te la serviré.\n",
        "Un cliente dice: ¡Grogor, otra ronda para mis amigos! Esta vez pagaré yo.\n",
        "Grogor dice: Un momento, ya voy. Dios, ¡qué gente más impaciente!\n",
        "Alguien dice: ¡Hey, Grogor! Dile a Kabia que su asado está muy bueno hoy.\n",
        "Kabia grita desde la cocina: ¡Grogor, ven a la cocina un momento!\n"}));
}
