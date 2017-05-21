/*****************************************************************************************
 ARCHIVO:       luciernaga.c
 AUTOR:         Ztico
 FECHA:         18-06-2005
 DESCRIPCIÓN:   Una luciernaga...
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("una luciérnaga", "luciernaga", ([GC_TORPE: 2]), GENERO_FEMENINO);
    AddId(({"luciérnaga", "pequeña luciernaga", "pequenya luciérnaga"}));
    SetShort("una pequeña luciérnaga");
    SetLong("Una pequeña luciérnaga, vive entre las nieblas, ocultándose de las miradas "
        "de los que quieran dañarla...\n");
    InitChats(4,
          ({"La luciérnaga se mueve de una lado para otro sin cesar.\n",
            "De vez en cuando la luciérnaga se posa para volver a tomar el vuelo un "
            "instante después.\n"}));
}
