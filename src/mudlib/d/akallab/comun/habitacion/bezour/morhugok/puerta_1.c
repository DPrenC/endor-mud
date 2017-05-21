// DESCRIPCION : puerta del Pa
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "path.h"
#include AK_MACRO
inherit MORHUGOK("comun");

create(){
 if (::create()) return 1;
 replace_program();
 SetIntShort("la puerta del Pa Raark de la bah�a de Morhugok");
 SetIntLong(
 "Te hallas bajo el arco de la �nica puerta que da acceso al Pa de Raark a "
 "trav�s de la empalizada. Calculas que dado el aspecto robusto de la "
 "y el caracter del terreno, atacar el Pa no debe ser f�cil. Al exterior, "
 "una escalera desciende desde la puerta hacia la costa y al interior al "
 "sur se abre una peque�a plaza.\n");
  
 AddDetail(({"escalera"}), this_object()->QueryIntLong() );
 AddDetail(({"plaza"}), "Est� al sur de aqu�.\n" );  
  
 AddDetail(({"puerta"}),
"La puerta de la empalizada es ancha y esta reforzada con bandas de hierro. "
"Parece lo suficientemente fuerte como para bloquear un posible ataque el "
"tiempo necesario para que los defensores parapetados detr�s de la "
"empalizada y aprovechando la ventaja de la altura eliminen a los atacantes.\n");

 AddExit("oeste",MORHUGOK("escalera4"));
 AddExit("este",MORHUGOK("fuente_1"));
 AddExit("sur",MORHUGOK("plaza_2"));
 AddExit("suroeste",MORHUGOK("plaza_1"));
}