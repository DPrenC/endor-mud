/*
DESCRIPCION  : Maucholeo en el que ahora habita un Lich
FICHERO      : /d/lad-laurelin/comun/habitacion/tiinkdhil/Mausoleo1.c
NOTAS        :
CREACION     : Alura (Julio del 2000)
*/

#include "./path.h"
#include <properties.h>
#include <rooms.h>
#include <door.h>

inherit ROOM;

create() {
  ::create();
SetIntShort("la morada del lich");
SetIntLong(
"  Te encuentras en una pequeña estancia en medio de la cual ves lo que queda\n"
"de una bella tumba rodeada por telarañas, mugre, y un olor especial, maloliente.\n"
"Descubres que el mal olor es producido por los grandes candelabros que bordean\n"
"un pequeño trono situado detras del mausoleo.\n");

AddDetail(({"trono"}),
"  Es grotesco y esta compuesto de craneos humanos.\n");
AddDetail (({"candelabros","candelabro"}),
"  Tienen la altura de un elfo, parecen hechos por un metal oscuro, hierro tal\n"
"vez. Tiran un humo amarillo que realmente apesta.\n");
AddDetail (({"tumba","mausoleo"}),
"  Esta abierto y partido en dos. No hay nada dentro.\n");

SetIntNoise(" Ni una mosca.\n");
SetIntSmell("  Huele a azufre y algo mas... como a podrido.\n");
SetLocate("Cementerio2");
SetIndoors (1); /* 0 exterior; 1 interior */
SetIntBright(26);

AddDoor("smaucem1","este","camino2","puertas","Son las puertas de salida del mausoleo.\n",
	([P_MATERIAL:M_BRONCE,P_PUERTA_VIDA:200,P_PUERTA_VIDA_MAX:200]) );

}