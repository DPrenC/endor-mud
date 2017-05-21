/*****************************************************************************
 AUTOR:		[t] Tyflos
 DETALLES:	Templo de Deiene
 *****************************************************************************/

#include "path.h"

inherit SIM_ROOM;

create() {
  ::create();

  SetIndoors(0);
  SetLocate("Templo de Deiene");
  SetIntShort("el altar de la diosa");
  SetIntLong(W("Est�s en la parte superior de la gran roca dedicada para ser "
  "el templo de la gran diosa Deiene. En el centro de esta especie de terraza "
  "natural hay una estatua de la diosa y a sus pies hay diversos huecos y "
  "superficies naturales destinadas a recoger los tributos y regalos hechos "
  "a la diosa. La escalinata de descenso est� hacia el norte. Hay un peque�o "
  "altar.\n"));
  SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
  SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
  AddDetail(({"altar"}),"El altar es un peque�o pedestal donde se sit�a la "
  "estatua de la diosa.\n");
  AddDetail(({"estatua","deiene","estatua de deiene","diosa"}),W("Es una "
  "estatua de casi dos metros de alto que toma la forma de una bella elfa "
  "de cabellos largos y dorados con semblante bondadoso. Parece desprender "
  "un aura m�gica de su interior y sus largos cabellos parecen tener la ilusi�n "
  "de ser mecidos por una eterna brisa. La estatua parece estar construida "
  "con diferentes pigmentos y maderas hasta conseguir que la diosa parezca "
  "viva. La diosa parece estar mirandote extendiendo su mano derecha hacia "
  "ti y su mano izquierda colocada en su pecho protegiendo algo.\n"));
  AddDetail(({"manos","mano","mano izquierda","mano de la estatua"}),W("Las "
  "manos de la estatua est�n magn�ficamente talladas, tanto que parecen vivas. "
  "La mano derecha, extendida hacia ti, parece invitarte a que te acerques a "
  "ella, y a la naturaleza, abandones este mundo de perversidad y que comiences "
  "la comuni�n con la naturaleza siguiendo el camino que han seguido los elfos "
  "de la luz. Su mano izquierda est� situada en su pecho, protegiendo de todo "
  "mal a una manzana dorada, s�mbolo del inicio de la comuni�n con la naturaleza.\n"));
  AddDetail(({"manzana","manzana dorada"}),"Es una manzana de aspecto m�gico "
  "y suculento. Est� protegida por la mano de la diosa.\n");
  AddExit("norte",ENALHAB"templo/escaleras5");
}
