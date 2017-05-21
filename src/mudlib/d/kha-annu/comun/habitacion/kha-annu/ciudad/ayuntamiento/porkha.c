//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   porkha.c                          *
//* Archivo de: Gorthem, El forjador    *
//* Email: jorcama@euibbs.upv.es        *
//* Basado en --------.c                *
//* Creacion: 20.10.98                  *
//* Modificacion: 20.10.98              *
//* Agradecimientos: Angor y su portal  *
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*/

#include "./path.h"
inherit KHA_ROOM;

create() {
object portal;
 ::create();

 SetIntShort("el portal de Kha-annu");
 SetIntLong("Te encuentras en la sala del Portal de Kha-annu.\n"
 "Aqui es por donde los enanos llegan a Kha-annu venidos del mas alla por la "
 "gracia de los dioses que rigen nuestro mundo. Los muros son estan perfectamente\n"
 "tallados y llenos de grabados. Al este hay un arco que parece dar a un jardin.\n");

 SetIndoors(1);

 SetIntBright(40);
 SetIntNoise("No oyes nada en especial.\n");
 SetIntSmell("No ves hueles nada que merezca la pena.\n");

 AddDetail(({"muros"}),
 "Los muros estan llenos de grabados, unos sobre batallas enanas, otros sobre algo "
 "parecido a la Isla Limbo, y otros de dragones y criaturas extrañas.\n");
 AddExit("este",("ayun1"));
 portal=clone_object("/obj/monolito");
 portal->SetRaza(({"enano","gnomo"}));
 portal->move(TO);

}
