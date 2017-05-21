/****************************************************************************
Fichero: piton.c
Autor: Ratwor
Fecha: 16/08/2007
Descripción: Una pitón real para el cinturón de Gaena.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>
inherit NPC;

create(){
    ::create();

    SetStandard("una pitón", "serpiente",8, GENDER_MALE);
    SetShort("una Pitón Real");
    SetLong("La pitón real es una especie de boa. Su carácter es especialmente dócil, y su "
        "apariencia es realmente hermosa.\n Su cuerpo se caracteriza por ofrecer atractivos "
        "patrones de tonos: negro, crema, amarillo y blanco.\n Al nacer miden entre 40 y 50 "
        "centímetros y en su madurez llegan a alcanzar metro y medio de largo aproximadamente.\n");
    AddId(({"piton", "pitón", "serpiente", "boa", "reptil"}));
    SetSize(P_SIZE_SMALL);
    SetWeight(20000);
    SetHands(({ ({"colmillos",TD_PENETRACION,5}) }));
    SetDesmembrableEn(({OTRO("piel_piton")}));
    SetGoChance(20);
    AddWalkZones(({BNORTE(""),BOSCURO(""),BWALD("")}));
}
