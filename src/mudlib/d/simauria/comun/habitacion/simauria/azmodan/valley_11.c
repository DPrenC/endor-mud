/***********************************************************/
//	"valley_11"
//	Valle, fuente
//	11-12-01 : Creaci�n -> Kodex
//	11-12-01 : Modificaci�n -> Kodex
//
//
#include "./path.h"
#include <sounds.h>
inherit SIM_ROOM;


int beber_cmd(string str)
{

if (!str) return notify_fail("�Beber qu�?\n");
if (str == "agua" || str == "agua de cascada" || str == "de cascada")
	{
	if (TP->QueryDrink() >= TP->QueryMaxDrink())
   		{
    		write("No puedes beber nada m�s.\n");
    		say(capitalize(TP->QueryRealName())+" intenta beber de la cascada, pero est� saciado.\n");
    		return 1;
   		}
  	else
  		{
  		TP->SetDrink(TP->QueryDrink()+5);
		say(capitalize(TP->QueryName())+" bebe un trago del agua cristalina de la cascada.\n");
		write("Bebes un poco de agua de la cascada.\nEs el agua m�s refrescante que has bebido jam�s.\n");
		play_sound(TO, SND_SUCESOS("beber"));
 		return 1;
		}
	}
else
	return notify_fail("No encuentras " + str + " para beber.\n");

}


create() {
    ::create();
    SetIntShort("el centro del valle, junto a una peque�a cascada");
    SetIntLong("Aqu� puedes ver como el agua fluye por una peque�a cascada a trav�s"
    " de unas rocas cayendo encima de una especie de recipiente de piedra erosionada.\n "
    "La vegetaci�n rodea la rudimentaria construcci�n, dando la cascada colorido a esta zona "
    "verde del valle.\n");
    SetIndoors(0);
    SetIntNoise("Oyes el sonido del agua.\n");
    SetIntSmell("Huele a aire puro.\n");
    AddDetail(({"cascada", "agua"}),
    "Es una peque�a cascada natural de la que cae agua cristalina,"
    " tiene una apariencia muy refrescante.\n");
    AddExit("oeste",VALLE_AZMODAN("valley_10"));
    AddExit("este",VALLE_AZMODAN("valley_12"));
    AddExit("norte",VALLE_AZMODAN("valley_15"));
    AddExit("sur",VALLE_AZMODAN("valley_07"));
    SetLocate("Valle");
    SetSoundEnvironment(SND_AMBIENTES("manantial"));
    if (random(100) < 60)
    	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
    if (random(100) < 15)
    	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
}

init()
{
    ::init();
    add_action("beber_cmd","beber");
}
