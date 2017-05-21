/* Archivo: /d/simauria/comun/pnj/abadia/caballos.c
* Descripción: Caballo semental para la granja.
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
    SetStandard("un caballo semental","caballo",20+d6(),GENERO_MASCULINO);
    SetShort("Un caballo semental");
    SetLong("Es un animal grande y elegante.\nEs un purasangre, destinado a la "
        "cría de caballos en la granja.\n");
    AddId(({"caballo","semental","purasangre"}));
    SetNoGet("Al acercarte, el caballo te amenaza con sus cascos. Decides mantener las distancias.\n");
    SetHands(({({"una pata",2,7}),
        ({"otra pata",2,7})}));
    InitChats(5,({SF(relinchar),
        "Un caballo mordisquea el heno.\n",
        SF(resoplar),
        "Un caballo patea nervioso.\n"}));
    InitAChats(10,({"El caballo arremete contra ti echando espuma de rabia.\n"}));
}
