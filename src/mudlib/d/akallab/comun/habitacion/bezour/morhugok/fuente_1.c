// DESCRIPCION : puerta del Pa
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "path.h"
#include AK_MACRO
inherit MORHUGOK("comun");

create(){
 if (::create()) return 1;
 replace_program();
 SetIntShort("una pequeña fuente en el Pa Raark de la bahía de Morhugok");
 SetIntLong(
 "Esta parte del Pa está adosada a los altos acantilados cubiertos de "
 "vegetación tropical de la bahía. Por lo que puedes ver, los habitantes "
 "locales han desviado el agua de una pequeña cascada que queda al este "
 "por medio de un canalón de planchas de madera hasta aquí donde una pileta "
 "la recoge.\n");
  
AddDetail(({"canalon","canalón"}),
"El canalón es una estructura de madera muy básica que sirve para llevar agua "
"de un sitio a otro. Esta formado por tablones planos y alargados de madera "
"montadas en forma de V montados sobre anclajes a la ladera del acantilado.\n");
  
 AddItem(OTRO("fuente"), REFRESH_DESTRUCT, 1);   
 AddExit("oeste",MORHUGOK("puerta_1"));
}
