
#include "path.h"

inherit SIM_ROOM;

create() {
    ::create();

	SetIntShort("la habitacion de lujo");
	SetIntLong("Esta habitaci�n est� reservada a la gente importante. Contiene una "
	"cama de roble, en la que se aprecia el relieve de una bruja montada en su escoba.\n"
	" Las s�banas est�n limpias y son de seda morada. Sobre la cama hay un cuadro en "
	"el que se ve a una pareja de enamorados ba��ndose desnudos en un lago.\n  Al "
	"oeste hay una gran ventana por la cual se ven los famosos anocheceres de Krigor.\n");
	SetIntBright(45);
	AddDetail("bruja", "Est� tallada en la madera de roble de la cama.\n");
	AddDetail(({"cuadro", "pareja", "pareja de enamorados", "enamorados"}),
	"En el cuadro se ve un paisaje con un lago y unos enamorados ba��ndose desnudos.\n");
	SetIntSmell("El olor a dulce frangacion de rosas te enbriaga.");
	AddExit("este",KRIGOR("posada/pasillo"));
	AddDoor("este", "la puerta de la habitaci�n lujosa",
    "Es la puerta para entrar en la habitaci�n lujosa",
    ({"puerta", "puerta del oeste", "puerta de la habitaci�n lujosa"}));
}
