/****************************************************************************
Fichero: joven_ciudadana.c
Autor: Dharkus
Fecha: 24/05/2010
Descripción: Una joven ciudadana para Koek.
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
#include RHOEDANYO
create() {
    "*"::create();
    
    SetStandard("una joven","humano",([GC_TORPE:12]),GENDER_FEMALE);
    SetIds(({"joven","ciudadana", "humana"}));
    SetShort("una joven ciudadana");
    SetLong("Es una joven muy bonita de cabellos claros y grandes ojos azules.\n "
    "Camina contorneando todo su cuerpo como si pretendiese llamar la atención.\n");
    InitChats(4,({"La joven ciudadana saca un espejo y se mira.\n",
    "La joven contempla la piedra de su anillo.\n",
    "La ciudadana se alisa la falda con un movimiento de cadera.\n",
    "La joven ciudadana te sonríe dulcemente.\n",
    "La joven te mira.\n"}));
    AddQuestion("anillo","La joven dice:\n '¡Ah, sí! ¿mi anillo?\n Es un regalo "
    "de una persona muy especial, y pienso llevarlo siempre conmigo.'\n");
    AddItem(RHOEARM("koek/ciudadanos/blusa"), REFRESH_REMOVE, SF(wearme));
    AddItem(RHOEARM("koek/ciudadanos/falda"), REFRESH_REMOVE, SF(wearme));
    AddItem(RHOEARM("koek/ciudadanos/anillo_plata"), REFRESH_REMOVE, SF(wearme));
    SetCitizenship("koek");
    SetGoChance(20);
    AddWalkZones(RHOEHAB("koek"));
}
