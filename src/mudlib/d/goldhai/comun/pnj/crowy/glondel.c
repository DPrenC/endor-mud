/***************************************************************************************
ARCHIVO:   /d/goldhai/comun/pnj/crowy/glondel.c
AUTOR:    Yalin
COMENTARIOS:   empleado de consignas en Crowy
***************************************************************************************/

#include "path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Glondel","elfo",4+d6(),GENERO_MASCULINO);
    SetName("Glondel");
    SetShort("Glondel, el interventor");
    SetLong("Glondel es el funcionario encargado de atender tus demandas en la "
        "oficina de cajas de seguridad.\nEs un elfo de cara agradable, aunque con "
        "ese aire t�pico de aburrimiento de los que realizan un trabajo "
        "mon�tono.\n");
    AddId(({"interventor","empleado","glondel","Glondel","elfo"}));
    AddQuestion(({"caja","cajas","alquilar","alquiler","precio"}),
        "Glondel te dice: Si quieres saber el funcionamiento del servicio, "
            "ser� mejor que leas el cartel, estoy muy ocupado.\n");
    AddQuestion(({"objeto","objetos","meter","poner","sacar","permiso","meter ogbjetos","sacar objetos"}),
        "Glondel te dice: Si deseas informaci�n sobre el funcionamiento de la "
            "caja, coge uno de esos folletos.\n");
    InitChats(10,
        ({"Glondel murmura: Hum, parece que se ha perdido el rastro de esta caja...\n",
        "Glondel te mira seriamente y te dice: Si no quieres nada, qu�tate de "
            "enmedio, podr�a golpearte con las cajas al pasar.\n",
        "Glondel gru�e impaciente: Vaya, este no ha pagado el alquiler..., pues "
            "nada, subastaremos sus objetos para cubrir p�rdidas.\n",
        "Glondel bosteza aburrido.\n"}));
}

