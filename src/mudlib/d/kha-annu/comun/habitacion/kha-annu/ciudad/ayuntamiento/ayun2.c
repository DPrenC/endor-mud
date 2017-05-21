//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   ayun2.c                           *
//* Archivo de: Gorthem, El forjador    *
//* Email: jorcama@euibbs.upv.es        *
//* Basado en --------.c                *
//* Creacion: 20.10.98                  *
//* Modificacion: 20.10.98              *
//* Agradecimientos:                    *
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*/

#include "./path.h"
inherit KHA_ROOM;
create() {
 ::create();

 SetIntShort("la sala de información para la comunidad de Kha-annu");
 SetIntLong("Esta es la sala de informacion para Kha-annu, aqui es donde los enanos "
 "dejan información en el panel que hay en la pared. Comparte con tus hermanos tus "
 "conocimientos y aprende de ellos.\n");
 SetIndoors(1);
 SetIntBright(50);
 SetIntNoise("Oyes el repiqueo del agua hay fuera.\n");
 SetIntSmell("Todavia huele a flores.\n");

 AddExit("oeste",("ayun1"));

 }
