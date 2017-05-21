/***********************************************************/
//	"laberinto"
//
//	Pedazo laberinto xD no rula el teleport(por razones obvias)
//	Kodex: Creación y ultima modificación 17-02-02
//


#include <colours.h>
#include <moving.h>
#include <magia.h>
#include <properties.h>
#include "./path.h"
inherit SIM_ROOM;




create() {
::create();
SetIndoors(1);
SetIntBright(25);
SetIntShort("un laberinto");
Set(P_TPORT,TPORT_NO);
Set(P_TPORT_REASON,"Unas vibraciones mágicas muy fuertes te impiden teletransportarte.\n");
SetIntLong(W("Estás en un laberinto de roca. Las paredes ennegrecidas,"
" hace tiempo estaban decoradas. Esto no parece parte de la mina"
" sino una construcción antigua. Oyes unos pasos que vienen de "
"alguna parte. Estás muy confundido y no sabes a donde te llevarán"
" las salidas...\n"));
SetIntNoise("Oyes los pasos de algo... o alguien.\n");
SetIntSmell("El aire es irrespirable.\n");
SetLocate("Laberinto");
switch (random(6))
	{
	case 0: AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1); break;
	case 1: AddItem(NPC_AZMODAN("orco"),REFRESH_DESTRUCT,1); break;
	case 2: AddItem(NPC_AZMODAN("uruk"),REFRESH_DESTRUCT,1); break;
	case 3: AddItem(NPC_AZMODAN("shaman"),REFRESH_DESTRUCT,1); break;
	default:break;
	}
}

init() {
string sexo;
::init();
if (TP->QueryGender()==2)
	sexo ="a";
else
	sexo = "o";
switch (random(5))
	{
	case 0: write(TC_YELLOW+"No sabes bien como llegaste a esta parte del laberinto.\n"+TC_NORMAL); break;
	case 1: write(TC_PURPLE+"Estás perdid"+sexo+" y muy confundid"+sexo+".\n"+TC_NORMAL); break;
	case 2: write(TC_CYAN+"Este es un buen lugar para perderse...\n"+TC_NORMAL); break;
	case 3: write(TC_RED+"No te crees capaz de encontrar la salida.\n"+TC_NORMAL); break;
	case 4: write(TC_GREEN+"Estás aturdid"+sexo+" de ver un laberinto tan complicado.\n"+TC_NORMAL); break;
	}
}		

/* Al carajo las salidas aleatorias.
Aleatorio()
{
	TP->move(LABERINTO_AZMODAN(random(6)),M_GO);
	return 1;
}
*/

Salir()
{
if (TP->QueryName() == "un troll")
	return 1;
write(TC_CYAN+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	+TC_BOLD+"¡¡¡Un torrente de agua sale de una de las paredes y te arrastra!!!\n"
	+TC_NORMAL+TC_CYAN+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+TC_NORMAL);
tell_room(VALLE_AZMODAN("valley_01"),"¡¡¡"+capitalize(TP->QueryRealName())+" llega arrastrado por un torrente de agua!!!\n");
TP->move(VALLE_AZMODAN("valley_01"),M_SILENT);
TP->LookAfterMove();
return 1;
}