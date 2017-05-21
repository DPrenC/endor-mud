/* Archivo: /d/simauria/comun/pnj/abadia/caballom.c
* Descripción: Caballo de monta para la granja.
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
    SetStandard("un caballo veloz","caballo",20+d6(),GENERO_MASCULINO);
    SetShort("Un caballo veloz");
    SetLong("Es un animal alto y estilizado.\nSus patas son largas y "
        "flexibles, a propósito para la carrera y los viajes largos.\n");
    AddId(({"caballo","caballo veloz"}));
    SetNoGet("Al acercarte, el caballo te amenaza con sus cascos. Decides mantener las distancias.\n");
    SetHands(({({"una pata",2,6}),
        ({"otra pata",2,6})}));
    InitChats(5,({SF(relinchar),
        "Un caballo mordisquea el heno.\n",
        SF(resoplar),
        "Un caballo patea nervioso.\n"}));
    InitAChats(10,({"El caballo arremete contra ti echando espuma de rabia.\n"}));
}
