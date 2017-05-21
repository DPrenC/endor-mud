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
 "Esta pequeña plaza triangular de tierra batida es el centro del Pa de Raark. "
 "En su parte norte distingues la puerta que te permite cruzar la empalizada "
 "y salir al exterior. Al no haber mucho espacio habitable sobre este "
 "promontorio las casas de madera que se alzan alrededor de la plaza se "
 "aprientan unas contra otras.\n");

 AddDetail(({"casas"}),
"Alrededor de la plaza se alzan las casas de madera de los habitantes de este "
"Pa de Raark. Son construcciones estrechas y de dos plantas dada la escasez de "
"espacio habitable.\n");
  
 AddDetail(({"puerta"}),
"La puerta de la empalizada es ancha y esta reforzada con bandas de hierro. "
"Parece lo suficientemente fuerte como para bloquear un posible ataque el "
"tiempo necesario para que los defensores parapetados detrás de la "
"empalizada y aprovechando la ventaja de la altura eliminen a los atacantes.\n");

 AddExit("norte",MORHUGOK("puerta_1"));
 AddExit("oeste",MORHUGOK("plaza_1"));

}