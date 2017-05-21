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
        "ese aire t�pico de aburrimiento de los que realizan un trabajo "
        "mon�tono.\n");
    AddId(({"interventor","empleado","ruffus","Ruffus","enano"}));
    AddQuestion(({"caja","cajas","alquilar","alquiler","precio"}),
        "Ruffus te dice: Si quieres saber el funcionamiento del servicio, "
        "ser� mejor que leas el cartel, estoy muy ocupado.\n");
    AddQuestion(({"objeto","objetos","meter","poner","sacar","permiso","meter ogbjetos","sacar objetos"}),
        "Ruffus te dice: Si deseas informaci�n sobre el funcionamiento de la "
            "caja, coge uno de esos folletos.\n");
    InitChats(10,
        ({"Ruffus murmura: Hum, parece que se ha perdido el rastro de esta caja...\n",
        "Ruffus te mira seriamente y te dice: Si no quieres nada, qu�tate de "
            "enmedio, podr�a golpearte con las cajas al pasar.\n",
        "Ruffus gru�e impaciente: Vaya, este no ha pagado el alquiler..., pues "
            "nada, subastaremos sus objetos para cubrir p�rdidas.\n",
        "Ruffus bosteza aburrido.\n"}));
}

