/*
DESCRIPCION  : Camino desde el Sendero de los Cráneos hasta el bosque
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/c_bosque02.c
MODIFICACION : 27/11/97 Jotuna.
               15/03/98 [Angor@Simauria] Rehecha
               06-10-98 [Angor@Simauria] Varias modificaciones
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("un cruce en el camino del bosque");
  SetIntLong(
     "Has llegado a un cruce en el camino que conduce al bosque. El camino asciende "
     "lentamente hacia el oeste bordeando el río hasta cruzarse con el Sendero de los "
     "Cráneos. Aqui el camino se bifurca en dos, uno que sigue hacia el bosque al este "
     "y otro que, una vez cruzado el río Kuneii, desciende hacia los campos de cultivo "
     "que se hallan en el fondo del valle al sudeste. El aire sopla frio desde el sur.\n");

 AddDetail(({"bosque", "bosque del este"}),
     "Desde aqui lo unico que ves es la entrada del sendero al bosque. Poco a poco una "
     "densa vegetacion absorbe el camino hasta perderse su rastro. Puedes ver que "
     "algunos de los arboles que tienes formas extranyas e inquietantes. Parece un "
     "aviso antes de adentrarte en el...\n");

 AddDetail(({"camino","senda"}),
     "Parece que no se tomaron muchas molestias en hacer esta senda, ya que solo es un "
     "camino de tierra mal marcado. Algo de vegetacion que ha crecido gracias a la "
     "humedad del río hace mas mejora la triste imagen que presenta. Mucho mas al este "
     "ves que el camino se pierde en un denso bosque.\n");

  AddDetail(({"río","Kuneii","kuneii", "cauce"}),
     "Ves que el camino sigue el cauce del río Kuneii que continua hacia el este. Mas "
     "adelante se desvia al sur alejandose del bosque al que conduce esta senda, lo "
     "cual parece ser un mal presagio. Desde aqui puedes ver algunos peces que emergen "
     "a la superficie del río cerca de la orilla, como si la curiosidad les llevara a "
     "a seguir tus movimientos y saber lo que haces.\n");

 SetIntNoise("Oyes el suave susurrar del correr del agua del río.\n");
 SetIntSmell("Hmm..el aire es humedo y frio.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);
 AddExit("oeste",Z_CAMINO("c_bosque01"));
 AddExit("este",Z_CAMINO("c_bosque03"));
 AddExit("sudeste",Z_CAMINO("c_camp12"));
}