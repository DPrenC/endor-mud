/********************************************
*    Nombre: cueva14.c			    *
*    Localizacion: Cueva de los Trolls      *
*    Realizada por : Cajun, el ejecutor     *
*    Creado : 09-02-00                      *
*    Modificado:                            *
*       03-03-04 Sorgin: Cambiada salida    *
*       norte de 13 a 12		    *
*********************************************/


#include "./path.h"
#include <properties.h>

inherit MARHCUEVA("cueva_base");


create () {
    ::create();
    SetIntShort("un l�gubre pasillo");
    SetIntLong("El t�nel avanza hacia las profundidades, las paredes y el suelo de "
    "la cueva estan mal excavadas, not�ndose aqu� que la roca es menos estable, y "
    "la superficie que pisas poco regular.\n Algunas estalactitas est�n algo m�s bajas "
    "de lo normal.\n");
    SetIntNoise("El eco de tus pasos resuenan por las paredes.\n");
    SetIntSmell("El aire es muy espeso y te cuesta respirar.\n");
    AddDetail(({"estalactitas","estalactita"}),
        "Unas grandes rocas con forma puntiaguda sobresalen del techo.\n");
    AddDetail(({"humedad","agua"}),
    "la humedad que cae por las paredes ayuda a que proliferen todo tipo de hongos.\n");
    AddExit("noroeste", "./cueva15");
    AddExit("sur", "./cueva12");
}
