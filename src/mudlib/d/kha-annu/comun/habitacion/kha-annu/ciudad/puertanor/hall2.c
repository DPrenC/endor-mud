//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   hall2.c                           *
//* Archivo de: Gorthem, El forjador    *
//* Email: jorcama@euibbs.upv.es        *
//* Basado en --------.c                *
//* Creacion: 01.08.98                  *
//* Modificacion: 03.12.98              *
//* Agradecimientos:                    *
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*/

#include "./path.h"

#define CARAVANA_KENTON "/d/kenton/comun/transporte/caravana/kenton/kenton"


inherit CARAVAN_STOP;
public create() {
 ::create();

 SetIntShort("el hall de Kha-annu. Parada de la caravana Khandor");
 SetIntLong(
 "Esta parte del hall donde paran la carvanas que llegan a la ciudad por la "
 "puerta norte. Puedes ver ahora con detalle los altos muros tallados y "
 "pulidos sobre la misma roca, asi como una tabla con la informacion sobre "
 "las caravanas que llegan o salen desde aqui.\n"
 "Al sur ves la entrada de una calle, al este esta la puerta principal de "
 "Kha-annu.\n"
 "En los muros hay unos grandes faroles que iluminan la gran estacia.\n");

 SetIndoors(1);
 SetIntBright(60);
 SetIntNoise("Oyes el bullicio tipico de la entrada de la ciudad.\n");
 SetIntSmell("Un monton de olores se mezclan en tu nariz.\n");

 AddDetail(({"calles","calle"}),
"Excavada en la roca ves al fondo una calle que se pierde en las profundidades "
"de la montanya.\n");

AddCaravana(KHANDOR("khandor"));
AddCaravana(CARAVANA_KENTON);

 AddExit("sur",("hall4"));
 AddExit("este",("hall1"));
 AddExit("sudeste",("hall5"));

 SetLocate("Kha-annu");

 }

