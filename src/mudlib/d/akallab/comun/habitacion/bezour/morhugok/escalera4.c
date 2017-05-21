// DESCRIPCION : escalera al promontorio
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "path.h"
#include AK_MACRO
inherit MORHUGOK("comun");

create(){
 if (::create()) return 1;
 replace_program();
 SetIntShort("la escalera a un promontorio de la bahía de Morhugok");
 SetIntLong(
 "En este lugar la escalera gira bruscamente alejándose de la costa y se "
 "vuelve aun mas empinada antes de llegar a la puerta de la empalizada que "
 "queda al este. Esta puerta da acceso al Pa de Raark y es su único acceso. "
 "La exuberante vegetación tropical invade esta zona de la escalera y hace "
 "que casi parezca un tunel.\n");
  
 AddDetail(({"escalera"}), this_object()->QueryIntLong() );
  
 AddDetail(({"puerta"}),
"La puerta de la empalizada es ancha y esta reforzada con bandas de hierro. "
"Parece lo suficientemente fuerte como para bloquear un posible ataque el "
"tiempo necesario para que los defensores parapetados detrás de la "
"empalizada y aprovechando la ventaja de la altura eliminen a los atacantes.\n");

 AddExit("nordeste",MORHUGOK("escalera3"));
 AddExit("este",MORHUGOK("puerta_1"));
}