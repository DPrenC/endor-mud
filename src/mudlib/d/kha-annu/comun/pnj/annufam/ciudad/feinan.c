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
        "ese aire t�pico de aburrimiento de los que realizan un trabajo "
        "mon�tono.\n");
    AddId(({"interventor", "empleado", "funcionario", "Feinan"}));
    Set(P_CANT_LURE, 1);
    AddQuestion(({"caja","cajas","alquilar","alquiler","precio"}),
        "Feinan te dice: Si quieres saber el funcionamiento del servicio, "
        "ser� mejor que leas el cartel, estoy muy ocupado.\n");
    AddQuestion(({"objeto","objetos","meter","poner","sacar","permiso","meter objetos","sacar objetos"}),
        "Feinan te dice: Si deseas informaci�n sobre el funcionamiento de la "
            "caja, coge uno de esos folletos.\n");
    InitChats(10,
        ({"Feinan murmura: Hum, parece que se ha perdido el rastro de esta caja...\n",
        "Feinan te mira seriamente y te dice: Si no quieres nada, qu�tate de "
            "enmedio, podr�a golpearte con las cajas al pasar.\n",
        "Feinan gru�e impaciente: Vaya, este no ha pagado el alquiler..., pues "
            "nada, subastaremos sus objetos para cubrir p�rdidas.\n",
        "Feinan bosteza aburrido.\n"}));
}
