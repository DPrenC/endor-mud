
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

	SetIntShort("el salón de descanso");
	SetIntLong("En esta habitación se hospedan los que tienen poco dinero. Se compone "
	"de pequeños catres repartidos por toda la habitación y unas gruesas cortinas "
	"para dar un poco de intimidad.\n De las paredes cuelgan unos viejos cuadros de "
	"gente que no conoces, y en el techo hay dos grandes lámparas.\n  También hay unas "
	"pequeñas ventanas por las que se ve la luna en las noches claras.\n");
	SetIntBright(45);
	SetIntSmell("El olor a sudor y cansancio casi se puede palpar.");
	AddExit("norte",KRIGOR("posada/pasillo"));
	AddDoor("norte", "la puerta de la habitación humilde",
    "Esa puerta es para entrar a la habitación humilde.\n",
    ({"puerta", "puerta del sur", "puerta de la habitación humilde"}));
}
