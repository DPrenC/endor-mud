// DESCRIPCION : puerta del Pa
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "path.h"
#include AK_MACRO
inherit MORHUGOK("comun");

create(){
 if (::create()) return 1;
 replace_program();
 SetIntShort("la plaza del Pa Raark de la bahía de Morhugok");
 SetIntLong(
 "La empalizada de este Pa se halla a tu lado y avanza hacia la puerta que "
 "observas al nordeste de aquí. Junto a ella en este extremo de la pequeña "
 "plaza triangular que es el centro del Pa de Raark, empiezan a crecer hierbas "
 "que muestran la voluntad ferrea de la vegetación tropical de reconquistar "
 "este lugar habitado que antes le perteneció. Altas y estrechas casas de "
 "madera rodean la plaza.\n");

 AddDetail(({"hierbas"}),
"Son pequeñas plantas tropicales como las que habitan en los acantilados.\n");

 AddDetail(({"casas"}),
"Alrededor de la plaza se alzan las casas de madera de los habitantes de este "
"Pa de Raark. Son construcciones estrechas y de dos plantas dada la escasez de "
"espacio habitable.\n");
 
 AddDetail(({"puerta"}),
"La puerta de la empalizada es ancha y esta reforzada con bandas de hierro. "
"Parece lo suficientemente fuerte como para bloquear un posible ataque el "
"tiempo necesario para que los defensores parapetados detrás de la "
"empalizada y aprovechando la ventaja de la altura eliminen a los atacantes.\n");

 AddExit("nordeste",MORHUGOK("puerta_1"));
 AddExit("este",MORHUGOK("plaza_2"));
}