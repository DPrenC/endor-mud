#include "path.h"
inherit ATB_B("std_bosque");

create(){
  string w;
  ::create();

  switch (random(7)) {
    case 0: w="Estás en una parte del bosque en el que la gran cantidad de "
	"vegetación te hace bastante difícil el camino, ya que las ramas de "
	"los árboles y de los arbustos se entrecruzan ante tí.\n";
	break;
    case 1: w="Estás rodeado por una exhuberante vegetación. Por el suelo "
    	"las raíces se entrecruzan como pueden, haciendo difícil el avance "
    	"en prácticamente todas las direcciones.\n";
    	break;
    case 2: w="Los grandes árboles te rodean en todas las direcciones "
    	"posibles, dejándote algún que otro lugar libre por donde poder "
    	"colarte, no sin una cierta dificultad.\n";
    	break;
    case 3: w="Aunque no hay ninguna senda, hay ciertas zonas hacia las "
    	"que puedes avanzar a pesar de la salvaje y desordenada espesura "
    	"de la maleza.\n";
    	break;
    case 4: w="Ves árboles hacia todas las direcciones a las que mires. "
    	"Todos estos árboles son enormes, aunque por el color y la forma "
    	"parecen ser jóvenes.\n";
    case 5: w="Ves el suelo recubierto de maleza y musgo. Allí donde se "
    	"posen tus ojos ves vegetación: árboles, arbustos, hierba, zarzas, "
    	"matas, matojos... Desde luego un paraíso para quien le guste la "
    	"naturaleza...\n";
    default: w="Este bosque es un claro ejemplo de lugar donde puedes "
    	"perderte con total facilidad, aunque las zonas a las que puedes "
    	"ir están bastante limitadas debido a la desmesurada vegetación "
    	"que crece por la zona.\n";
  }

  SetIntLong(W(w));
  SetIntShort("la zona sur del bosque de Atbalnin");
  SetIntNoise("Escuchas el sonido de la naturaleza.\n");
  SetIntSmell("Huele a naturaleza.\n");
  SetLocate("bosque de Atbalnin");
  AddDetail(({"huella", "huellas"}), "Son las huellas de pequeños animales.\n");
  AddDetail(({"rama", "ramas", "arbusto", "arbustos"}), "Las ramas de los arbustos te impiden el paso en varias direcciones.\n");
  AddDetail(({"vegetacion", "vegetación"}), "La vegetación en la zona es muy densa, casi te impide el paso.\n");
  AddDetail("bosque", "Estás en la zona sur del bosque de Atbalnin, la zona de una vegetación más densa.\n");
  SetIndoors(0);
}
