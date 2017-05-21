/****************************************************************************
fichero: workroom.c
Autor: Kastwey
Descripción: Mi workroom
****************************************************************************/

#include "path.h"
inherit ROOM;

create() {
    ::create();
    SetIntShort("la habitación de Kastwey");
    SetIntLong("Esta es la habitación de Kastwey. Antes era más grande, pero "
            "parece ser que se ha puesto a hacer reformas y ha borrado muchas cosas.\n");

    SetIntBright(45);
    SetIndoors(1);

    AddExit("torre", TORRE("piso4/center"));
    AddExit("sur",   TORRE("rooms/kastwey/tasca"));
    AddExit("oeste", TORRE("rooms/kastwey/transporte"));
    AddExit("norte",(:write("La casa de Kastwey está cerrada por ser su código insalubre.\n"),1:));
}
