/*
Fichero: npc_nobel.c
Autor: Orome.
Fecha: 28/09/2014
Descripción: Archivo base de animalillos de nivel mínimo
*/
#include <properties.h>

inherit NPC;

create ()
{
	::create();

	seteuid(getuid());

	SetWhimpy(2);
	}

public varargs int Defend(int dam, int dam_type, mixed flags, string *xtras){
    //write(TO->QueryHP());
        if(TP->QueryGuildLevel()<5 && TO->QueryHP()>3 && TO->QueryHP()<TO->QueryMaxHP())
                                TO->SetHP(2);
                                                    return ::Defend(dam, dam_type, flags, &xtras);
}

