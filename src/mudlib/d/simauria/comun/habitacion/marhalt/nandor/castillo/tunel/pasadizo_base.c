/****************************************************************************
Fichero: pasadizo_base.c
Autor: Ratwor
Fecha: 12/01/2008
Descripción: un archivo base para los túneles subterráneos del castillo.
****************************************************************************/

#include "path.h"
#include <properties.h>

inherit SIM_ROOM;

create(){
    ::create();
    SetLocate("algún lugar del norte de Marhalt");
    SetIntShort("un túnel oscuro");
    SetIntLong("Te encuentras en un túnel frío y oscuro, notas las paredes demasiado "
    "cerca de tí y no se aprecia nada de luz allá donde mires.\n");
    SetIntNoise("Todo es silencio, la proximidad de las paredes atenúan el sonido.\n");
    SetIntSmell("Huele a una mezcla de humedad y algún olor parecido al de "
    "animal muerto.\n");
    if(d8()==1)
        AddItem(PNJCASTILLO("rata"), REFRESH_DESTRUCT, d3());
}

