// kas.c
// Un kainoak mu malévolo que pulula por Glucksfall
// Como Woo no le puso cabecera, se la pone Nemesis.
// Y ya de paso, le cambia el nombre de Genserico a Kas-Hal-Nati
// (Verás qué risa les va a dar a los players...)



#include "./path.h"
#include <skills.h>
#include <properties.h>


inherit NPC;

create() {
 ::create();
seteuid(getuid());
 SetStandard("Kas-Hal-Nari","kainoak",([GC_LUCHADOR:60]),GENERO_MASCULINO);
 SetIds(({"kas-hal-nari","kas","hal","nari","odu","namun","odu namun","kainoak" }));
 SetShort("Kas-Hal-Nari el 'Odu Namun'");
 SetAlign(-30);
 SetWhimpy(0); // O mata o muere
 SetDex(TO->QueryDex()+5); //le doy destreza a cambio de fuerza
 SetStr(TO->QueryStr()-5);
 SetAggressive(2);

 AddItem(ARMA("espada-larga"),REFRESH_REMOVE,SF(wieldme));
 AddItem(ARMA("espada-larga"),REFRESH_REMOVE,SF(wieldme));
 AddItem(ARMA("espada-larga"),REFRESH_REMOVE,SF(wieldme));
 AddItem(ARMA("espada-larga"),REFRESH_REMOVE,SF(wieldme));
 InitAChats(10,({"Kas-Hal-Nari dice: '¡¡No me has caído bien desde que te he visto!!'\n",
                 "Kas-Hal-Nari grita: '¡¡Odio a los de tu calaña!!'\n"}));
}

//mixed SetCombatDelay(int time, string s) { return ::SetCombatDelay(to_int(time/3),s);}