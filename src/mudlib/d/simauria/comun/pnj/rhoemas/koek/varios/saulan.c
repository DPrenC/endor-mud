/***************************************************************************************
ARCHIVO:   /d/simauria/comun/pnj/rhoemas/koek/varios/saulan.c
AUTOR:    [Y] Yalin
COMENTARIOS:   empleado de consignas en Koek
***************************************************************************************/

#include "path.h"
#include <properties.h>
inherit NPC;
#include RHOEDANYO

create()
{
    ::create();
    SetStandard("Saulan","humano",4+d6(),GENERO_MASCULINO);
    SetName("saulan");
    SetShort("Saulan, el interventor");
    SetLong("Saulan es el funcionario encargado de atender tus demandas en la "
        "oficina de cajas de seguridad.\nEs un hombre de aspecto serio, con "
        "ese aire típico de aburrimiento de los que realizan un trabajo "
        "monótono.\n");
    AddId(({"saulan","Saulan","interventor","empleado","humano"}));
    Set(P_CANT_LURE,1);
    AddQuestion(({"caja","cajas","alquilar","alquiler","precio"}),
        "Saulan te dice: Si quieres saber el funcionamiento del servicio, "
        "será mejor que leas el cartel, estoy muy ocupado.\n");
    AddQuestion(({"objeto","objetos","meter","poner","sacar","permiso","meter ogbjetos","sacar objetos"}),
        "Saulan te dice: Si deseas información sobre el funcionamiento de la "
            "caja, coge uno de esos folletos.\n");
    InitChats(10,
        ({"Saulan murmura: Hum, parece que se ha perdido el rastro de esta caja...\n",
        "Saulan te mira seriamente y te dice: Si no quieres nada, quítate de "
            "enmedio, podría golpearte con las cajas al pasar.\n",
        "Saulan gruñe impaciente: Vaya, este no ha pagado el alquiler..., pues "
            "nada, subastaremos sus objetos para cubrir pérdidas.\n",
        "Saulan bosteza aburrido.\n"}));
}

