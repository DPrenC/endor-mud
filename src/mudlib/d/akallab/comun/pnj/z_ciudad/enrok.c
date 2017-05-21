/***************************************************************************************
ARCHIVO:   /d/akallab/comun/pnj/enrok.c
AUTOR:    [Y] Yalin
COMENTARIOS:   taquillero de consignas en Zarkam
 ***************************************************************************************/

#include "path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Enrok","orco",4+d6(),GENERO_MASCULINO);
    SetName("Enrok");
    SetShort("Enrok, el interventor");
    SetLong("Enrok es el funcionario encargado de atender tus demandas en la "
        "oficina de cajas de seguridad.\nEs un orco malhumorado, con "
        "ese aire típico de aburrimiento de los que realizan un trabajo "
        "monótono.\n");
    AddId(({"interventor","empleado","enrok","Enrok","orco"}));
    AddQuestion(({"caja","cajas","alquilar","alquiler","precio"}),
        "Enrok te dice: Si quieres saber el funcionamiento del servicio, "
        "será mejor que leas el cartel, estoy muy ocupado.\n");
    AddQuestion(({"objeto","objetos","meter","poner","sacar","permiso","meter objetos","sacar objetos"}),
        "Enrok te dice: Si deseas información sobre el funcionamiento de la "
            "caja, coge uno de esos folletos.\n");
    InitChats(10,
        ({"Enrok murmura: Hum, parece que se ha perdido el rastro de esta caja...\n",
        "Enrok te mira seriamente y te dice: Si no quieres nada, quítate de "
            "enmedio, podría golpearte con las cajas al pasar.\n",
        "Enrok gruñe impaciente: Vaya, este no ha pagado el alquiler..., pues "
            "nada, subastaremos sus objetos para cubrir pérdidas.\n",
        "Enrok bosteza aburrido.\n"}));
}

