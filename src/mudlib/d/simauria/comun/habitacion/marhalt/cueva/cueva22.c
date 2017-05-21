/********************************************
*    Nombre: cueva22.c			    *
*    Localizacion: Cueva de los Trolls      *
*    Realizada por : Cajun, el ejecutor     *
*    Creado : 09-02-00                      *
*    Modificado:                            *
*********************************************/


#include "./path.h"
#include <properties.h>

inherit MARHCUEVA("cueva_base");


create () {
    ::create();
    SetIntShort("un derrumbe");
    SetIntLong("Cuando llegas al final del pasillo te das cuenta que "
        "ha sido bloqueado por un derrumbe hace algunos siglos . No te parece que pueda haber "
        "ninguna salida por aquí.\n");
    SetIntNoise("Se escucha un silencio incómodo.\n");
    SetIntSmell("El aire es muy espeso y te cuesta respirar.\n");
    AddDetail("derrumbe", "Un montón de rocas bloquean el estrecho pasillo.\n");
    AddExit("este", "./cueva21");
}
