// drex.c
// Un demonio mu malévolo que pulula por Glucksfall
// Como Woo no le puso cabecera, se la pone Nemesis.
// Y ya de paso, le cambia el nombre de Comodo a Drex-Ui
// (Verás qué risa les va a dar a los players...)

#include "./path.h"
#include <skills.h>
#include <properties.h>

inherit NPC;

create () {
  ::create();
  seteuid(getuid());
 SetStandard("Drex-Ui","demonio",([GC_LUCHADOR:60]),GENERO_MASCULINO);
 SetIds(({"drex-ui","demonio","drexui","drex","Drex"}));
 SetShort("Drex-Ui el demonio");
 SetAlign(-80);
 SetAggressive(2);
 SetWhimpy(0); // O mata o muere

 AddItem(ARMA("hacha_combate"),REFRESH_REMOVE,SF(wieldme));
 AddItem(ARMA("hacha_combate"),REFRESH_REMOVE,SF(wieldme));
 AddItem(PROT("botas-negras"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("coraza_drex-ui"),REFRESH_REMOVE,SF(wearme));
 AddItem(PROT("guantes-metal"),REFRESH_REMOVE,SF(wearme));
 AddItem("/obj/sunglasses",REFRESH_REMOVE,SF(wearme));

 InitAChats(2,({"Drex-Ui ruge: '¡¡No tienes escapatoria renacuajo!!'\n"}));
}

//mixed SetCombatDelay(int time, string s) { return ::SetCombatDelay(to_int(time/3),s); }