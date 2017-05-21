#include "path.h"
inherit ATB_B("std_bosque");

create(){
  string w;
  SetNoAnimals(1);
  ::create();

  switch (random(7)) {
    case 0: w="Esta parte del bosque parece tener miles de años. Los árboles "
    	"son realmente enormes, y el aspecto que dan es bastante lúgubre, "
    	"incluso amenazador. Quizás sea por eso por lo que han resistido tanto "
    	"tiempo, por que prácticamente nadie se aventura por aqui, y quien lo "
    	"hace cuenta extrañas historias...\n";
	break;
    case 1: w="Estás rodeado por lo que podrían ser los abuelos de los árboles "
    	"del resto del mundo. Siglos y siglos han vivido en relativa paz. Aunque "
    	"han sido escenario de batallas e invasiones, siempre han sido "
    	"respetados por los ejércitos, ya sea por respeto o por miedo.\n";
    	break;
    case 2: w="Allí donde mires verás árboles grandes, oscuros y retorcidos. "
    	"Estos árboles confieren al bosque un aspecto oscuro, lúgubre... "
    	"seguramente la zona está plagada de seres peligrosos y agresivos, "
    	"con los que seguramente es mejor no meterse.\n";
    	break;
    case 3: w="Ves el suelo recubierto de unos matojos de hierba que "
    	"seguramente no han sido excesivamente pisados por los habitantes de "
    	"los alrededores. Ni siquiera los lobos suelen atreverse a "
    	"adentrarse en esta zona.\n";
    	break;
    case 4: w="El suelo está salpicado de raíces de todos los árboles que "
    	"crecen a tu alrededor. Seguramente serán las raíces más largas "
    	"de toda la zona, teniendo en cuenta el tiempo que llevan aquí. "
    	"Un escalofrío recorre tu cuerpo y piensas que sería más sensato "
    	"ir a un lugar más apacible.\n";
    case 5: w="Todo a tu alrededor parece hostil; los árboles que parecen "
    	"mirarte, las sombras que parecen moverse, algún crujido de alguna "
    	"rama, el silencio que reina en la zona debido a los pocos animales "
    	"que por aquí habitan...\n";
    default: w="Desde luego no sería excesivamente tranquilizador el "
    	"perderse por aquí. ¡Quién sabe los peligros que pueden acecharte "
    	"en este milenario bosque!\n";
  }

  SetIntLong(W(w));
  SetIntShort("la zona sur del bosque de Atbalnin");
  SetIntNoise("Escuchas el sonido de la naturaleza.\n");
  SetIntSmell("Huele a naturaleza.\n");
  SetLocate("bosque de Atbalnin");
  AddDetail(({"huella", "huellas"}), "Son las huellas algo grande que camina arrastrándose.\n");
  AddDetail(({"rama", "ramas", "arbusto", "arbustos"}), "Las ramas de los arbustos te impiden el paso en varias direcciones.\n");
  AddDetail(({"vegetacion", "vegetación"}), "La vegetación en la zona no es excesivamente densa, aunque sí bastante vieja.\n");
  AddDetail("bosque", "Estás en la zona este del bosque de Atbalnin. Aquí todo parece lúgubre y tenebroso.\n");
  SetIndoors(0);
}
