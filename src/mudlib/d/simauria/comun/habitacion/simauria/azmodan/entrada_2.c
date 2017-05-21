/***********************************************************/
//	"entrada_2"
//	Entrada a la mina, avisa si es de noche
//	09-12-01 : Creaci�n -> Kodex
//	09-12-01 : Modificaci�n -> Kodex
//
//
#include <nightday.h>
#include <colours.h>
#include "./path.h"
inherit SIM_ROOM;


create() {
::create();
SetIntShort("la entrada de la mina");
SetIntLong(W("El interior de la mina es bastante oscuro"
" aunque hay peque�os focos de luz que no sabes de donde "
"vienen e iluminan un poco el camino, desde aqu� puedes "
"ver unas rudimentarias escaleras excavadas en la roca que "
"llevan hacia un piso inferior en la mina. No dan seguridad, "
"adem�s nadie sabe lo que podr�as encontrarte si bajaras por ah�.\n"));
SetIndoors(1);
SetIntBright(25);
SetIntNoise("Oyes peque�as rocas precipitandose.\n");
SetIntSmell("El aire es irrespirable.\n");
AddExit("abajo",MINA_AZMODAN("mina_1-01"));
AddExit("sur",MINA_AZMODAN("entrada_1"));
SetLocate("Entrada");
}

aviso()
{
tell_object(TP,TC_RED+"Oyes aullidos que provienen"
" de pisos inferiores...\nLos moradores de la mina est�n revueltos.\n"+TC_NORMAL);
}

init()
{
 mixed nd;
  ::init();
        nd = (mixed *)NIGHTDAY->QueryState();
        if (nd == ND_NIGHT || nd == ND_PREDAWN || nd == ND_FALL || nd == ND_PRENIGHT)
       call_out("aviso",1);
}