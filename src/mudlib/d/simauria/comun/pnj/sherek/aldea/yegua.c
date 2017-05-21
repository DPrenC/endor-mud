/* Archivo: /d/simauria/comun/pnj/abadia/yegua.c
* Descripción: Yeguas para la granja.
Autor: Lug y Yalin.
*/
#include "path.h"
#include <properties.h>
#include <guild.h>
#include <sounds.h>
inherit NPC;

private string relinchar()
{
    play_sound(environment(),SND_PNJS("relincho"));
    return "Una yegua relincha intranquila.\n";
}
    
private string resoplar()
{
    play_sound(environment(),SND_PNJS("bufido_caballo"));
    return "La yegua te cocea resoplando furiosa.\n";
}
    
create()
{
    ::create();
    SetStandard("una yegua","yegua",([ GC_TORPE:15+d10() ]), GENERO_FEMENINO);
    SetShort("Una yegua");
    SetLong("Es una preciosa yegua, de gran porte y aspecto saludable.\n"
        "Probablemente ha sido traída de lejos para la cría de caballos.\n");
    AddId(({"yegua"}));
    SetNoGet("Al acercarte a ella, la yegua se muestra agresiva. Decides no molestarla.\n");
    SetHands(({({"una pata",2,5}),
        ({"otra pata",2,5})}));
    InitChats(5,({"Una yegua rumia un poco de heno.\n",
        "Una yegua se sacude los pelos.\n",
        "Una yegua patea el suelo.\n",
        SF(relinchar)}));
    InitAChats(10,({SF(resoplar)}));
}
