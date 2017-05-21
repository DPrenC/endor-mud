/***
Fichero: murcielago.c
autor: kastwey@simauria
Descripción:
Murciélago para las celdas... Retocado del de la mina de novatos de limbo.
Gracias woo y angor por ahorrarme el trabajo de codear las descripciones :)
***/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <gremios.h>


inherit NPC;

create() {
    ::create();

    SetStandard("un murcielago", "murcielago", ([ GC_TORPE: 3]), GENDER_MALE);
    SetShort("un murcielago");
    SetLong(
        "Es un murcielago. Te recuerda a una pequeña rata, solo que con alas y unas\n"
        "grandes orejas. Es de color oscuro, casi negro, y parece bastante inquieto.\n");
    SetIds(({"murcielago", "vampiro", "murciélago"}));
    SetAds(({"pequenyo", "pequeño"}));
    SetSize(P_SIZE_SMALL);
    SetHands( ({ ({"mordisco", TD_PENETRACION, 4}) }) );
    SetNoGet(1); // no termino de entender porqué quería que se cogiese.
    SetWeight(500);

    InitChats(8, ({
     "El murcielago revolotea a tu alrededor.\n",
     "El murcielago produce un agudo chillido.\n",
     "El murcielago esquiva los obstaculos de forma acrobática al volar.\n",
     "El murcielago se cuelga en un saliente de la roca.\n",
     "El murcielago atrapa algun tipo de bicho que revoloteaba cerca.\n"}));
}
