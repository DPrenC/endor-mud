/*****************************************************************************************
 ARCHIVO:       hada_sirviente.c
 AUTOR:         Ztico
 FECHA:         18-06-2005
 DESCRIPCI�N:   Una hada sirviente.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

public string fun_msgs();

create()
{
    if(::create()) return 1;

    SetStandard("hada sirviente", "duende", ([GC_CONJURADOR: 30]), GENERO_FEMENINO);
    AddId(({"hada", "sirviente"}));
    SetShort("un hada sirviente");
    SetLong("Esta hada es muy peque�a, aunque parece vivaz y emprendedora. Seguramente "
        "se trata de uno de los sirvientes de su majestad, reina de toda la fantas�a y "
        "se�ora del bosque.\n");

    //cambiar el sonr�e astutamente si la reina est� muerta
    InitChats(4,
          ({SF(fun_msgs),
          	"Un hada sirviente te mira de reojo...\n"
            }));
}

public string fun_msgs()
{
    object reina;

    //Si la reina est� en la habitaci�n...
    if ((reina = present("reina_faeria")) && living(reina))
    {
        return "Un hada sirviente te sonrie astutamente.\n";
    }
    return "Un hada sirviente te mira con miedo.\n";
}
