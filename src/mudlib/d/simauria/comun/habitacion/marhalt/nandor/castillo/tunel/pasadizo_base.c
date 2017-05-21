/****************************************************************************
Fichero: pasadizo_base.c
Autor: Ratwor
Fecha: 12/01/2008
Descripci�n: un archivo base para los t�neles subterr�neos del castillo.
****************************************************************************/

#include "path.h"
#include <properties.h>

inherit SIM_ROOM;

create(){
    ::create();
    SetLocate("alg�n lugar del norte de Marhalt");
    SetIntShort("un t�nel oscuro");
    SetIntLong("Te encuentras en un t�nel fr�o y oscuro, notas las paredes demasiado "
    "cerca de t� y no se aprecia nada de luz all� donde mires.\n");
    SetIntNoise("Todo es silencio, la proximidad de las paredes aten�an el sonido.\n");
    SetIntSmell("Huele a una mezcla de humedad y alg�n olor parecido al de "
    "animal muerto.\n");
    if(d8()==1)
        AddItem(PNJCASTILLO("rata"), REFRESH_DESTRUCT, d3());
}

