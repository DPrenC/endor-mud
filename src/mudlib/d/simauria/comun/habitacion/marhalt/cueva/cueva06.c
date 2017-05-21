/***********************************************************
*    Nombre: cueva06.c			                   *
*    Localizacion: Cueva de los Trolls                     *
*    Realizada por : Cajun, el ejecutor                    *
*    Creado : 19-10-99                                     *
*    Modificado: 24-11-99 -> Añadir monstruo carroñero     *
*                18-04-00 -> Añadida la función saltar     *
************************************************************/


#include "./path.h"
#include <moving.h>
#include <properties.h>

inherit MARHCUEVA("cueva_base");


int saltar(){
	if (TP->QuerySize() < 3) {
		write("Por mucho que saltas eres incapaz de alcanzar el hueco.\n");
	}else{
		write ("Das un gran salto y te coges del saliente. Poco a poco te aupas y "
		"consigues colarte por el hueco.\n");
		say (TP->QueryName()+" salta y se cuela por un hueco en el techo.\n");
		TP->move(MARH("cueva/cueva05"),M_SILENT);
	}
	return 1;
}


create () {
    ::create();
    SetIntShort("un basurero pestilente");
    SetIntLong("Escondido en la gruta se encuentra esta asquerosa sala circular llena "
    "de restos de comida y cuerpos en descomposición.\n El aspecto es horrible y "
    "el olor insoportable como para producir arcadas a cualquier raza civilizada.\n");

  SetIntSmell("Un olor fuerte a podrido se cuela por tu nariz y te produce arcadas.\n");
    AddDetail(({"pared","paredes","cueva","sala"}),
        "Te das cuenta que hay un agujero algo pequeño en el suelo y un hueco más "
        "grande en el techo.\n");
    AddDetail("agujero","El agujero es tan pequeño que si no te agachas no podrás pasar.\n");
    AddDetail(({"hueco","techo"}),"El hueco en el techo está muy alto tal vez saltando "
    "lo alcanzarás.\n");
    AddItem(PNJ("marhalt/cueva/carronyero"),REFRESH_DESTRUCT,d3());
    AddExit("agacharse", "./cueva05");
    SetExitSize("agacharse",P_SIZE_SMALL);
    AddExit("saltar",SF(saltar));
    HideExit ("agacharse",1);
    HideExit ("saltar",1);
    SetExplorable(1);
}
