/***
Fichero: serpiente.c
Autor: kastwey@simauria
Descripci�n: Serpiente para las celdas de siempreunidos.
Las descripciones est�n sacadas de la v�vora de la mina del parque de novatos de limbo...
Thanks Angor por las descripciones.
Creaci�n: 07/12/2004
***/


#include "path.h"
#include <combat.h>
#include <properties.h>
#include <gremios.h>


inherit NPC;

create() {
    ::create();
    SetStandard("una vibora", "serpiente", ([ GC_TORPE: 8]), GENDER_FEMALE);
    SetShort("una vibora negra");
    SetLong(
        "Es una vibora de color oscuro, casi negro. No es muy grande, pero te mira al\n"
        "tiempo que olisquea el aire con una lengua b�fida de color p�rpura. Crees que\n"
        "esta serpiente debe ser bastante peligrosa...\n");
    SetIds(({"serpiente", "vibora", "reptil"}));
    SetSize(P_SIZE_SMALL);
    SetAggressive(1);
    SetHands(({ ({"colmillos", TD_PENETRACION, 5}) }));
    SetWeight(1000);
}

