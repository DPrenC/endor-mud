/***************************************************************************************
ARCHIVO:   /guilds/kisalas/pnj/geneibr.c
AUTOR:    [Y] Yalin
COMENTARIOS:   empleada de consignas en el gremio de Kisalas
***************************************************************************************/

#include "path.h"
#include <properties.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Geneibr","elfo",4+random(5),GENERO_FEMENINO);
    SetName("Geneibr");
    SetShort("Geneibr, la interventora");
    SetLong("Geneibr es una kisala encargada de atender tus demandas en la "
        "oficina de cajas de seguridad.\nEs una elfa de aspecto serio, con "
        "ese aire t�pico de aburrimiento de los que realizan un trabajo "
        "mon�tono.\n");
    AddId(({"interventora","empleada","ginebra","Geneibr","elfa"}));
    AddQuestion(({"caja","cajas","alquilar","alquiler","precio"}),
        "Geneibr te dice: Si quieres saber el funcionamiento del servicio, "
        "ser� mejor que leas el cartel, estoy muy ocupada.\n");
    AddQuestion(({"objeto","objetos","meter","poner","sacar","permiso","meter ogbjetos","sacar objetos"}),
        "Geneibr te dice: Si deseas informaci�n sobre el funcionamiento de la "
            "caja, coge uno de esos folletos.\n");
    InitChats(10,
        ({"Geneibr murmura: Hum, parece que se ha perdido el rastro de esta caja...\n",
        "Geneibr te mira seriamente y te dice: Si no quieres nada, qu�tate de "
            "enmedio, podr�a golpearte con las cajas al pasar.\n",
        "Geneibr gru�e impaciente: Vaya, este no ha pagado el alquiler..., pues "
            "nada, subastaremos sus objetos para cubrir p�rdidas.\n",
        "Geneibr bosteza aburrida.\n"}));
}

