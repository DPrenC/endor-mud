/*
DESCRIPCION  : Sigreb, kender siervo de los dioses en la puerta del newbiepark
FICHERO      : /d/limbo/comun/pnj/sigreb.c
MODIFICACION : 28-08-98 [Angor@Simauria] Creacion
               29-06-99 [Angor@Simauria] Wrapeado
--------------------------------------------------------------------------------
*/

#include "./path.h"
#include <properties.h>
inherit NPC;
#define NOMBRE  (capitalize(TP->QueryName()))

int nolucho()
{
    tell_room(environment(),NOMBRE+" intenta atacar a Sigreb. Sigreb salta al otro lado de la "
        "roca, al tiempo que golpea con su pie el estómago de "+NOMBRE+", mientras le grita: "
        "¡¿Pero qué haces, insolente?! Si yo fuera tú, tendría más cuidado, no querría estar "
        "en tu pellejo si los dioses se enfadan contigo.\n",({TP}));
    return notify_fail("Sigreb salta al otro lado de la roca, rechazándote con un golpe "
        "de su pie, mientras te grita: ¡¿Pero qué haces, insolente?! Si yo fuera tú, tendría "
        "más cuidado, no querría estar en tu pellejo si los dioses se enfadan contigo.\n",
        NOTIFY_NOT_VALID);
}

int esquivo()
{
    tell_room(environment(),"Sigreb hace un movimiento rápido. Parece que "+NOMBRE+" intentaba "
        "lanzarle algo.\n",({TP}));
    write("Sigreb hace un rápido quiebro, esquivando tu lanzamiento.\n");
    return 1;
}

create()
{
    ::create();
    SetStandard("Sigreb","kender",50,GENDER_MALE);
    SetChkFightFunction(SF(nolucho));
    SetChkMagicFunction(SF(nolucho));
    SetName("Sigreb");
    SetShort("Sigreb, un siervo de los dioses");
    SetLong("Sigreb es un kender, de eso no hay duda. Los ojillos de este pequeño ser hace "
        "rato que te observan sin perder detalle alguno. Lleva la típica indumentaria de "
        "aquellos que sirven a los dioses en la isla Limbo, una túnica blanca recorrida "
        "verticalmente por una ancha franja de color rojo. Está subido en una gran roca en "
        "medio de este claro del bosque. Es un tipo simpático y descarado.\n");
    SetIds(({"kender","sigreb","Sigreb","siervo"}));
    SetAds(({"siervo","curioso"}));
    SetNoise("Sigreb silva una alegre melodía.\n");
    SetNoGet("Sigreb te dice: ¡Eh, a mí no me toques!\n");
    InitChats(3,
        ({"Sigreb se tumba en la parte superior de la roca y mientras mordisquea una brizna de "
            "hierba, se dedica a contemplar el cielo.\n",
        "Sigreb te mira con curiosidad y dice: ¿Y se supone que tú eres un guerrero?...\n",
        "Sigreb te dice: ¿Sabes? en la zona del bosque que queda al oeste de aquí puedes "
            "encontrar un montón de bichejos que matar. Es como un parque de entrenamiento.'\n",
        "Sigreb dice: Llevas la palabra novato tatuada en la frente. ¡Ja, ja, ja!\n",
        "Sigreb se sienta en el borde de la roca y balancea sus piernas en el aire.\n",
        "Sigreb dice: ¡No me mires tanto que me vas a desgastar! Anda vete al parque.\n",
        "Sigreb saca unos dados de un bolsillo y se pone a jugar con ellos sobre la roca.\n",
        "Sigreb dice: ¡Eooo, despierta! Piensa: tú+parque=entrenamiento. No es tan difícil, "
            "aunque..., ¡parece que eso de pensar no es lo tuyo francamente!'\n"}));
}

init()
{
    ::init();
    add_action("esquivo","lanzar");
}
    