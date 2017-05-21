/*****************************************************************************************
 ARCHIVO:       tritón.c
 AUTOR:         Ztico
 FECHA:         20-01-2006
 DESCRIPCIÓN:   Un tritón
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("un tritón", "triton", ([GC_LUCHADOR: 60]), GENERO_MASCULINO);
    AddId("tritón");
    SetShort("un tritón");
    SetLong("Es un tritón. Tiene la piel azul-plateada en degradado hacia la mitad "
        "inferior de su cuerpo, la cual está escamada. Su pelo es de un azul profundo y "
        "los dedos de los pies están palmeados, convirtiéndose en pequeñas aletas.\n");
    SetAggressive(2);
}
