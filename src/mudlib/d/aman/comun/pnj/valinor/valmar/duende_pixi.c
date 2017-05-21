/*****************************************************************************************
 ARCHIVO:       duende_pixi.c
 AUTOR:         Ztico
 FECHA:         18-06-2005
 DESCRIPCIÓN:   Un pixi.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>


inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("un pixi", "pixi", ([GC_GUARDABOSQUE: 25]), GENERO_MASCULINO);
    AddId("duende");
    SetShort("un pixi");
    InitChats(3,
          ({"Un pequeño pixi juguetea con algo que tiene entre las manos.\n"}));
}
