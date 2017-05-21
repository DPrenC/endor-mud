/****************************************************************************
Fichero: /d/akallab/comun/pnj/z_ciudad/sebte.c
Autor: Yalin
Fecha: 26/03/2008 00:10
Descripci�n: Panadero de Zarkam.
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
    SetLong("Sebte es un orco de mediana edad. Una grave herida de guerra casi le destroz� la "
        "pierna derecha, pero consigui� sobrevivir. La cojera que le qued� le impidi� seguir "
        "en el ej�rcito y fue entonces cuando aprendi� el oficio de la zapater�a para poder "
        "ganarse la vida. Lleva ya algunos a�os asentado en esta ciudad.\n");
    AddId(({"sebte","Sebte","zapatero","orco"}));
}
