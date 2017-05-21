/*
DESCRIPCION  : Camino al norte de los campos de cultivo
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/c_camp12.c
MODIFICACION : 11/02/98 Klauss
               15/03/98 [Angor@Simauria] Rehecha
               06-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el puente que cruza el río Kuneii");
  SetIntLong(
     "En este punto el camino que lleva a los campos de cultivo cruza el río Kuneii. "
     "Los orcos han contruido el puente que permite cruzar el río y sobre el que te "
     "hallas. El puente es bajo, pero ancho y macizo, pues por el deben pasar los "
     "carros cargados con las cosechas de los campos de cultivo que ves al sudeste del "
     "valle. Observas que en el norte de los campos hay una pequenya cabanya.\n");

  AddDetail (({"puente"}),
     "Es un bajo puente de madera que cruza sobre el río Kuneii. Esta construido "
     "con gruesos troncos de madera traidos del bosque del nordeste del valle. Por "
     "a su aspecto desvencijado, dirias que este ancho y macizo puente ha sido muy "
     "transitado a lo largo de los anyos.\n");

  AddDetail(({"cabanya","gran cabanya","establo"}),
     "Los orcos suelen utilizar esclavos para cultivar sus tierras, por lo que supones "
     "que la construccion que ves al norte de los campos debe ser el lugar donde los "
     "orcos mantienen a estos esclavos cuando no estan trabajando.\n");

  AddDetail (({"río","Kuneii","kuneii","cauce"}),
     "El río continua su curso hacia el este suavemente. A ambos lados de la orilla "
     "crece una escasa vegetacion que alegra algo el paisaje. Desde tu elevada "
     "posicion ves algunos peces en el río. ¡Este seria un buen lugar para pescar!\n");

  AddDetail(({"tierras de cultivo","campos","cultivos","campos de cultivo"}),
     "Los orcos emplean sus prisioneros de guerra para que trabajen sus tierras. Esto "
     "no significa que los orcos sean malos agricultores, simplemente ocurre que "
     "debido a su mentalidad guerrera necesitan el mayor numero de hombres para sus "
     "batallas. No es de extranyar que alli te encuentres prisioneros de distintas "
     "razas, posiblemente enemigos entre si, pero con una similitud... el enemigo "
     "comun que los mantiene como esclavos.\n");

  SetIntNoise("Oyes el suave susurro del correr del agua del río.\n");
  SetIntSmell("Hmm.. hueles el frescor de la hierba fresca.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("sudeste",Z_CAMINO("c_camp11"));
  AddExit("noroeste",Z_CAMINO("c_bosque02"));
}

