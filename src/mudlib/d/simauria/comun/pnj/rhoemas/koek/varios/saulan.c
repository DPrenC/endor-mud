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
        "ese aire t�pico de aburrimiento de los que realizan un trabajo "
        "mon�tono.\n");
    AddId(({"saulan","Saulan","interventor","empleado","humano"}));
    Set(P_CANT_LURE,1);
    AddQuestion(({"caja","cajas","alquilar","alquiler","precio"}),
        "Saulan te dice: Si quieres saber el funcionamiento del servicio, "
        "ser� mejor que leas el cartel, estoy muy ocupado.\n");
    AddQuestion(({"objeto","objetos","meter","poner","sacar","permiso","meter ogbjetos","sacar objetos"}),
        "Saulan te dice: Si deseas informaci�n sobre el funcionamiento de la "
            "caja, coge uno de esos folletos.\n");
    InitChats(10,
        ({"Saulan murmura: Hum, parece que se ha perdido el rastro de esta caja...\n",
        "Saulan te mira seriamente y te dice: Si no quieres nada, qu�tate de "
            "enmedio, podr�a golpearte con las cajas al pasar.\n",
        "Saulan gru�e impaciente: Vaya, este no ha pagado el alquiler..., pues "
            "nada, subastaremos sus objetos para cubrir p�rdidas.\n",
        "Saulan bosteza aburrido.\n"}));
}

