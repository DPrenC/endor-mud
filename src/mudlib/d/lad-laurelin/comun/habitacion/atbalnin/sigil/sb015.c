
#include "./path.h"
inherit LAD_ROOM;

create()
{
 ::create();

 SetIntShort("la muralla norte de Sigil");
 SetIntLong("La muralla norte de Sigil esta bajo tus pies, al oeste mas muralla que admirar y\n"
		"al este la torre Nor-NorEste de Sigil. Aun se puede ver algo de paisaje desde aqui\n"
		"aunque no se puede apreciar muy bien los pasillos de la historia.\n");
 SetIndoors(1); 

 SetIntBright(MAX_SUNBRIGHT/2);

 SetIntNoise("Todo es tranquilo y silencioso.\n");

 SetIntSmell("Hueles a naturaleza, arboles y plantas.\n");

 AddDetail(({"vistas","vista","paisaje"}),
 		 " Desde aqui puedes observar la grandeza de la torre de magia y sus 4 pisos\n" 
		 "asi como las dos zonas de entrenamiento y los grandes árboles que hay en ellas.\n"); 
 AddDetail(({"pasillo","pasillos"}),
 		 " Tan solo puedes ver a la noble gente de la ciudad de Sigil paseando por esta\n" 
		 "gran libreria viviente, ya que los escritos estan en unos enormes muros apoyados\n"
		 "entre los grandes arboles y por supuesto el sabio de la ciudad se encuentra ahi\n"
		 "mismo explicando a los escritores la historia de los elfos, la cual van transcribiendo\n"
		 "a esas milenarias paredes creadas con un material ya olvidado construir.\n"); 
 AddExit("este","./sb016");
 AddExit("oeste","./sb014");
}
