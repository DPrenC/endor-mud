#include "path.h"
inherit ATB_B("std_bosque");

create(){
  string w;
  ::create();

  switch (random(7)) {
    case 0: w="Est�s en una parte del bosque en el que la gran cantidad de "
	"vegetaci�n te hace bastante dif�cil el camino, ya que las ramas de "
	"los �rboles y de los arbustos se entrecruzan ante t�.\n";
	break;
    case 1: w="Est�s rodeado por una exhuberante vegetaci�n. Por el suelo "
    	"las ra�ces se entrecruzan como pueden, haciendo dif�cil el avance "
    	"en pr�cticamente todas las direcciones.\n";
    	break;
    case 2: w="Los grandes �rboles te rodean en todas las direcciones "
    	"posibles, dej�ndote alg�n que otro lugar libre por donde poder "
    	"colarte, no sin una cierta dificultad.\n";
    	break;
    case 3: w="Aunque no hay ninguna senda, hay ciertas zonas hacia las "
    	"que puedes avanzar a pesar de la salvaje y desordenada espesura "
    	"de la maleza.\n";
    	break;
    case 4: w="Ves �rboles hacia todas las direcciones a las que mires. "
    	"Todos estos �rboles son enormes, aunque por el color y la forma "
    	"parecen ser j�venes.\n";
    case 5: w="Ves el suelo recubierto de maleza y musgo. All� donde se "
    	"posen tus ojos ves vegetaci�n: �rboles, arbustos, hierba, zarzas, "
    	"matas, matojos... Desde luego un para�so para quien le guste la "
    	"naturaleza...\n";
    default: w="Este bosque es un claro ejemplo de lugar donde puedes "
    	"perderte con total facilidad, aunque las zonas a las que puedes "
    	"ir est�n bastante limitadas debido a la desmesurada vegetaci�n "
    	"que crece por la zona.\n";
  }

  SetIntLong(W(w));
  SetIntShort("la zona sur del bosque de Atbalnin");
  SetIntNoise("Escuchas el sonido de la naturaleza.\n");
  SetIntSmell("Huele a naturaleza.\n");
  SetLocate("bosque de Atbalnin");
  AddDetail(({"huella", "huellas"}), "Son las huellas de peque�os animales.\n");
  AddDetail(({"rama", "ramas", "arbusto", "arbustos"}), "Las ramas de los arbustos te impiden el paso en varias direcciones.\n");
  AddDetail(({"vegetacion", "vegetaci�n"}), "La vegetaci�n en la zona es muy densa, casi te impide el paso.\n");
  AddDetail("bosque", "Est�s en la zona sur del bosque de Atbalnin, la zona de una vegetaci�n m�s densa.\n");
  SetIndoors(0);
}
