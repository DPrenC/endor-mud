
#include "./path.h"
#include <properties.h>
#include <sounds.h>
inherit NPC;
public void snd_ladrido();
public void snd_gruñido();
create()
{
    ::create();
    SetStandard("un perro", "animal", 2+d3(), GENDER_MALE);
    SetShort("un perro pulgoso");
    SetLong("Este perro parece que no ha comido bien en algún tiempo. "
    "Las que sí han comido bien son el rebaño de pulgas que lleva encima.\n");
    AddId(({"perro", "perro pulgoso"}));
    SetAlign(50);
    SetHands(({
 ({"la pata delantera izquierda",0,1}),
    ({"la pata delantera derecha",0,1}),
    ({"los colmillos",1,2})
    }));
    InitChats(7, ({"El perro olfatéa en un rincón.\n",
        SF(snd_ladrido), SF(snd_gruñido)}));
    SetGoChance(45);
    AddWalkZones(MARH("nandor"));
}

public void snd_ladrido(){
    tell_room(environment(), "El perro ladra: '¡¡Guau, guau!!'\n");
    play_sound(environment(), SND_PNJS("ladrido"));
}

public void snd_gruñido(){
    tell_room(environment(), "El perro gruñe: 'Grrrr...'\n");
    play_sound(environment(), SND_PNJS("grunido"));
}
