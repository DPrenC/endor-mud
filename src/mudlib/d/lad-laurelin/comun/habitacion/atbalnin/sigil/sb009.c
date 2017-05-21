
#include "./path.h"
inherit LAD_ROOM;

create()
{
 ::create();

 SetIntShort("la muralla norte de Sigil");
 SetIntLong("Estas en el centro del tramo de la muralla norte de de Sigil. Desde aqui algunos\n"
		"arqueros elfos protegen a sus companyeros que vigilan el portal del norte.\n"
		"Aun a pesar del ambiente de vigilancia que hay a tu alrededor, puedes observar los\n"
		"pasillos de la historia justo enfrente y abajo y la gran torre de magia.\n");
 SetIndoors(1); 

 SetIntBright(MAX_SUNBRIGHT/2);

 SetIntNoise("Todo es demasiado tranquilo y silencioso para la cantidad de guardias presentes.\n");

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
 AddDetail("portal"," Aqui tienes una buenas vista de una de las tres entradas a la ciudad.\n");
 AddExit("este","./sb010");
 AddExit("oeste","./sb008");
}
