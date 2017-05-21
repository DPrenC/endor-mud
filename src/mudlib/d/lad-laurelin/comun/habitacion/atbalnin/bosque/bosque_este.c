#include "path.h"
inherit ATB_B("std_bosque");

create(){
  string w;
  SetNoAnimals(1);
  ::create();

  switch (random(7)) {
    case 0: w="Esta parte del bosque parece tener miles de a�os. Los �rboles "
    	"son realmente enormes, y el aspecto que dan es bastante l�gubre, "
    	"incluso amenazador. Quiz�s sea por eso por lo que han resistido tanto "
    	"tiempo, por que pr�cticamente nadie se aventura por aqui, y quien lo "
    	"hace cuenta extra�as historias...\n";
	break;
    case 1: w="Est�s rodeado por lo que podr�an ser los abuelos de los �rboles "
    	"del resto del mundo. Siglos y siglos han vivido en relativa paz. Aunque "
    	"han sido escenario de batallas e invasiones, siempre han sido "
    	"respetados por los ej�rcitos, ya sea por respeto o por miedo.\n";
    	break;
    case 2: w="All� donde mires ver�s �rboles grandes, oscuros y retorcidos. "
    	"Estos �rboles confieren al bosque un aspecto oscuro, l�gubre... "
    	"seguramente la zona est� plagada de seres peligrosos y agresivos, "
    	"con los que seguramente es mejor no meterse.\n";
    	break;
    case 3: w="Ves el suelo recubierto de unos matojos de hierba que "
    	"seguramente no han sido excesivamente pisados por los habitantes de "
    	"los alrededores. Ni siquiera los lobos suelen atreverse a "
    	"adentrarse en esta zona.\n";
    	break;
    case 4: w="El suelo est� salpicado de ra�ces de todos los �rboles que "
    	"crecen a tu alrededor. Seguramente ser�n las ra�ces m�s largas "
    	"de toda la zona, teniendo en cuenta el tiempo que llevan aqu�. "
    	"Un escalofr�o recorre tu cuerpo y piensas que ser�a m�s sensato "
    	"ir a un lugar m�s apacible.\n";
    case 5: w="Todo a tu alrededor parece hostil; los �rboles que parecen "
    	"mirarte, las sombras que parecen moverse, alg�n crujido de alguna "
    	"rama, el silencio que reina en la zona debido a los pocos animales "
    	"que por aqu� habitan...\n";
    default: w="Desde luego no ser�a excesivamente tranquilizador el "
    	"perderse por aqu�. �Qui�n sabe los peligros que pueden acecharte "
    	"en este milenario bosque!\n";
  }

  SetIntLong(W(w));
  SetIntShort("la zona sur del bosque de Atbalnin");
  SetIntNoise("Escuchas el sonido de la naturaleza.\n");
  SetIntSmell("Huele a naturaleza.\n");
  SetLocate("bosque de Atbalnin");
  AddDetail(({"huella", "huellas"}), "Son las huellas algo grande que camina arrastr�ndose.\n");
  AddDetail(({"rama", "ramas", "arbusto", "arbustos"}), "Las ramas de los arbustos te impiden el paso en varias direcciones.\n");
  AddDetail(({"vegetacion", "vegetaci�n"}), "La vegetaci�n en la zona no es excesivamente densa, aunque s� bastante vieja.\n");
  AddDetail("bosque", "Est�s en la zona este del bosque de Atbalnin. Aqu� todo parece l�gubre y tenebroso.\n");
  SetIndoors(0);
}
