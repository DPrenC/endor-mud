/****************************************************************************
Fichero: /d/akallab/comun/pnj/z_ciudad/sebte.c
Autor: Yalin
Fecha: 26/03/2008 00:10
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
    SetStandard("Sebte","orco",15,GENERO_MASCULINO);
    SetName("Sebte");
    SetShort("Sebte, el zapatero");
    SetLong("Sebte es un orco de mediana edad. Una grave herida de guerra casi le destrozó la "
        "pierna derecha, pero consiguió sobrevivir. La cojera que le quedó le impidió seguir "
        "en el ejército y fue entonces cuando aprendió el oficio de la zapatería para poder "
        "ganarse la vida. Lleva ya algunos años asentado en esta ciudad.\n");
    AddId(({"sebte","Sebte","zapatero","orco"}));
}
