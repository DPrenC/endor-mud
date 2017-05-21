// kurzuj.c
// Un orco mu malévolo que pulula por Glucksfall
// Como Woo no le puso cabecera, se la pone Nemesis.
// Y ya de paso, le cambia el nombre de Cloro (hermano de Formo)
// a Kurzuj
// (Verás qué risa les va a dar a los players...)

#include "./path.h"
#include <skills.h>
#include <properties.h>


inherit NPC;

create() {
 ::create();
seteuid(getuid());
 SetStandard("Kurzuj","orco",([GC_LUCHADOR:55]),GENERO_MASCULINO);
 SetIds(({"kurzuj","orco"}));
 SetShort("Kurzuj el orco");
 SetAlign(-100);
 SetWhimpy(0); // O mata o muere

 AddItem(ARMA("hacha_combate"),REFRESH_REMOVE,SF(wieldme));
 AddItem(PROT("yelmo_orco"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("escudo_orco"),REFRESH_REMOVE,SF(wearme));

}

//mixed SetCombatDelay(int time, string s) { return ::SetCombatDelay(to_int(time/3),s);}