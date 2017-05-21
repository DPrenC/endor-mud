/*=============================================================*
 |             << Fortaleza:Simauria [m] Maler >> 		       |
 *=============================================================*
 |               Creacion............. 02-05-00                |
 *=============================================================*/

#include "./path.h"

inherit NPC;

#include <properties.h>

create () {
    ::create();
    SetStandard("un gusano patético","gusano",1,GENERO_MASCULINO);
    SetShort("un patético gusano");
    SetLong("Es un gusano verde y peludo, da autentico asco verlo. Al observarle el "
    "gusano empieza a reptar tan rapidamente como su baboso cuerpo le permite.\n");
    SetIds(({"gusano","gusano patetico","gusano patético"}));
    SetHands(({({"su baboso cuerpo",0,1})}));
    SetInt(1);
    SetMaxHP(5);
    SetHP(QueryMaxHP());
    SetSize(P_SIZE_SMALL);
    InitChats(3,"El gusano parece estar diciéndote PISAME\n");
}
