/*
DESCRIPCION : un fantasma
FICHERO     : /d/akallab/comun/pnj/monstruo/fantasma.c
MODIFICACION: 27-11-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

inherit NPC;

#include <properties.h>
#include <living.h>
#include <moving.h>
#include <attributes.h>

create(){
::create();
SetName("un fantasma");
SetShort("un fantasma");
SetLong("Una forma semitransparente que flota en el aire. El fantasma vaga eternamente "
        "por esta zona en busca de nuevas victimas que aplaquen su dolor.\n");
SetRace("nomuerto");
SetGender(GENDER_FEMALE);
SetIds(({"fantasma","nomuerto","monstruo"}));
SetLevel(8+random(5));
SetAC(5);
Set(P_HANDS,({({"un toque debilitador",0,10}),({"una terrible mirada",0,10})}));
Set(P_CORPSE,1);
SetAggressive(1);
SetWeight(10);
SetAlign(-900);
}

public varargs void Die(mixed silent){
  tell_room(environment(TO),"El fantasma se disuelve en una fina bruma.\n");
  ::Die(silent);
}
