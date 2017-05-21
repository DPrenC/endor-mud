
#include "./path.h"
inherit LAD_ROOM;

create()
{
 ::create();

 SetIntShort("la torre Nor NorOeste");
 SetIntLong("Te encuentras en la torre Nor-NorOeste de Sigil. Las torres de la muralla\n"
		    "de Sigil están construidas con marmol blanco para deslumbrar a todo aquel\n"
			"que las mira y permitir ver mejor a los que desde aqui vigilan la ciudad.\n"
			"Desde aqui se puede observar bien la torre y hay unas hermosas vistas.\n");
 SetIndoors(1); 

 SetIntBright(MAX_SUNBRIGHT/2);

 SetIntNoise(" Todo es tranquilo y silencioso. Tan sólo se oyen los pasos de los guardias\n"
             "vigilando y el canturrear de unos gorriones que han hecho aqui su nido.\n");

 SetIntSmell("Desde aquí aún se huele a naturaleza, árboles y plantas.\n");

 AddDetail(({"torre","muralla"}),
             " Las torres de Sigil se alzan hasta 8 metros por encima del suelo y a tan\n"
			 "solo 7 metros de la plataforma que sostiene el 2º piso de Sigil. Las murallas\n"
			 "refuerzan las paredes de metal dorado que hacen de Sigil una ciudad inexpugnable\n"
			 "desde el cielo, o sea desde fuera de Sigil.\n");
 AddDetail(({"vistas","vista","paisaje"}),
 			 " Desde aqui puedes observar la grandeza de la torre de magia y sus 4 pisos\n" 
			 "asi como las dos zonas de entrenamiento y los grandes árboles que hay en ellas.\n"); 
 AddExit("este","./sb002");
 AddExit("suroeste","./sb017");
 AddExit("abajo","./sb018");
}
