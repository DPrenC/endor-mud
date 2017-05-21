
#include "./path.h"
inherit LAD_ROOM;

create()
{
 ::create();

 SetIntShort("la muralla nortde de Sigil");
 SetIntLong("Estas en la muralla norte de Sigil. Desde aqui arriba tienes hermosos paisajes y\n"
		"vistas que admirar asi como los pasillos de la historia de Sigil. En estos momentos\n"
		"te estas preguntando que haces aqui arriba si no disfrutas del hermoso paisaje.\n");
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
 AddExit("este","./sb013");
 AddExit("oeste","./sb011");
}