/***********************************************************/
//	"valley_04"
//	Valle
//	11-12-01 : Creación -> Kodex
//	11-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
inherit SIM_ROOM;



create() {
    ::create();
    SetIntShort("el sureste del valle");
    SetIntLong("Estás al sureste del valle de Azmodan. Un pequeño riachuelo fluye rápidamente"
    " justo a tu lado, puedes ver algunas piedras pequeñas en el agua bajando a "
    "través de su cauce. El valle se extiende hacia el norte y el oeste.\n");
    SetIndoors(0);
    SetIntNoise("Oyes el sonido del agua.\n");
    SetIntSmell("Huele a aire puro.\n");
    AddDetail(({"rocas", "piedras"}),
    "Son piedrecitas que se han ido desprendiendo de rocas más grandes.\n");
    AddDetail(({"rio", "río", "riachuelo", "agua"}),
    "Es un pequeño riachuelo con poco nivel de agua que recorre esta zona del valle.\n");

    AddExit("oeste",VALLE_AZMODAN("valley_03"));
    AddExit("norte",VALLE_AZMODAN("valley_08"));
    SetLocate("Valle");
    if (random(100) < 60)
	    AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
    if (random(100) < 15)
    	AddItem(NPC_AZMODAN("goblin"),REFRESH_DESTRUCT,1);
}
