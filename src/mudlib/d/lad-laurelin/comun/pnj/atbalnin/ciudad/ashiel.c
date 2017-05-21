/***************************************************************************************
ARCHIVO:   /d/simauria/comun/pnj/marhalt/enalel/otro/ashiel.c
AUTOR:    Yalin
COMENTARIOS:   empleado de consignas en Crowy
***************************************************************************************/

#include "path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Ashiel","elfo",4+d6(),GENERO_MASCULINO);
    SetName("Ashiel");
    SetShort("Ashiel, el interventor");
    SetLong("Ashiel es el funcionario encargado de atender tus demandas en la "
        "oficina de cajas de seguridad.\nEs un elfo de cara agradable, aunque con "
        "ese aire típico de aburrimiento de los que realizan un trabajo "
        "monótono.\n");
    AddId(({"interventor","empleado","ashiel","Ashiel","elfo"}));
    AddQuestion(({"caja","cajas","alquilar","alquiler","precio"}),
        "Ashiel te dice: Si quieres saber el funcionamiento del servicio, "
            "será mejor que leas el cartel, estoy muy ocupado.\n");
    AddQuestion(({"objeto","objetos","meter","poner","sacar","permiso","meter ogbjetos","sacar objetos"}),
        "Ashiel te dice: Si deseas información sobre el funcionamiento de la "
            "caja, coge uno de esos folletos.\n");
    InitChats(10,
        ({"Ashiel murmura: Hum, parece que se ha perdido el rastro de esta caja...\n",
        "Ashiel te mira seriamente y te dice: Si no quieres nada, quítate de "
            "enmedio, podría golpearte con las cajas al pasar.\n",
        "Ashiel gruñe impaciente: Vaya, este no ha pagado el alquiler..., pues "
            "nada, subastaremos sus objetos para cubrir pérdidas.\n",
        "Ashiel bosteza aburrido.\n"}));
}

