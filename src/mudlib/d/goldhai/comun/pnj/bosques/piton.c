/****************************************************************************
Fichero: piton.c
Autor: Ratwor
Fecha: 16/08/2007
Descripci�n: Una pit�n real para el cintur�n de Gaena.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <combat.h>
inherit NPC;

create(){
    ::create();

    SetStandard("una pit�n", "serpiente",8, GENDER_MALE);
    SetShort("una Pit�n Real");
    SetLong("La pit�n real es una especie de boa. Su car�cter es especialmente d�cil, y su "
        "apariencia es realmente hermosa.\n Su cuerpo se caracteriza por ofrecer atractivos "
        "patrones de tonos: negro, crema, amarillo y blanco.\n Al nacer miden entre 40 y 50 "
        "cent�metros y en su madurez llegan a alcanzar metro y medio de largo aproximadamente.\n");
    AddId(({"piton", "pit�n", "serpiente", "boa", "reptil"}));
    SetSize(P_SIZE_SMALL);
    SetWeight(20000);
    SetHands(({ ({"colmillos",TD_PENETRACION,5}) }));
    SetDesmembrableEn(({OTRO("piel_piton")}));
    SetGoChance(20);
    AddWalkZones(({BNORTE(""),BOSCURO(""),BWALD("")}));
}
