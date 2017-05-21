/***************************************************************************************
ARCHIVO:   /d/simauria/comun/pnj/dimas.c
AUTOR:    [Y] Yalin
COMENTARIOS:   empleado de consignas en Nandor
***************************************************************************************/

#include "path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Dimas","humano",4+d6(),GENERO_MASCULINO);
    SetName("Dimas");
    SetShort("Dimas, el interventor");
    SetLong("Dimas es el funcionario encargado de atender tus demandas en la "
        "oficina de cajas de seguridad.\nEs un hombre de aspecto serio, con "
        "ese aire t�pico de aburrimiento de los que realizan un trabajo "
        "mon�tono.\n");
    AddId(({"interventor","empleado","dimas","Dimas","humano"}));
    Set(P_CANT_LURE,1);
    AddQuestion(({"caja","cajas","alquilar","alquiler","precio"}),
        "Dimas te dice: Si quieres saber el funcionamiento del servicio, "
        "ser� mejor que leas el cartel, estoy muy ocupado.\n");
    AddQuestion(({"objeto","objetos","meter","poner","sacar","permiso","meter objetos","sacar objetos"}),
        "Dimas te dice: Si deseas informaci�n sobre el funcionamiento de la "
            "caja, coge uno de esos folletos.\n");
    InitChats(10,
        ({"Dimas murmura: Hum, parece que se ha perdido el rastro de esta caja...\n",
        "Dimas te mira seriamente y te dice: Si no quieres nada, qu�tate de "
            "enmedio, podr�a golpearte con las cajas al pasar.\n",
        "Dimas gru�e impaciente: Vaya, este no ha pagado el alquiler..., pues "
            "nada, subastaremos sus objetos para cubrir p�rdidas.\n",
        "Dimas bosteza aburrido.\n"}));
}

