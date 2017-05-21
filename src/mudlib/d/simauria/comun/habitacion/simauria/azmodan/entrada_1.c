/***********************************************************/
//	"entrada_1"
//	Entrada a la mina
//	09-12-01 : Creaci�n -> Kodex
//	09-12-01 : Modificaci�n -> Kodex
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
"much�simo tiempo, te preguntas qui�n tendr� inter�s "
"en explorarla ahora.\n"));
SetIndoors(1);
SetIntBright(25);
SetIntNoise("Oyes peque�as rocas precipitandose.\n");
SetIntSmell("El aire es irrespirable.\n");
AddExit("norte",MINA_AZMODAN("entrada_2"));
AddExit("sur",VALLE_AZMODAN("valley_15"));
SetLocate("Entrada");
AddItem("/obj/torch",REFRESH_REMOVE,1);
AddItem(ARMA_AZMODAN("pico"),REFRESH_REMOVE,1);
}