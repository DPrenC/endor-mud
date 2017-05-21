/*****************************************************************************************
 ARCHIVO:       duende_nixi.c
 AUTOR:         Ztico
 FECHA:         18-06-2005
 DESCRIPCIÓN:   Un nixi.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>


inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("un nixi", "nixi", ([GC_GUARDABOSQUE: 25]), GENERO_MASCULINO);
    AddId("duende");
    SetShort("un pequeño nixi");
    InitChats(3,
          ({".\n"}));
}
