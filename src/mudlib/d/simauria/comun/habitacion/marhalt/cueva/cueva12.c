/********************************************
*    Nombre: cueva12.c			    *
*    Localizacion: Cueva de los Trolls      *
*    Realizada por : Cajun, el ejecutor     *
*    Creado : 07-02-00                      *
*    Modificado:                            *
*********************************************/


#include "./path.h"
#include <properties.h>

inherit MARHCUEVA("cueva_base");


create () {
    ::create();
    SetIntShort("un lúgubre pasillo");
    SetIntLong("El túnel avanza hacia las profundidades, notándose la presión de la "
    "roca. Las paredes estan igual de mal excavadas que el resto de la cueva.\n En "
    "esta parte de la gruta alguna estalactita está más baja de lo normal.\n El "
    "pasillo continúa hacia el este y norte, mientras que al oeste se adentra en una "
    "mediana sala.\n");
    SetIntNoise("El eco de tus pasos resuenan por las paredes.\n");
    SetIntSmell("El aire es muy espeso y te cuesta respirar.\n");
    AddDetail(({"estalactita", "estalactitas"}),
        "Unas grandes rocas con forma puntiaguda penden del techo.\n");
    AddDetail(({"humedad","agua"}),
    "La humedad que cae por las paredes ayuda a que proliferen todo tipo de hongos.\n");
    AddExit("norte", "./cueva14");
    AddExit("este", "./cueva11");
    AddExit("oeste", "./cueva13");
}
