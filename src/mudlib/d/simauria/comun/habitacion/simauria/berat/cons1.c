/****************************************************************************
Fichero: cons1.c
Autor: Ratwor
Fecha: 15/11/2007
Descripción: Una casa en construcción para Malmabet.
****************************************************************************/

#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();
    SetIntShort("una casa en construcción");
    SetIntLong("Estás en una casa en construcción y parece que todavía está poco "
    "avanzada, no se puede deducir como quedará cuando se termine la obra.\n Multitud de "
    "escombros y maderas se amontonan por doquier. Destaca un cartel en un rincón.\n");
    AddDetail(({"escombros", "maderas"}), "Está todo lleno de escombros y maderas "
    "de la propia obra.\n");
    AddDetail(({"cartel","letrero"}), "Está ahí en un rincón sin importancia.\n");
    AddReadMsg(({"cartel", "letrero"}), "Hogar de Malmabeth.\n");
    AddItem(QUEST "cuchillo/caja", REFRESH_DESTRUCT,1);
    AddItem(QUEST "cuchillo/currito", REFRESH_DESTRUCT,1);
    SetIntBright(45);
    AddExit("este","./ckol3");
}
