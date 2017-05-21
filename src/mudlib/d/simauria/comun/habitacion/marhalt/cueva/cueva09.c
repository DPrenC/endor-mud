/********************************************
*    Nombre: cueva09.c			    *
*    Localizacion: Cueva de los Trolls      *
*    Realizada por : Cajun, el ejecutor     *
*    Creado : 20-12-99                      *
*    Modificado:                            *
*********************************************/


#include "./path.h"
#include <properties.h>

inherit MARHCUEVA("cueva_base");


create () {
    ::create();
    SetIntShort("un cruce de túneles");
    SetIntLong("El túnel llega al final de este tramo donde hay un cruce. El ambiente "
    "comienza a ser muy pesado, debido al fuerte olor mezclado con un alto nivel de "
    "humedad.\n Tanto las paredes como suelos son aquí algo más habitables, aunque no "
    "dejan de estar irregulares.\n");
    SetIntSmell("El aire lleva mucho tiempo sin ser renovado y te cuesta respirar.\n");
    AddDetail(({"humedad","agua"}), "La humedad que cae por las paredes ayuda "
        "a que proliferen todo tipo de hongos.\n");
    AddExit("sudeste", "./cueva08");
    AddExit("este", "./cueva10");
    AddExit("oeste", "./cueva11");
}
