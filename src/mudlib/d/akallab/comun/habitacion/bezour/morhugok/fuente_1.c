// DESCRIPCION : puerta del Pa
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "path.h"
#include AK_MACRO
inherit MORHUGOK("comun");

create(){
 if (::create()) return 1;
 replace_program();
 SetIntShort("una peque�a fuente en el Pa Raark de la bah�a de Morhugok");
 SetIntLong(
 "Esta parte del Pa est� adosada a los altos acantilados cubiertos de "
 "vegetaci�n tropical de la bah�a. Por lo que puedes ver, los habitantes "
 "locales han desviado el agua de una peque�a cascada que queda al este "
 "por medio de un canal�n de planchas de madera hasta aqu� donde una pileta "
 "la recoge.\n");
  
AddDetail(({"canalon","canal�n"}),
"El canal�n es una estructura de madera muy b�sica que sirve para llevar agua "
"de un sitio a otro. Esta formado por tablones planos y alargados de madera "
"montadas en forma de V montados sobre anclajes a la ladera del acantilado.\n");
  
 AddItem(OTRO("fuente"), REFRESH_DESTRUCT, 1);   
 AddExit("oeste",MORHUGOK("puerta_1"));
}
