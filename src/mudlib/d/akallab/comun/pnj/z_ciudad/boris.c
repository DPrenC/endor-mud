/****************************************************************************
Fichero: /d/akallab/comun/pnj/z_ciudad/boris.c
Autor: Yalin
Fecha: 19/11/2007 21:56
Descripción: Panadero de Zarkam.
****************************************************************************/
#include "path.h"
#include <properties.h>
#include <moving.h>
#include <messages.h>
inherit NPC;
    
create()
{
    ::create();
    SetStandard("Boris","orco",20,GENERO_MASCULINO);
    SetName("Boris");
    SetShort("Boris, el panadero");
    SetLong("Boris es el propietario de esta panadería. Es un viejo orco de movimientos "
        "pausados y carácter seco. Las cicatrices de su cuerpo recuerdan su ya lejana juventud "
        "como guerrero al servicio del emperador.\n");
    AddId(({"Boris","boris","panadero","tendero"}));
}
