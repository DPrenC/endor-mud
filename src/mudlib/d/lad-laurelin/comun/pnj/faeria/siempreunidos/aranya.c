/***
Fichero: ara�a.c
Autor: kastwey@simauria
Descripci�n: Ara�a para las celdas.
Sacado de la ara�a de la mina de novatos del parque... las pocas ganas
que me quedan de codear ;P
Gracias woo y angor por ahorrarme el trabajo :)
***/

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <gremios.h>


inherit NPC;

create() {
    ::create();
    SetStandard("una ara�a grande", "aranya", ([ GC_TORPE: 2]), GENDER_FEMALE);
    SetShort("una ara�a grande");
    SetLong(
    "Es una ara�a peluda de color negro con estrias marron en el abdomen. Sus\n"
    "m�ltiples ojos son de un color rojo brillante.\n");
    SetIds(({"aranya", "bicho", "ara�a"}));
    SetAds(({"una", "asquerosa", "gran"}));
    SetSize(P_SIZE_SMALL);
    SetMaxHP(10+(QueryLevel()-1)*5);
    SetHP(QueryMaxHP());
    SetHands( ({ ({"mordisco", TD_PENETRACION, 3}) }) );
    SetNoGet(0);
    SetWeight(500);
}
