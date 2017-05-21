/********************************************
*    Nombre: cueva04.c			    *
*    Localizacion: Cueva de los Trolls      *
*    Realizada por : Cajun, el ejecutor     *
*    Creado : 20-10-99                      *
*    Modificado:                            *
*********************************************/

#include "./path.h"
#include <properties.h>

inherit MARHCUEVA("cueva_base");

create () {
    ::create();
    SetLocate("cueva de los trolls");
    SetIntShort("una cueva maloliente");
    SetIntLong("Esta cueva se va haciendo m�s oscura conforme avanza hacia el oeste."
    " Notas un olor extra�o que no se ve de donde puede provenir.\n Las paredes "
    "contin�an muy h�medas.\n");
    SetIntSmell("Del fondo del pasillo emerge un pestilente olor a podrido.\n");
    AddDetail(({"humedad","agua","pared","paredes"}),
        "Los hongos en esta parte de la cueva son muy grandes.\n");
    AddExit("oeste", "./cueva05");
    AddExit("este", "./cueva03");
}
