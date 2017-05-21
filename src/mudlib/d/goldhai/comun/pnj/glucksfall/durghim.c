// durghim.c
// Un draconiano mu malévolo que pulula por Glucksfall
// Como Woo no le puso cabecera, se la pone Nemesis.
// Y ya de paso, le cambia el nombre de Jorgu a Dhurgim
// (Verás qué risa les va a dar a los players...)


#include "./path.h"
#include <skills.h>
#include <properties.h>


inherit NPC;

create () {
 ::create();
seteuid(getuid());
 SetStandard("Durghim","draconiano",([GC_LUCHADOR:55]),GENERO_MASCULINO);
 SetIds(({"durghim","draconiano"}));
 SetShort("Durghim");
 SetAlign(-50);
 SetWhimpy(0); // O mata o muere

 AddItem(ARMA("hacha_combate"),REFRESH_REMOVE,SF(wieldme));
 AddItem(ARMA("hacha_combate"),REFRESH_REMOVE,SF(wieldme));
 AddItem(PROT("botas-negras"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("coraza-acero"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("guantes-metal"),REFRESH_REMOVE,SF(wearme));

 InitChats(5,({"Durghim te mira y te dice: '¿Quieres camorra?'\n",
               "El draconiano se mira los pies y frunce el ceño.\n"}));
 InitAChats(10,({"Durghim dice: 'Ya verás te voy a destrozar.'\n",
                 "Durghim grita: '¿Cómo osas atacarme?'\n"}));
}

//mixed SetCombatDelay(int time, string s) { return ::SetCombatDelay(to_int(time/3),s);}