/***************************************************************************************
ARCHIVO:   /d/kha-annu/comun/pnj/ruffus.c
AUTOR:    Yalin
COMENTARIOS:   empleado de consignas en Kha-annu
***************************************************************************************/

#include "path.h"
#include <properties.h>
inherit KBASE;

create()
{
    ::create();
    SetStandard("Ruffus","enano",4+d6(),GENERO_MASCULINO);
    SetName("Ruffus");
    SetShort("Ruffus, el interventor");
    SetLong("Ruffus es el funcionario encargado de atender tus demandas en la "
        "oficina de cajas de seguridad.\nEs un enano de aspecto arisco, con "
        "ese aire típico de aburrimiento de los que realizan un trabajo "
        "monótono.\n");
    AddId(({"interventor","empleado","ruffus","Ruffus","enano"}));
    AddQuestion(({"caja","cajas","alquilar","alquiler","precio"}),
        "Ruffus te dice: Si quieres saber el funcionamiento del servicio, "
        "será mejor que leas el cartel, estoy muy ocupado.\n");
    AddQuestion(({"objeto","objetos","meter","poner","sacar","permiso","meter ogbjetos","sacar objetos"}),
        "Ruffus te dice: Si deseas información sobre el funcionamiento de la "
            "caja, coge uno de esos folletos.\n");
    InitChats(10,
        ({"Ruffus murmura: Hum, parece que se ha perdido el rastro de esta caja...\n",
        "Ruffus te mira seriamente y te dice: Si no quieres nada, quítate de "
            "enmedio, podría golpearte con las cajas al pasar.\n",
        "Ruffus gruñe impaciente: Vaya, este no ha pagado el alquiler..., pues "
            "nada, subastaremos sus objetos para cubrir pérdidas.\n",
        "Ruffus bosteza aburrido.\n"}));
}

