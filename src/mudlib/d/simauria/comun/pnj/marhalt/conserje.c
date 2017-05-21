/****************************************************************************
Fichero: conserje.c
Autor: Ratwor
Fecha: 14/08/2007
Descripción: El recaudador de tributos del noble.
****************************************************************************/

#include <properties.h>
inherit NPC;

create() {
    ::create();

    SetStandard("el recaudador", "humano", 15, GENDER_MALE);
    SetShort("El recaudador");
    SetCitizenship("nandor");
    SetLong("El recaudador es un humano de complexion normal. Por su comportamiento "
    "parece educado y refinado.\n");
    AddId(({"hombre", "conserje", "recaudador"}));
    Set(P_NOGET,"No alcanzas a cogerlo.\n");
    InitChats(4,({"El recaudador silba una canción.\n",
        "El recaudador te observa.\n",
        "El recaudador ojea unos papeles.\n",
        "El recaudador te pregunta: '¿Vienes a pagar tus tributos?'\n"}));
    AddQuestion(({"informacion","censo","información"}),
        "El recaudador dice: 'Para censarte escribe \"censar\", y para consultar "
        "el censo, \"consultar\".'\n");
}
