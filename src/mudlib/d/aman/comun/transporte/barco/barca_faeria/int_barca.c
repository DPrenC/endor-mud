/*****************************************************************************************
 ARCHIVO:       int_barca.c
 AUTOR:         Ztico
 FECHA:         06-05-2005
 DESCRIPCIÓN:   Barca que une el bosque de Faeria con la isla de los Druidas en el lago
                Glinnael.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit ROOM;

create()
{
    if(::create()) return 1;

    SetIntShort("la nube flotante");
    SetIntLong("Te encuentras en el interior de la barca. Está fabricada con ramas "
        "trenzadas y forrada en la parte exterior con piel de toro curtida. Una capa "
        "de grasa recubre el cuero.\n");
    SetIndoors(0);
    AddItem(PNJ_VALMAR("barquero.c"));
}
