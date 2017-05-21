/****************************************************************************
Fichero: joven_ciudadano.c
Autor: Dharkus
Fecha: 02/06/2010
Descripción: Un joven ciudadano para Koek.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
#include RHOEDANYO
create() {
    "*"::create();
    
    AddId(({"joven","ciudadano"}));
    SetStandard("un joven","humano",([GC_TORPE:14]),GENDER_MALE);
    SetShort("un joven ciudadano");
    SetLong("Es un joven de cabellos rojizos.\n Sus grandes ojos verdes parecen "
    "tener un brillo especial.\n Va repitiendo rimas en voz alta, y de tanto en "
    "tanto suelta una ruidosa carcajada que aturde el entorno.\n");
    InitChats(4,({"El joven se ríe ruidosamente.\n",
    "El joven dice:\n '¡La vida es una alegría,\n y el amor más todavía!'\n",
    "El ciudadano recita:\n 'Una belleza a mi lado,\n hace más corto el camino.\n "
    "¡qué rico está un buen bocado,\n cuando se riega con vino!'\n",
    "El joven ciudadano te sonríe.\n",
    "El joven te mira.\n"}));
    AddQuestion("rimas","El joven dice:\n '¡sí! ¿mis rimas?\n son unos versillos "
    "que yo escribo inspirados en la vida, en las mujeres bonitas y en el amor.\n "
    "¿quieres que te recite alguno?'\n");
    AddItem(RHOEARM("koek/ciudadanos/pantalones"), REFRESH_REMOVE, SF(wearme));
    AddItem(RHOEARM("koek/ciudadanos/camisa"), REFRESH_REMOVE, SF(wearme));
    SetCitizenship("koek");
    SetGoChance(20);
    AddWalkZones(RHOEHAB("koek"));
}
