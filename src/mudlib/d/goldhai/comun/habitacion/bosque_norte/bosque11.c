/*=============================================================*
 |            << GOLDHAI.Bosque [w] Woo@simauria >>            |
 *=============================================================*
 |               Creacion.............. 08-02-99               |
 |               Ultima Modificacion... 08-02-99               |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit GBOSQUE;

create()
{
    ::create();
    AddExit("este",BNORTE("bosque10"));
    AddExit("oeste",ACANTILADO("acantilado_norte5"));
    AddPnj();
    SetLocate("bosque norte de Goldhai");
}
