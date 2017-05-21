/***********************************************************/
//	"entrada_1"
//	Entrada a la mina
//	09-12-01 : Creación -> Kodex
//	09-12-01 : Modificación -> Kodex
//
//
#include "./path.h"
inherit SIM_ROOM;



create() {
::create();
SetIntShort("la entrada de la mina");
SetIntLong(W("Te encuentras en la entrada de la mina,"
" al sur ves el exterior y al norte sigue avanzando el"
" angosto pasillo rocoso. Esta mina fue abandonada hace "
"muchísimo tiempo, te preguntas quién tendrá interés "
"en explorarla ahora.\n"));
SetIndoors(1);
SetIntBright(25);
SetIntNoise("Oyes pequeñas rocas precipitandose.\n");
SetIntSmell("El aire es irrespirable.\n");
AddExit("norte",MINA_AZMODAN("entrada_2"));
AddExit("sur",VALLE_AZMODAN("valley_15"));
SetLocate("Entrada");
AddItem("/obj/torch",REFRESH_REMOVE,1);
AddItem(ARMA_AZMODAN("pico"),REFRESH_REMOVE,1);
}