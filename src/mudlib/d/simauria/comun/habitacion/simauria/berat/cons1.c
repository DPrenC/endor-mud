/****************************************************************************
Fichero: cons1.c
Autor: Ratwor
Fecha: 15/11/2007
Descripci�n: Una casa en construcci�n para Malmabet.
****************************************************************************/

#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();
    SetIntShort("una casa en construcci�n");
    SetIntLong("Est�s en una casa en construcci�n y parece que todav�a est� poco "
    "avanzada, no se puede deducir como quedar� cuando se termine la obra.\n Multitud de "
    "escombros y maderas se amontonan por doquier. Destaca un cartel en un rinc�n.\n");
    AddDetail(({"escombros", "maderas"}), "Est� todo lleno de escombros y maderas "
    "de la propia obra.\n");
    AddDetail(({"cartel","letrero"}), "Est� ah� en un rinc�n sin importancia.\n");
    AddReadMsg(({"cartel", "letrero"}), "Hogar de Malmabeth.\n");
    AddItem(QUEST "cuchillo/caja", REFRESH_DESTRUCT,1);
    AddItem(QUEST "cuchillo/currito", REFRESH_DESTRUCT,1);
    SetIntBright(45);
    AddExit("este","./ckol3");
}
