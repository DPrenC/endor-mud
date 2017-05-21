/****************************************************************************
Fichero: conserje.c
Autor: Ratwor
Fecha: 14/08/2007
Descripción: El conserje del ayuntamiento, totalmente reformado para que sea coerente.
****************************************************************************/

#include <properties.h>
inherit NPC;

create() {
    ::create();
    SetStandard("el conserje", "humano", 12, GENDER_MALE);
    SetShort("El conserje del ayuntamiento");
    SetLong("El conserje es un humano de complexion normal. Por su comportamiento "
    "parece educado y refinado.\n");
    AddId(({"hombre", "conserje"}));
    Set(P_NOGET,"No alcanzas a cogerlo.\n");
    SetCitizenship("gorat");
    InitChats(4,({"El conserje silba una canción.\n",
        "El conserje te observa.\n",
        "El conserje ojea unos papeles.\n",
        "El conserje te pregunta: '¿Necesitas algo?'\n"}));

    AddQuestion(({"informacion","información"}),
        "El conserje dice: Aquí puedes pedir algunos documentos, o licencias.\n");
    AddQuestion(({"licencia de pesca","licencia","licencia para pescar"}),
        "El conserje dice: Para pedir una Licencia de Pesca escribe: 'pedir licencia "
        "para pescar.'\n");
}
