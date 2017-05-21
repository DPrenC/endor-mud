// DESCRIPCION : playa
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "path.h"
#include AK_MACRO
inherit MORHUGOK("comun");

create(){
 if (::create()) return 1;
 SetIntShort("la playa de la bah�a de Morhugok");
 SetIntLong(
 "La playa gira aqu� lentamente hacia el sur camino de un gran promontorio "
 "rocoso donde acaba esta bah�a de Morhugok. La arena h�meda que se hunde bajo "
 "tus pies esta llena de todo tipo de conchas arrastradas por el mar. El "
 "bosque tropical llega aqu� muy cerca del mar estrechando la playa de arena.\n");

AddDetail(({"concha","conchas"}),
"Esta parte de la playa esta llena de peque�as conchas arrastradas por el oleaje.\n");

 AddExit("sur",MORHUGOK("playa4"));
 AddExit("noroeste",MORHUGOK("playa2"));
 AddItem(OTRO("concha"), REFRESH_DESTRUCT, 3); 
}