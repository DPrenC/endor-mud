#include <mud.h>


#include <properties.h>

#include "./path.h"



inherit SIM_ROOM;




create () {

  ::create();

Set(P_INT_SHORT,"un campo de maíz");

SetIntLong(

"Un campo de maiz de apariencia interminable te rodea. Te encuentras cerca\n"

"de una granja que esta hacia el oeste. Entre el maiz logras distinguir a\n"

"alguien hacia el este. Un grupo de cuervos vuela sobre tu cabeza.\n");



SetIndoors(0);

SetIntNoise("Escuchas el sonido de tus pasos al pisotear la hojarasca.\n");

SetIntSmell("Sientes olores lejanos a pan y comida recien hechos.\n");

SetLocate("nandor");



AddDetail(({"cuervos","cuervo"}),

"Un grupo de pajaros negros comedores de maiz.\n");

AddExit("suroeste","../sendero1");

AddExit("noroeste","huerto");

AddExit("este","maizal2");

HideExit("suroeste",1);

HideExit("noroeste",1);

HideExit("este",1);

AddItem(COMIDA("mazorca"),REFRESH_REMOVE,1);

}


