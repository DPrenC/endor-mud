//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*
//*   hall2.c                           *
//* Archivo de: Gorthem, El forjador    *
//* Email: jorcama@euibbs.upv.es        *
//* Basado en --------.c                *
//* Creacion: 01.08.98                  *
//* Modificacion: 03.12.98              *
//* Anyado la caravana de Lad Laurelin  *
//* Agradecimientos:                    *
//*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*/

#include "./path.h"
inherit CARAVAN_STOP;

create() {
 ::create();

 SetIntShort("la parada de la caravana Khandor");
 SetIntLong(
 "Estas en el camino que une el pueblo pesquero de gorat con el puerto "
 "aqui tienes una parada de caravanas, concretamente la caravana Khandor "
 "para cualquier informacion mira la tabla\n");
 SetIndoors(0);
 SetIntNoise("Oyes el bullicio tipico de un puerto.\n");
 SetIntSmell("Un monton de olores se mezclan en tu nariz.\n");

 AddCaravana("/d/kha-annu/comun/transportes/caravana/khandor/khandor");
 AddCaravana("/d/lad-laurelin/comun/objeto/otro/caravana");

 AddExit("norte","/d/simauria/comun/habitacion/caminos/nandor-simauria/puerto");
 SetLocate("Gorat");

}