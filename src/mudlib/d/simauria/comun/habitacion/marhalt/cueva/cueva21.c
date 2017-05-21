/********************************************
*    Nombre: cueva21.c			    *
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
    SetIntShort("una gran sala circular");
    SetIntLong("Esta ámplia sala está sorprendentemente bien excavada, las paredes "
    "están lisas y pulidas, al igual que el suelo y el alto techo.\n Una enorme "
    "columna blanca preside el centro de la estancia circular , que se estiende en "
    "distintas direcciones.\n  La temperatura aquí ha bajado varios grados, por lo que "
    "se siente un frío poco natural.\n");
    SetIntNoise("El eco de tus pasos resuenan por las pulidas paredes.\n");
    SetIntSmell("El aire es muy espeso y te cuesta respirar.\n");
    AddDetail(({"columna", "columna blanca","pilar"}), "Es una enorme columna de frío "
    "mármol que preside el centro de esta estancia circular.\n");
    AddExit("sur","./cueva19");
    AddExit("este","./cueva20");
    AddExit("oeste","./cueva22");
    AddItem(PNJ("marhalt/cueva/gran_troll"),REFRESH_DESTRUCT);
    AddItem(OBJETO"otro/caparazon",REFRESH_REMOVE);
}
