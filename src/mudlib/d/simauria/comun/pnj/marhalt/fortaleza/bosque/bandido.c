/*=============================================================*
 |             << Fortaleza:Simauria [m] Maler >> 		       |
 *=============================================================*
 |               Creacion............. 03-07-00                |
 *=============================================================*/

#include "./path.h"
inherit NPC;

#include <properties.h>
#include <gremios.h>

create () {
    ::create();
   seteuid(getuid());
    SetStandard("un bandido", "humano",([ GC_ASESINO: 20+random(10) ]),GENERO_MASCULINO);
    SetShort("un bandido humano");
    SetLong("Es un bandido humano. Lleva los ropajes negros típicos de la profesión. "
            "Parece dispuesto a atacarte en cualquier momento.\n");
    SetIds(({"humano","bandido"}));
    SetAggressive(1);
    SetAlign(-150);
    InitChats(3, "El bandido te mira amenazadoramente.\n");
    AddItem(ARMA("daga2"), REFRESH_REMOVE, SF(wieldme));
    AddItem(ARMA("daga2"), REFRESH_REMOVE, SF(wieldme));
}
