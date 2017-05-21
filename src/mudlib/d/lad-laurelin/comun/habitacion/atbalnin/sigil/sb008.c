
#include "./path.h"
inherit LAD_ROOM;

create()
{
 ::create();

 SetIntShort("la muralla norte de Sigil");
 SetIntLong("Estas en la muralla norte de Sigil, este tramo esta vigilado por guardias elfos\n"
		"que estan protegiendo a sus companyeros unos metros mas abajo. Desde aqui arriba\n"
		"tienes un hermoso paisaje que admirar. Los pasillos de la historia tambien pueden\n"
		"verse muy bien desde aqui arriba aunque no se puede llegar a leer nada.\n");
 SetIndoors(1); 

 SetIntBright(MAX_SUNBRIGHT/2);

 SetIntNoise("Se oyen los constantes pasos de los guardias elfos a tu alrededor.\n");

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
 AddExit("este","./sb009");
 AddExit("oeste","./sb007");
}
