/***************************************************************************************
ARCHIVO:   /d/kha-annu/comun/pnj/feinaa.c
AUTOR:    [T] Tagoras
COMENTARIOS:   empleado de consignas en Annufam
***************************************************************************************/

#include "path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Feinan", "enano", 10, GENERO_MASCULINO);
    SetName("Feinan");
    SetShort("Feinan, el interventor");
    SetLong("Feinan es el funcionario encargado de atender tus demandas en la "
        "oficina de cajas de seguridad.\nEs un hombre de aspecto serio, con "
        "ese aire típico de aburrimiento de los que realizan un trabajo "
        "monótono.\n");
    AddId(({"interventor", "empleado", "funcionario", "Feinan"}));
    Set(P_CANT_LURE, 1);
    AddQuestion(({"caja","cajas","alquilar","alquiler","precio"}),
        "Feinan te dice: Si quieres saber el funcionamiento del servicio, "
        "será mejor que leas el cartel, estoy muy ocupado.\n");
    AddQuestion(({"objeto","objetos","meter","poner","sacar","permiso","meter objetos","sacar objetos"}),
        "Feinan te dice: Si deseas información sobre el funcionamiento de la "
            "caja, coge uno de esos folletos.\n");
    InitChats(10,
        ({"Feinan murmura: Hum, parece que se ha perdido el rastro de esta caja...\n",
        "Feinan te mira seriamente y te dice: Si no quieres nada, quítate de "
            "enmedio, podría golpearte con las cajas al pasar.\n",
        "Feinan gruñe impaciente: Vaya, este no ha pagado el alquiler..., pues "
            "nada, subastaremos sus objetos para cubrir pérdidas.\n",
        "Feinan bosteza aburrido.\n"}));
}
