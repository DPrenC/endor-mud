/***************************************************************************************
ARCHIVO:   /d/simauria/comun/pnj/fenrim.c
AUTOR:    [Y] Yalin
COMENTARIOS:   empleado de consignas en Gorat
***************************************************************************************/

#include "./path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Fenrim","humano",15+d6(),GENERO_MASCULINO);
    SetName("Fenrim");
    SetShort("Fenrim, el interventor");
    SetLong("Fenrim es el funcionario encargado de atender tus demandas en la "
        "oficina de cajas de seguridad.\nEs un hombre de aspecto serio, con "
        "ese aire típico de aburrimiento de los que realizan un trabajo "
        "monótono.\n");
    AddId(({"interventor","empleado","fenrim","Fenrim","humano"}));
    Set(P_CANT_LURE,1);
    SetCitizenship("gorat");
    AddQuestion(({"caja","cajas","alquilar","alquiler","precio"}),
        "Fenrim te dice: Si quieres saber el funcionamiento del servicio, "
        "será mejor que leas el cartel, estoy muy ocupado.\n");
    AddQuestion(({"objeto","objetos","meter","poner","sacar","permiso","meter objetos","sacar objetos"}),
        "Fenrim te dice: Si deseas información sobre el funcionamiento de la "
            "caja, coge uno de esos folletos.\n");
    InitChats(10,
        ({"Fenrim murmura: Hum, parece que se ha perdido el rastro de esta caja...\n",
        "Fenrim te mira seriamente y te dice: Si no quieres nada, quítate de "
            "enmedio, podría golpearte con las cajas al pasar.\n",
        "Fenrim gruñe impaciente: Vaya, este no ha pagado el alquiler..., pues "
            "nada, subastaremos sus objetos para cubrir pérdidas.\n",
        "Fenrim bosteza aburrido.\n"}));
}

