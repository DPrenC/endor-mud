/* Archivo: /d/simauria/comun/pnj/abadia/caballot.c
* Descripción: Caballo de tiro para la granja.
* Autor: Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <sounds.h>
inherit NPC;

private string relinchar()
{
    play_sound(environment(),SND_PNJS("relincho"));
    return "Un caballo relincha.\n";
}
    
private string resoplar()
{
    play_sound(environment(),SND_PNJS("bufido_caballo"));
    return "Un caballo resopla impaciente.\n";
}
    
create()
{
    ::create();
    SetStandard("un caballo percherón","caballo",20+d6(),GENERO_MASCULINO);
    SetShort("Un caballo percherón");
    SetLong("Es un animal macizo y fuerte.\nSus patas son gruesas y "
        "musculosas, apropiadas para el tiro de carros y arados.\n");
    AddId(({"caballo","percheron","percherón"}));
    SetNoGet("Al acercarte, el caballo te amenaza con sus cascos. Decides mantener las distancias.\n");
    SetHands(({({"una pata",2,8}),
        ({"otra pata",2,8})}));
    InitChats(5,({SF(relinchar),
        "Un caballo mordisquea el heno.\n",
        SF(resoplar),
        "Un caballo patea nervioso.\n"}));
    InitAChats(10,({"El caballo arremete contra ti echando espuma de rabia.\n"}));
}
