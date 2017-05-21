/****************************************************************************
Fichero: posadera_glucksfall.c
Autor: Buh
Fecha: 29/08/2006
Descripción: una posadera ogra para la posada huesos rotos de Glucksfall.
****************************************************************************/

#include "path.h"
#include <properties.h>
#include <gremios.h>
inherit NPC;

create()
{
    ::create();

        AddId(({"ogra", "mesonera", "posadera", "fea", "pirata", "medio-ogra"}));
    SetStandard("Taraka", "ogro", ([GC_LUCHADOR:55]), GENDER_FEMALE);
    SetShort("Taraka la posadera");
    SetLong(
        "Taraka es una Semi-ogra Excapitana del bajel 'Espolón Sangriento', que tras "
        "tener demasiadas aventuras decidió pasar a una vida mas reposada.\n  Su "
        "ascendencia humana se deja notar en unos grandes e inquisitivos ojos marrones y "
        "en una nariz rectilínea. Mientras que una enorme boca de dientes ennegrecidos y "
        "mellados y un enorme cuerpo robusto y musculoso denotan la sangre de su padre "
        "Ogro al cual nunca conoció.\n  Luce espectaculares tatuajes de motivos "
        "marineros por toda la piel que deja ver.\n");
    SetWeight(120900);
    SetSmell("Huele a ogro medio limpio.\n");
    AddSubDetail("tatuajes", "Diferentes tatuajes con motivos marineros adornan su "
        "piel, puedes ver: una rosa  de los vientos con los puntos cardinales, un  "
        "ancla, una calavera pirata  y algunos nudos marinos.\n");
    InitChats(1, ({"Taraka recoge una mesa.\n",
        "La ogra prepara un conejo para cocinarlo.\n", "Taraka te mira.\n",
    "Taraka te dice: ¿te sirvo algo?.\n"}));
    InitAChats(40, ({"La oghra te ataca con todas sus fuerzas.\n",
        "La ogra respira rapidamente.\n", "La ogra grita: groaaarrrgr!.\n",
        "Taraka grita: ¡no sabes con quien te estás metiendo!.\n",
        "Taraka te grita: ¡te voy a aplastar salvaje!.\n"}));
}
