/****************************************************************************
Fichero: cebo.c
Autor: Ratwor
Fecha: 24/09/2007
Descripci�n: Un cebo para pescar.
****************************************************************************/

#include <properties.h>
inherit THING;

create() {
    ::create();
    SetShort("un gusano para cebo");
	AddId(({"gusano", "lombriz", "invertebrado", "cebo", "qcebo"}));
	SetLong("Es una peque�a lombriz que viene muy bien para pescar.\n");
    SetWeight(20);
    SetValue(5);
    Set(P_SIZE,P_SIZE_SMALL);
    SetSmell("Pues huele a gusano.\n");
}

init(){
    ::init();
    call_out("comer_cebo",d6());
    }

public void comer_cebo(){
    object pajaro = present("pajaro") || present("ave");
    if (pajaro && living(pajaro)){
        tell_room(environment(), CAP(pajaro->QueryShort())+
        " coge "+QueryShort()+" con el pico y se lo come.\n");
        remove();
    }
    return 0;
}

