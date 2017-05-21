// tuliel.c
// Un elfo mu gay que pulula por Glucksfall
// Como Woo no le puso cabecera, se la pone Nemesis.
// Y ya de paso, le cambia el nombre de Nepote (ahórrate la rima)
// a Tuliel
// [kastwey] ¿Nepote? ¿Para que me crezca la nariz? :P :P
// (Verás qué risa les va a dar a los players...)


#include "./path.h"
#include <skills.h>
#include <properties.h>


inherit NPC;

create() {
 ::create();
seteuid(getuid());
 SetStandard("Tuliel","elfo",([GC_LUCHADOR:55]),GENERO_MASCULINO);
 SetIds(({"tuliel","elfo"}));
 SetShort("Tuliel el elfo legendario");
 SetAlign(-70);
 SetWhimpy(0); // O mata o muere

 AddItem(ARMA("espada_elfica"),REFRESH_REMOVE,SF(wieldme));
 AddItem(ARMA("espada_elfica"),REFRESH_REMOVE,SF(wieldme));
 AddItem(PROT("botas-negras"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("coraza-acero"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("guantes-metal"),REFRESH_REMOVE,SF(wearme));

}

//mixed SetCombatDelay(int time, string s) { return ::SetCombatDelay(to_int(time/3),s);}