/****************************************************************************
Fichero: rata.c
Autor: Ratwor
Fecha: 23/09/2007
Descripción: Una rata.
****************************************************************************/
#include <properties.h>
#include <sounds.h>
#include <combat.h>
inherit NPC;
public void chillido();
create() {
    ::create();
    SetStandard("una rata", "roedor", d3(), GENDER_FEMALE);
    SetShort("una rata");
    SetLong("Es una horrible rata que no tiene muy buen aspecto.\n");
    SetWeight(1500);
    AddId(({"roedor", "horrible rata", "rata"}));
    SetHands(({({"la pata delantera derecha",0,1}),
	     ({"la pata delantera izquierda",0,1}),
	     ({"los dientes",0,1})}));
    InitChats(5,({"La rata escarba en el suelo buscando algo para roer.\n",
        "La rata corretea.\n",
        SF(chillido)}));
    InitAChats(10,({
	    "La rata te muerde los pies.\n", SF(chillido)}));
}

public void chillido(){
    tell_room(environment(), "La rata chilla.\n");
    play_sound(environment(), SND_PNJS("ratas"), 0, 60);
}

