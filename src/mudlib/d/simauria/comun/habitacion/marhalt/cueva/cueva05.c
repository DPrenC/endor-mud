/***********************************************************
*    Nombre: cueva05.c			                   *
*    Localizacion: Cueva de los Trolls                     *
*    Realizada por : Cajun, el ejecutor                    *
*    Creado : 20-10-99                                     *
*    Modificado: 18-04-00 -> A�adida la funci�n de saltar  *
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
		TP->move(MARH("cueva/cueva06"),M_SILENT);
	}
	return 1;
}

create () {
    ::create();
    SetIntShort("una cueva muy peque�a");
    SetIntLong("El pasillo de la cueva llega a lo que parece un lugar sin salida, "
    "las paredes parecen encojerse quit�ndote espacio. Aunque ese olor debe salir "
    "de alg�n lugar.\n");
    SetIntSmell("De algun lugaro del pasillo emerge un pestilente olor a podrido.\n");
    AddDetail(({"humedad","agua"}),
        "Los hongos en esta parte de la cueva son muy grandes.\n");
    AddDetail(({"pared","paredes","cueva","pasillo"}),
        "Te das cuenta que hay un agujero muy peque�o en el suelo y un hueco m�s "
        "grande en el techo.\n");
    AddDetail("agujero","El agujero es tan peque�o que si no te agachas no podr�s pasar.\n");
    AddDetail(({"hueco","techo"}),"El hueco en el techo est� muy alto, tal vez saltando "
        "lo alcanzar�s.\n");
    AddExit("agacharse", "./cueva06");
    AddExit("este", "./cueva04");
    AddExit("saltar",SF(saltar));
    SetExitSize("agacharse",P_SIZE_SMALL);
    HideExit("agacharse",1);
    HideExit("saltar",1);
    AddItem(PNJ("marhalt/cueva/troll"), REFRESH_DESTRUCT, d3());
}
