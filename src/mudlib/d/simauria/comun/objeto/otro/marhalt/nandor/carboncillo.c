/****************************************************************************
Fichero: carboncillo.c
Autor: Ratwor
Fecha: 01/06/2007
Descripción: algo para escribir en los pergaminos.
****************************************************************************/

#include <properties.h>

inherit THING;

create(){
    ::create();
    AddId(({"lapiz", "lápiz", "carboncillo", "lapicero"}));
    SetShort("un carboncillo");
    SetLong("Un carboncillo para escribir en los pergaminos.\n");
    SetValue(30);
    SetWeight(90);
    Set(P_SIZE,P_SIZE_SMALL);
}

init(){
    ::init();
    add_action("cmd_escribir", "escribir");
}

public int cmd_escribir(string str){
    if(!str) return notify_fail("¿Escribir qué?\n");
    if (!present(TO,TP))
        return notify_fail("Deberás tener el carboncillo en las manos para poder "
        "escribir.\n", NOTIFY_NOT_VALID);
        if(environment()->QueryEscribible()!=1)
        return notify_fail("No puedes ir escribiendo por todas partes.\n",
        NOTIFY_NOT_VALID);
}
