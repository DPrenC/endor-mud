// DESCRIPCION : playa
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "path.h"
#include AK_MACRO
inherit MORHUGOK("comun");

create(){
 if (::create()) return 1;
 SetIntShort("la playa de la bah�a de Morhugok");
 SetIntLong(
 "Los acantilados se van acercando a la orilla a medida que la playa se "
 "aproxima al promontorio que queda al sur donde acaba la bah�a. La vegetaci�n "
 "tropical de esta zona ha sido talada y no quedan arboles grandes, cosa que "
 "aprovechan los j�venes para crecer r�pido. Un sendero de tierra batida avanza "
 "en direcci�n a la pared de los acantilados al nordeste.\n");

 AddExit("norte",MORHUGOK("playa3"));
 AddExit("nordeste",MORHUGOK("bosque1"));
 AddExit("sur",MORHUGOK("playa5"));
 replace_program();
}