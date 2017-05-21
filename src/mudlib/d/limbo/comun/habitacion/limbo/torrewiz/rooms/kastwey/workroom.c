/****************************************************************************
fichero: workroom.c
Autor: Kastwey
Descripci�n: Mi workroom
****************************************************************************/

#include "path.h"
inherit ROOM;

create() {
    ::create();
    SetIntShort("la habitaci�n de Kastwey");
    SetIntLong("Esta es la habitaci�n de Kastwey. Antes era m�s grande, pero "
            "parece ser que se ha puesto a hacer reformas y ha borrado muchas cosas.\n");

    SetIntBright(45);
    SetIndoors(1);

    AddExit("torre", TORRE("piso4/center"));
    AddExit("sur",   TORRE("rooms/kastwey/tasca"));
    AddExit("oeste", TORRE("rooms/kastwey/transporte"));
    AddExit("norte",(:write("La casa de Kastwey est� cerrada por ser su c�digo insalubre.\n"),1:));
}
