// DESCRIPCION : playa
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "path.h"
#include AK_MACRO
inherit MORHUGOK("comun");

create(){
 if (::create()) return 1;
 SetIntShort("la playa de la bahía de Morhugok");
 SetIntLong(
 "La playa gira aquí lentamente hacia el sur camino de un gran promontorio "
 "rocoso donde acaba esta bahía de Morhugok. La arena húmeda que se hunde bajo "
 "tus pies esta llena de todo tipo de conchas arrastradas por el mar. El "
 "bosque tropical llega aquí muy cerca del mar estrechando la playa de arena.\n");

AddDetail(({"concha","conchas"}),
"Esta parte de la playa esta llena de pequeñas conchas arrastradas por el oleaje.\n");

 AddExit("sur",MORHUGOK("playa4"));
 AddExit("noroeste",MORHUGOK("playa2"));
 AddItem(OTRO("concha"), REFRESH_DESTRUCT, 3); 
}