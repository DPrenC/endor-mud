/********************************************
*    Nombre: cueva18.c			    *
*    Localizacion: Cueva de los Trolls      *
*    Realizada por : Cajun, el ejecutor     *
*    Creado : 09-02-00                      *
*    Modificado:                            *
*********************************************/


#include "./path.h"
#include <properties.h>
inherit MARHCUEVA("cueva_base");

create()
{
    ::create();
    SetIntShort("una gran sala");
    SetIntLong("Esta �mplia sala est� sorprendentemente bien excavada, las paredes "
    "est�n lisas y pulidas, al igual que el suelo y el alto techo.\n Una enorme "
    "columna blanca preside el centro de la estancia circular , que se estiende en "
    "distintas direcciones.\n  La temperatura aqu� ha bajado varios grados, por lo que "
    "se siente un fr�o poco natural.\n");
    SetIntNoise("El eco de tus pasos resuenan por las pulidas paredes.\n");
    SetIntSmell("El aire es muy espeso y te cuesta respirar.\n");
    AddDetail(({"columna", "columna blanca", "pilar"}),"Es una enorme columna de fr�o"
    " m�rmol que preside el centro de esta sala circular.\n");
    AddExit("este", "./cueva17");
    AddExit("oeste", "./cueva19");
    AddExit("norte", "./cueva20");
}
