/***************************************************************************************
ARCHIVO:   /d/simauria/comun/pnj/simauria/berat/taylor.c
AUTOR:    [Y] Yalin
COMENTARIOS:   empleado de consignas en Berat
***************************************************************************************/

#include "path.h"
#include <properties.h>
#include <moving.h>
#include <messages.h>

inherit NPC;

create()
{
    ::create();
    SetStandard("Taylor","humano",14+random(5),GENERO_MASCULINO);
    SetShort("Taylor, el interventor");
    SetLong("Taylor es el funcionario encargado de atender tus demandas en la "
        "oficina de cajas de seguridad.\nEs un hombre de aspecto serio, con "
        "ese aire típico de aburrimiento de los que realizan un trabajo "
        "monótono.\n");
    Set(P_CANT_LURE,1);
    AddId(({"interventor", "Taylor", "taylor", "funcionario"}));
    SetCitizenship("berat");
    AddQuestion(({"caja","cajas","alquilar","alquiler","precio"}),
        "Taylor te dice: Si quieres saber el funcionamiento del servicio, "
        "será mejor que leas el cartel, estoy muy ocupado.\n");
    AddQuestion(({"objeto","objetos","meter","poner","sacar","permiso","meter ogbjetos","sacar objetos"}),
        "Taylor te dice: Si deseas información sobre el funcionamiento de la "
            "caja, coge uno de esos folletos.\n");
    InitChats(3,
        ({"Taylor murmura: Hum, parece que se ha perdido el rastro de esta caja...\n",
        "Taylor te mira seriamente y te dice: Si no quieres nada, quítate de "
            "enmedio, podría golpearte con las cajas al pasar.\n",
        "Taylor gruñe impaciente: Vaya, este no ha pagado el alquiler..., pues "
            "nada, subastaremos sus objetos para cubrir pérdidas.\n",
        "Taylor bosteza aburrido.\n"}));
}

