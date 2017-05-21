/*
DESCRIPCION : Camino de la mina.
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/camino/c_mina05.c
MODIFICACION: 05-03-98 [Angor@Simauria] Creacion
              06-10-98 [Angor@Simauria] Varias modificaciones
	      07-11-01 [nemesis@simauria] Añadida una salida al santuario
	               para el quest del Cáliz de Valevissa
		       Ya que estaba, castellanizado...
		       Comentada la salida al santuario: cuando esté el quest,
		       se descomenta y listo...
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
 ::create();
 SetIntShort("el cruce del río Kuneii y el camino de la mina");
 SetIntLong(
     "El camino de la mina es atravesado aquí por el arroyo que más tarde será el río "
     "Kuneii. Entre el arroyo y la tierra removida por los carromatos de mineral que "
     "suelen bajar por el camino han formado un buen barrizal. Observas que los orcos "
     "han canalizado parte de las aguas del arroyo por unos canalones y las conducen "
     "al noroeste de aquí donde se halla el lavadero de mineral. Al oeste te llama la "
     "atención un curioso arco que da a una cueva que no parece una mina.\n");

  AddDetail(({"canalones","lavadero","planchas"}),
     "Al noroeste de aquí se halla el lavadero de mineral de la mina. Los orcos han "
     "construído unos canalones con planchas de madera a modo de acueducto que llevan "
     "parte del agua del río Kuneii, recogida en un salto de agua al sur, hasta allí.\n");

  AddDetail(({"montanya","montanyas","Shojuna","shojuna","montaña","montañas"}),
     "Al oeste del valle se hallan las montanyas de Shojuna. Estas altas montañas "
     "aislan al valle de Zarkam de los territorios costeros del oeste de la península "
     "de Aguliuk, ya que no existe un paso en condiciones para poder cruzarlas. Los "
     "orcos han excavado algunas minas en ellas.\n");

  AddDetail(({"mineral","huellas","carromatos","huellas de carromatos"}),
     "Por este camino se baja en carromatos el mineral extraído de la mina hacia la "
     "forja que hay en la herreria de Zarkam. El mineral es pesado y las carromatos "
     "cargados dejan por ello claras huellas de su paso en el camino.\n");

  AddDetail(({"arroyo","río","río Kuneii","Kuneii","kuneii","río"}),
     "El río Kuneii serpentea a traves del valle de Zarkam. Sus aguas son frías y algo "
     "turbias. En esta zona, es más bien un arroyo que corre entre peñas que un río "
     "propiamente dicho.\n");

  AddDetail(({"arco","curioso arco"}),
  "Es un arco esculpido en la roca rodeando la entrada a una cueva. "
  "Es todo lo contrario a lo que esperarías encontrar en la entrada a una mina.\n");

  AddDetail(({"cueva","entrada","entrada a cueva"}),
  "A juzgar por la anchura de esa entrada, la cueva tiene que ser muy espaciosa.\n");

  SetIntNoise("El ruido de los rápidos es bastante fuerte y no te deja oír nada más.\n");
  SetIntSmell("El aire es muy húmedo y huele a fango.\n");
  SetLocate("valle de Zarkam");
  SetIndoors(0);
  AddExit("noroeste",Z_CAMINO("c_mina06"));
  //AddExit("oeste", Z_MINAS("nivel0/santuario"));
  AddExit("este",Z_CAMINO("c_mina04"));
}
