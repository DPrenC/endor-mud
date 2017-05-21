/****************************************************************************
Fichero: ancestro.c
Autor: Ratwor
Fecha: 04/11/2007
Descripción: Un ancestro que se reencarna en algunos ogros al morir.
****************************************************************************/


#include "./path.h"
#include <gremios.h>
#include <properties.h>

inherit CAOSPNJ"ogro_base";

create(){

    ::create();
    SetStandard("el ancestro","ogro",([ GC_LUCHADOR:100+d6()]),GENERO_MASCULINO);
    SetShort("el ancestro de los ogros de las cavernas");
    SetLong("Este no es un ogro normal, como así lo demuestra su pronunciado aspecto "
    "brutal y endemoniado.\n  Se trata de la reencarnación de uno de los guerreros "
    "ancestrales que ha conseguido apoderarse de este nuevo cuerpo, gracias a la "
    "ayuda del dios Khorni.\n");
    AddId(({"ancestro","Ancestro","espiritu","ogro","Ogro", "ogro de las cavernas"}));
    SetAggressive(1);
    SetAlign(-1000);
    SetGoChance(90);
    AddWalkZones(CAOSHAB);
    SetStr(QueryStr()+10);
    SetCon(QueryCon()+10);
    SetDex(QueryDex()+10);
}

init(){
    ::init();
    SetAggressive(1);
}

public varargs void Die(mixed silent){
    if (!silent) tell_room(ENV(TO),
    "El Ancestro grita: ¡Aaaaargh!.\n ¡Mi Diós, el gran Khorni, me dará otro cuerpo para "
    "que te busque y te devore!\n");
    return ::Die(silent);
}
