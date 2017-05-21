#include "path.h"
inherit ATB_B("std_bosque");

create(){
  string w;
  ::create();

  switch (random(5)) {
    case 0: w="Ante tí ves una senda de tierra fina que conduce hacia el "
    	"norte y hacia el sur, creada seguramente por los pies de todos los "
    	"viajeros que van y vienen de la ciudad. Esta parte del bosque no "
    	"es demasiado frondosa ni la vegetación excesivamente compacta.\n";
	break;
    case 1: w="En este suelo bastante pisado no ves demasiada hierba; más "
    	"bien lo que ves es una tierra fina que cubre toda la zona. Los "
    	"árboles, aunque grandes, no son enormes, y de vez en cuando ves "
    	"alguno creciendo entre sus hermanos.\n";
    	break;
    case 2: w="Ves distintos tipos de árboles, unos más pequeños que otros, "
    	"aunque ninguno es gigante. Seguramente esta parte del bosque es "
    	"relativamente nueva, quizás sólo tenga un par de centenares de "
    	"años.\n";
    	break;
    case 3: w="Esta parte del bosque no es demasiado frondosa. La senda "
    	"que ves a tus pies lo recorre en todas direcciones haciendo el "
    	"camino bastante más facil.\n";
    	break;
    default: w="Ves árboles y arbustos jóvenes, y algún que otro animalillo "
    	"furtivo espiándote. Las huellas de civilización son bastante "
    	"evidentes por aquí, puesto que la zona parece bastante transitada "
    	"como así lo demuestra el suelo desnudo.\n";
  }

  SetIntLong(W(w));
  SetIntShort("la zona norte del bosque de Atbalnin");
  SetIntNoise("Escuchas el sonido de la naturaleza.\n");
  SetIntSmell("Huele a naturaleza.\n");
  SetLocate("bosque de Atbalnin");
  AddDetail(({"huella", "huellas"}), "Son las huellas de pequeños animales.\n");
  AddDetail(({"rama", "ramas", "arbusto", "arbustos"}), "Ves las pequeñas ramas de los arbustos.\n");
  AddDetail(({"vegetacion", "vegetación"}), "La vegetación no es demasiado densa.\n");
  AddDetail("bosque", "Estás en la zona norte del bosque de Atbalnin, una zona relativamente joven.\n");
  SetIndoors(0);
}
