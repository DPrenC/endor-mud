// DESCRIPCION : playa
// MODIFICACION: 26-05-2008 [Angor] Creacion

#include "path.h"
#include AK_MACRO
inherit MORHUGOK("comun");

create(){
 if (::create()) return 1;
 SetIntShort("la playa de la bahía de Morhugok");
 SetIntLong(
 "Aquí comienza la playa de la pequeña bahía de Morhugok que se extiende "
 "hacia el este. Una escalera tallada en la roca del gran promontorio de "
 "roca que se alza al oeste parte frente a tí y parece permitir el ascenso al "
 "poblado con una empalizada que ves en su cima. Un pequeño bosque al norte "
 "separa la playa de los altos acantilados.\n");

 AddDetail(({"escalera"}),
"La escalera se halla en parte tallada y en parte construida con toscos y "
"gastados bloques de piedra oscura. Los escalones son bastante pronunciados "
"y no tiene barandilla. Con la humedad tropical de este lugar, los resbalones "
"pueden ser peligrosos...\n");
  
 //AddExit("suroeste",MORHUGOK("escalera0"));
 AddExit("este",MORHUGOK("playa1"));
 replace_program();
}