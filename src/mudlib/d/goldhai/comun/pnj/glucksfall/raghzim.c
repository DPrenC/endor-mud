// raghzim.c
// Un draconiano mu malévolo que pulula por Glucksfall
// Como Woo no le puso cabecera, se la pone Nemesis.
// Y ya de paso, le cambia el nombre de Crisóstomo a Raghzim
// (Verás qué risa les va a dar a los players...)



#include "./path.h"
#include <skills.h>
#include <properties.h>


inherit NPC;

create() {
 ::create();
seteuid(getuid());
 SetStandard("Raghzim","draconiano",([GC_LUCHADOR:60]),GENERO_MASCULINO);
 SetIds(({"raghzim","draconiano"}));
 SetShort("Raghzim el draco");
 SetAlign(-30);
 SetWhimpy(0); // O mata o muere

 AddItem(ARMA("hacha_combate"),REFRESH_REMOVE,SF(wieldme));
 AddItem(PROT("escudo_acero2"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("botas-negras"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("coraza-acero"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("guantes-metal"),REFRESH_REMOVE,SF(wearme));
 InitChats(5,({"Raghzim sonríe y te pregunta: '¿Cómo estás?'\n",
               "Raghzim empieza a juguetear con una piedra.\n"}));
 InitAChats(10,({"Raghzim grita de rabia: '¡¡AAARGGGHHHH!!'\n",
                 "Raghzim dice: 'Espera y verás de lo que soy capaz.'\n"}));
}

//mixed SetCombatDelay(int time, string s) { return ::SetCombatDelay(to_int(time/3),s); }