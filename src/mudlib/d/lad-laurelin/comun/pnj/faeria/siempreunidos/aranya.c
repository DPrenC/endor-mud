/***
Fichero: araña.c
Autor: kastwey@simauria
Descripción: Araña para las celdas.
Sacado de la araña de la mina de novatos del parque... las pocas ganas
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
    SetStandard("una araña grande", "aranya", ([ GC_TORPE: 2]), GENDER_FEMALE);
    SetShort("una araña grande");
    SetLong(
    "Es una araña peluda de color negro con estrias marron en el abdomen. Sus\n"
    "múltiples ojos son de un color rojo brillante.\n");
    SetIds(({"aranya", "bicho", "araña"}));
    SetAds(({"una", "asquerosa", "gran"}));
    SetSize(P_SIZE_SMALL);
    SetMaxHP(10+(QueryLevel()-1)*5);
    SetHP(QueryMaxHP());
    SetHands( ({ ({"mordisco", TD_PENETRACION, 3}) }) );
    SetNoGet(0);
    SetWeight(500);
}
