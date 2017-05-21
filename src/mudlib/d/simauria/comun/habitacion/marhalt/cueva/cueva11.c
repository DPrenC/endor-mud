/********************************************
*    Nombre: cueva11.c			    *
*    Localizacion: Cueva de los Trolls      *
*    Realizada por : Cajun, el ejecutor     *
*    Creado : 12-01-00                      *
*    Modificado:                            *
*********************************************/


#include "path.h"
#include <properties.h>

inherit MARHCUEVA("cueva_base");


create () {
    ::create();
    SetIntShort("un lúgubre pasillo");
    SetIntLong("El túnel avanza hacia las profundidades, las paredes de la cueva están "
    "tan mal excavadas como el resto de la gruta.\n En esta zona las estalactitas "
    "parecen estar más bajas de lo normal y la humedad te sigue acompañando.\n");
    SetIntNoise("El eco de tus pasos resuenan por las paredes.\n");
    SetIntSmell("El aire es muy espeso y te cuesta respirar.\n");
    AddDetail(({"estalactitas","estalactita"}),
        "Unas grandes rocas con forma puntiaguda penden del techo.\n");
    AddDetail(({"humedad","agua"}),
        "La humedad que cae por las paredes ayuda a que proliferen todo tipo de hongos.\n");
    AddExit("este", "./cueva09");
    AddExit("oeste", "./cueva12");
}
