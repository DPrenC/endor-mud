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
 "hacia el norte. Un pequeño bosque separa la playa de los altos "
 "acantilados que la rodean. Un imponente promontorio de roca se alza justo al "
 "sur. En sus paredes se ha tallado escalera que permite ascender al poblado "
 "con empalizada que ves en su cima.\n");
 
 AddDetail(({"escalera"}),
"La escalera se halla en parte tallada y en parte construida con toscos y "
"gastados bloques de piedra oscura. Los escalones son bastante pronunciados "
"y no tiene barandilla. Con la humedad tropical de este lugar, los resbalones "
"pueden ser peligrosos...\n");
  
 AddExit("oeste",MORHUGOK("escalera3"));
 AddExit("norte",MORHUGOK("playa4"));
 replace_program();
}