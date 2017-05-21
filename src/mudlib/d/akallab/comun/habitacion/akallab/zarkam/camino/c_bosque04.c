/*
DESCRIPCION  : Camino desde el Sendero de los Cráneos hasta el bosque
FICHERO      : /d/akallab/comun/habitacion/akallab/zarkam/camino/c_bosque04.c
MODIFICACION : 10-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include <moving.h>


inherit ROOM;

//los PNJ no pasan
int ir_e()
 {
 if (TP->QueryIsPlayer()) return TP->move(Z_CAMINO("c_bosque05"),M_GO);
   return 1;
 }


create() {
  ::create();
  SetIntShort("el camino hacia el bosque");
  SetIntLong(
     "A medida que el camino se dirije hacia el bosque que queda al nordeste se va "
     "alejando poco a poco del río Kuneii que desciende hacia el Kusaii con el que "
     "se une lejos al sudeste cerca de los campos de cultivo. El bosque resulta mas "
     "inquietante cuanto mas que te acercas mas a el.\n");

  AddDetail(({"bosque", "bosque del este"}),
     "Desde aqui lo unico que ves es la entrada del sendero al bosque. Poco a poco "
     "una densa vegetacion absorbe el camino hasta perderse su rastro. Puedes ver que "
     "algunos de sus arboles que han crecido junto al camino presentan formas "
     "extranyas. Parece un aviso antes de adentrarte en el...\n");

  AddDetail(({"camino","senda"}),
     "Parece que no se tomaron muchas molestias en hacer esta senda, ya que solo es un "
     "camino de tierra mal marcado. Algo de vegetacion que ha crecido gracias a la "
     "humedad del río mejora algo la pobre imagen que presenta. Al este ves que el "
     "camino se pierde en un denso bosque.\n");

  AddDetail(({"río","Kuneii","kuneii", "Kusaii", "kusaii", "cauce"}),
     "Ves como el río Kuneii comienza a alejarse del camino a medida que gira su curso "
     "hacia el fondo del valle al sudeste, donde se unira con el río Kusaii. Mas "
     "adelante este río se precipita en las cataratas de Nurr que ya se adivinan desde "
     "aqui al cruzar las montanyas Negras.\n");

  AddDetail(({"montanyas","montanyas Negras"}),
     "Las montanyas Negras son la cordillera montanyosa que se cierra la salida "
     "natural del valle hacia el este. Estas montanyas separan este valle de los "
     "territorios orcos en la costa este de la peninsula de Aguliuk.\n");

 SetIntNoise("Oyes el suave susurrar del correr del agua del río.\n");
 SetIntSmell("Hmm..el aire es humedo y frio.\n");
 SetLocate("valle de Zarkam");
 SetIndoors(0);
 AddExit("este",SF(ir_e));
 AddExit("suroeste",Z_CAMINO("c_bosque03"));
}
