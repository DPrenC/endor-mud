#include <mud.h>


#include <properties.h>

#include "path.h"



inherit SIM_ROOM;




create () {

  ::create();

Set(P_INT_SHORT,"un campo de maíz");

SetIntLong(

"Te encuentras en medio de un campo de maiz. Ves maiz por todas partes.\n"

"Logras atisbar lo que podria ser una granja hacia el oeste. Hay un\n"

"espantapajaros a tu lado intentando cumplir con su cometido.\n");



SetIndoors(0);  // 1-> cubierto 0-> descubierto

SetIntNoise("Escuchas el graznido de un cuervo asustado ante tu presencia.\n");

SetIntSmell("Atchiss. Podrias ser alergico al maiz?\n");

SetLocate("nandor");



AddDetail(({"espantapajaros"}),

"Una mala imitacion de algo mal vestido que aparenta ser humano.\n");

AddDetail(({"maiz"}),

"Amarillo, dorado, esta por todas partes...\n");

AddExit("oeste","maizal1");

// AddExit("este","");

HideExit("oeste",1);

AddItem(COMIDA("mazorca"),REFRESH_REMOVE,1);

}
