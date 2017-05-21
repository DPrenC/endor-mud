/* Fichero: /d/akallab/comun/pnj/akallab/gaddaro/grumm.c
Autor: Yalin
Fecha: 24/10/2007 17:36:13
Descripción: Tendero de Gaddaro.
*/
#include "path.h"
#include <properties.h>
#include <moving.h>
#include <messages.h>
inherit NPC;

create()
{
    ::create();
    SetStandard("Grumm","orco",10,GENERO_MASCULINO);
    SetName("Grumm");
    SetShort("Grumm, el tendero");
    SetLong("Grumm es un viejo orco. Posee una pequeña tienda en el pueblo de Gaddaro en la "
        "que se gana la vida comerciando con productos de uso general. En su cuerpo puedes "
        "apreciar algunas cicatrices, huellas de un pasado mas violento.\n");
    AddId(({"Grumm","grumm","tendero","orco"}));
    Set(P_CANT_LURE,1);
}
