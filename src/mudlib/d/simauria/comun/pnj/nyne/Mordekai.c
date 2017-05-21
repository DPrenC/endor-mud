/*
DESCRIPCION    : Mordekai el lider de los Contrabandistas.
FICHERO        : Mordekai.c
CREACION       : [B] 10/10/01
MODIFICACION   : [B] 18/01/02 - Le cambio el nombre
*/

#include "./path.h"
#include <combat.h>
#include <gremios.h>
#include <properties.h>

inherit NPC;

create()
{
    ::create();
    SetStandard("Mordekai","humano",([GC_LUCHADOR: 50]),GENERO_MASCULINO);
    SetShort("Mordekai, el Líder de los Contrabandistas");
    SetLong("Mordekai es el Líder de los Contrabandistas. Es un humano común. Va vestido con "
        "ropas elegantes, ya que normalmente trata con gente importante, y la presencia es un "
        "factor a tener en cuenta en su profesión. Lleva una daga enjoyada en su cinto. Parece "
        "ornamental, pero tal vez sea mejor no comprobarlo. La seguridad de este lugar no te "
        "permitiría vivir para contárselo a nadie.\n");
    SetIds(({"humano","Mordekai"}));
    SetAlign(50);  
    Set(P_CANT_LURE,1);
    SetAggressive(0);
}
