//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   hall2.c                           *
//* Archivo de: Gorthem, El forjador    *
//* Email: jorcama@euibbs.upv.es        *
//* Basado en --------.c                *
//* Creacion: 01.08.98                  *
//* Modificacion: 01.08.98              *
//* Agradecimientos:                    *
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*/

#include "./path.h"
inherit KHA_ROOM;
create() {
 ::create();

 SetIntShort("el hall de Kha-annu");
 SetIntLong(
 "Esta parte del hall esta menos habitada. Puedes ver ahora con detalle "
 "los altos muros tallados y pulidos sobre la misma roca. Al norte ves "
 "la entrada de una calle, al este esta la puerta principal de Kha-annu.\n"
 "En los muros hay unos grandes faroles que iluminan la gran estacia.\n");
 SetIndoors(1);
 SetIntBright(60);
 SetIntNoise("Oyes el bullicio tipico de la entrada de la ciudad.\n");
 SetIntSmell("Un monton de olores se mezclan en tu nariz.\n");

 AddDetail(({"calles","calle"}),
"Excavada en la roca ves al fondo una calle que se pierde en las profundidades "
"de la montanya.\n");

 AddExit("norte",("hall4"));
 AddExit("este",("hall1"));
 AddExit("nordeste",("hall5"));
 SetLocate("Kha-annu");
 }

