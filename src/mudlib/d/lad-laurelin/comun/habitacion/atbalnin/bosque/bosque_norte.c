#include "path.h"
inherit ATB_B("std_bosque");

create(){
  string w;
  ::create();

  switch (random(5)) {
    case 0: w="Ante t� ves una senda de tierra fina que conduce hacia el "
    	"norte y hacia el sur, creada seguramente por los pies de todos los "
    	"viajeros que van y vienen de la ciudad. Esta parte del bosque no "
    	"es demasiado frondosa ni la vegetaci�n excesivamente compacta.\n";
	break;
    case 1: w="En este suelo bastante pisado no ves demasiada hierba; m�s "
    	"bien lo que ves es una tierra fina que cubre toda la zona. Los "
    	"�rboles, aunque grandes, no son enormes, y de vez en cuando ves "
    	"alguno creciendo entre sus hermanos.\n";
    	break;
    case 2: w="Ves distintos tipos de �rboles, unos m�s peque�os que otros, "
    	"aunque ninguno es gigante. Seguramente esta parte del bosque es "
    	"relativamente nueva, quiz�s s�lo tenga un par de centenares de "
    	"a�os.\n";
    	break;
    case 3: w="Esta parte del bosque no es demasiado frondosa. La senda "
    	"que ves a tus pies lo recorre en todas direcciones haciendo el "
    	"camino bastante m�s facil.\n";
    	break;
    default: w="Ves �rboles y arbustos j�venes, y alg�n que otro animalillo "
    	"furtivo espi�ndote. Las huellas de civilizaci�n son bastante "
    	"evidentes por aqu�, puesto que la zona parece bastante transitada "
    	"como as� lo demuestra el suelo desnudo.\n";
  }

  SetIntLong(W(w));
  SetIntShort("la zona norte del bosque de Atbalnin");
  SetIntNoise("Escuchas el sonido de la naturaleza.\n");
  SetIntSmell("Huele a naturaleza.\n");
  SetLocate("bosque de Atbalnin");
  AddDetail(({"huella", "huellas"}), "Son las huellas de peque�os animales.\n");
  AddDetail(({"rama", "ramas", "arbusto", "arbustos"}), "Ves las peque�as ramas de los arbustos.\n");
  AddDetail(({"vegetacion", "vegetaci�n"}), "La vegetaci�n no es demasiado densa.\n");
  AddDetail("bosque", "Est�s en la zona norte del bosque de Atbalnin, una zona relativamente joven.\n");
  SetIndoors(0);
}
