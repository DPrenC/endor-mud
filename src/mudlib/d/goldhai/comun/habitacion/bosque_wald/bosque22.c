/*=============================================================*
 |          << GOLDHAI.Bosque Wald [w] Woo@simauria >>         |
 *=============================================================*
 |             Creacion................... 27-08-98            |
 |             Ultima Modificacion........ 20-02-99            |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
    ::create();
    SetIntShort("el bosque Wald");
    AddExit("sur",BWALD("bosque21"));
    AddExit("este",BWALD("bosque25"));
    AddExit("oeste",BWALD("bosque23"));
    AddItem(PNJ("bosque_wald/ent"),REFRESH_DESTRUCT,d6());
    AddItem(OTRO("arbol_legendario"),REFRESH_DESTRUCT);
    SetLocate("bosque Wald");
}
