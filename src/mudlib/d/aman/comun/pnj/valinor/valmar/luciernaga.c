/*****************************************************************************************
 ARCHIVO:       luciernaga.c
 AUTOR:         Ztico
 FECHA:         18-06-2005
 DESCRIPCI�N:   Una luciernaga...
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>

inherit NPC;

create()
{
    if(::create()) return 1;

    SetStandard("una luci�rnaga", "luciernaga", ([GC_TORPE: 2]), GENERO_FEMENINO);
    AddId(({"luci�rnaga", "peque�a luciernaga", "pequenya luci�rnaga"}));
    SetShort("una peque�a luci�rnaga");
    SetLong("Una peque�a luci�rnaga, vive entre las nieblas, ocult�ndose de las miradas "
        "de los que quieran da�arla...\n");
    InitChats(4,
          ({"La luci�rnaga se mueve de una lado para otro sin cesar.\n",
            "De vez en cuando la luci�rnaga se posa para volver a tomar el vuelo un "
            "instante despu�s.\n"}));
}
