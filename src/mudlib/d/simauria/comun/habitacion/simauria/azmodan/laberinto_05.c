/***********************************************************/
//	"laberinto_05"
//
//	Al oeste se sale se puede rastrear.
//	La salida se encuentra en esta habitaci�n
//	pero es aleatoriamente una de las cuatro
//	Kodex: Creaci�n y ultima modificaci�n 17-02-02
//



#include <skills.h>
#include "./path.h"
inherit STD_AZMODAN("laberinto");

rastrear_cmd()
{
	int perc;
	if (TP->QueryTP() < 2) return notify_fail("Est�s muy cansado para rastrear.\n"),0;
	perc = TP->UseSkill(HAB_RASTREAR);
	TP->AddTP(-2);
	if (perc < 0) return notify_fail("Rastreas minuciosamente pero no encuentras nada.\n"),0;
	else return write("Despues de rastrear te das cuenta de que esta habitaci�n tiene salida al exterior, pero no sabr�as precisar cual es.\n"),1;
}

create() {
::create();
AddExit("norte",LABERINTO_AZMODAN(2));
AddExit("sur",LABERINTO_AZMODAN(8));
AddExit("este",LABERINTO_AZMODAN(3));
AddExit("oeste",SF(Salir));
}

init()
{
::init();
add_action("rastrear_cmd","rastrear");	
}