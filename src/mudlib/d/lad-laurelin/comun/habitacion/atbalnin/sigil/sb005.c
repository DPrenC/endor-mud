
#include "./path.h"
inherit LAD_ROOM;

create()
{
 ::create();
 SetIntShort("la muralla norte de Sigil");
 SetIntLong("La muralla norte de Sigil se encuentra bajo tus pies. Tiene un tamaño medio si\n"
		"la comparamos con las grandes murallas del Oeste y del Este, pero es mas grande\n"
		"que el resto de murallas de la ciudad. Paseando por aqui arriba puedes ver la\n"
		"gran torre de magia, los pasillos de la historia y las dos zonas de entrena-\n"
		"miento del norte.\n");
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

 AddExit("este","./sb006");
 AddExit("oeste","./sb004");
}
