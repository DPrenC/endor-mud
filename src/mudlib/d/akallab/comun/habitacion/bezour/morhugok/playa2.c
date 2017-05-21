// DESCRIPCION : playa
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "path.h"
#include AK_MACRO
inherit MORHUGOK("comun");

create(){
 if (::create()) return 1;
 SetIntShort("la playa de la bahía de Morhugok");
 SetIntLong(
 "En este lugar de la playa desemboca el arroyo creado por la alta y ruidosa "
 "cascada que cae de los acantilados que ves al nordeste por encima de las "
 "copas de los arboles del bosque. La vegetación del bosque es muy densa y "
 "tropical pero un sendero de tierra batida se abre espacio en ella y parte "
 "de aquí corriendo junto al arroyo.\n");

 AddDetail(({"arroyo"}),
"El arroyo avanza ruidoso entre las piedras. Se puede cruzar fácilmente.\n");

 SetIntNoise("El arroyo avanza ruidoso entre las piedras.\n");

 //AddExit("nordeste",MORHUGOK("arroyo"));
 AddExit("oeste",MORHUGOK("playa1"));
 AddExit("sudeste",MORHUGOK("playa3"));
 replace_program();
}