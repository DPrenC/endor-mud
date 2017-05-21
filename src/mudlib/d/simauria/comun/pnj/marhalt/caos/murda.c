/****************************************************************************
Fichero: murda.c
Autor: Ratwor
Fecha: 15/08/2007
Descripción: uno de los secuaces de Girlak.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>
inherit CAOSPNJ"ogro_base";

create(){
    ::create();
    SetStandard("Murda","ogro",([ GC_LUCHADOR:61+random(5)]),GENERO_MASCULINO);

    SetShort("murda, secuaz de Girlak");
    SetLong("  ES uno de los ogros mercenarios de Girlak.  Muestra una postura "
    "desafiante exhibiendo con orgullo su maza mellada, señal inequívoca de lo "
    "cruento de las batallas en las que ha participado. \n Su altura, peso y "
    "poderosa musculatura van acompañadas de un intelecto que, pese a no ser muy "
    "grande, bbasta para hacerlo un adversario a tener en cuenta.\n");
    AddId(({"murda","Murda", "ogro de las cavernas", "secuaz"}));
    SetAlign(-400);
    SetGoChance(45);

    AddItem(CAOSARM"maza",REFRESH_REMOVE,SF(wieldme));
}
