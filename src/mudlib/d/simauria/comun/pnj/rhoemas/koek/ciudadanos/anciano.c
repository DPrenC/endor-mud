/****************************************************************************
Fichero: anciano.c
Autor: Dharkus
Fecha: 06/06/2010
Descripción: Un anciano para Koek
****************************************************************************/


#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit NPC;
#include RHOEDANYO
create() {
    "*"::create();
    
    AddId(({"hombre", "ciudadano", "anciano", "viejo"}));
    SetStandard("un anciano","humano",([GC_TORPE:11]),GENDER_MALE);
    SetShort("un anciano");
    SetLong("Es un anciano de blancos cabellos, con una mirada llena de sabiduría "
    "que te inspira respeto y ternura.\n Parece que esté tomando el aire simplemente "
    "dejando pasar el tiempo.\n");
    InitChats(3,({"El anciano te mira.\n",
      "El anciano dice:\n '¡Quién tubiera ahora juventud y fortaleza!'\n",
      "El anciano suspira.\n",
      "El viejecito te dice:\n 'Este pueblo es muy tranquilo.\n Parece que esos "
      "patrulleros hacen bien su trabajo.'\n"}));
    AddItem(RHOEARM("koek/ciudadanos/pantalones"), REFRESH_REMOVE, SF(wearme));
    AddItem(RHOEARM("koek/ciudadanos/camisa"), REFRESH_REMOVE, SF(wearme));
    SetCitizenship("koek");
}
