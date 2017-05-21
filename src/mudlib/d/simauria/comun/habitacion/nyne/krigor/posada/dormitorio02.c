
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

	SetIntShort("el sal�n de descanso");
	SetIntLong("En esta habitaci�n se hospedan los que tienen poco dinero. Se compone "
	"de peque�os catres repartidos por toda la habitaci�n y unas gruesas cortinas "
	"para dar un poco de intimidad.\n De las paredes cuelgan unos viejos cuadros de "
	"gente que no conoces, y en el techo hay dos grandes l�mparas.\n  Tambi�n hay unas "
	"peque�as ventanas por las que se ve la luna en las noches claras.\n");
	SetIntBright(45);
	SetIntSmell("El olor a sudor y cansancio casi se puede palpar.");
	AddExit("norte",KRIGOR("posada/pasillo"));
	AddDoor("norte", "la puerta de la habitaci�n humilde",
    "Esa puerta es para entrar a la habitaci�n humilde.\n",
    ({"puerta", "puerta del sur", "puerta de la habitaci�n humilde"}));
}
