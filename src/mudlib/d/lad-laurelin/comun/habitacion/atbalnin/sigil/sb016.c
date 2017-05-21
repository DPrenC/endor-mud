
#include "./path.h"
inherit LAD_ROOM;

create()
{
 ::create();

 SetIntShort("la torre Nor-NorEste");
 SetIntLong("Has llegado a la torre Nor-NorEste de Sigil, otra de las blancas torres de marmol\n"
		"de esta explendida ciudad. El brillo de la pulida torre permite ver mas alla de lo\n"
		"normal, incluso se puede ver el ayuntamiento, ademas de la torrde de magia y el\n"
		"lugar donde se preparan los jovenes heroes.\n");

 SetIndoors(1); 
 SetIntBright(MAX_SUNBRIGHT/2);

 SetIntNoise("Todo es tranquilo y silencioso.\n");

 SetIntSmell("Hueles a naturaleza, arboles y plantas.\n");

 AddDetail(({"torre","muralla"}),
             " Las torres de Sigil se encuentran a 6 metros por encima del suelo y a tan\n"
		 "solo 7 metros de la plataforma que sostiene el 2º piso de Sigil. Las murallas\n"
		 "refuerzan las paredes de metal dorado que hacen de Sigil una ciudad inexpugnable\n"
		 "desde el cielo, o sea, desde fuera de Sigil.\n");
 AddDetail(({"vistas","vista","paisaje"}),
 		 " Desde aqui puedes observar la grandeza de la torre de magia y sus 4 pisos\n" 
		 "asi como la zona de entrenamiento y los grandes árboles que hay en ella.\n"); 
 AddExit("sureste","./sb034");
 AddExit("oeste","./sb015");
 AddExit("abajo","./sb033");
}
