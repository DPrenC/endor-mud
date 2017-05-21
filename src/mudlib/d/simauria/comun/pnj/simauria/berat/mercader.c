/*
DESCRIPCION : Azaron
FICHERO     : /d/simauria/comun/pnj/simauria/berat/mercader.c
MODIFICACION: 4-11-99 [Icaro];10-6-00[Maler] oooo cielos, no hay retornos de
carro, ni na q modificar, toy impresionao.Cachis, sustituyo SetStandar por
SetStandard, casi era perfecto, cagonlaputa
--------------------------------------------------------------------------------
*/
#include "./path.h"
#include <properties.h>
inherit NPC;

create() {
    ::create();
    SetStandard("Azaron","humano",15,GENDER_MALE);
    AddId(({"mercader", "azaron"}));
    SetShort("Azaron el mercader");
    SetLong("Es Azaron el mercader, es un humano avispado pero no parece demasiado "
    "fuerte.\n");
    SetCitizenship("berat");
}
