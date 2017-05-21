/*****************************************************************************************
 ARCHIVO:       trit�n.c
 AUTOR:         Ztico
 FECHA:         20-01-2006
 DESCRIPCI�N:   Un trit�n
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("un trit�n", "triton", ([GC_LUCHADOR: 60]), GENERO_MASCULINO);
    AddId("trit�n");
    SetShort("un trit�n");
    SetLong("Es un trit�n. Tiene la piel azul-plateada en degradado hacia la mitad "
        "inferior de su cuerpo, la cual est� escamada. Su pelo es de un azul profundo y "
        "los dedos de los pies est�n palmeados, convirti�ndose en peque�as aletas.\n");
    SetAggressive(2);
}
