/***
Fichero: calle_03.c
Autor: kastwey@simauria
Descripción: Calle principal de Siempreunidos. La del establo.
Creación: 07/12/2004
***/

#include "path.h"

inherit STD_FAERIA("hab_siempreunidos");


create()
{
    ::create();
    SetIntShort("la calle principal de Siempreunidos");
    SetIntLong(W("Te encuentras caminando por la calle principal del pueblo de Siempreunidos.\n"
    "Al sur y al norte continúa la calle, y al este puedes ver un establo.\n"));
    SetOficina(HAB_PUESTO("calles/calle_02"));
    AddDetail(({"establo"}), "Es una pequeña construcción para guardar las monturas.\n");
    AddExit("sur", HAB_PUESTO("calles/calle_02"));
    AddExit("norte", HAB_PUESTO("calles/calle_04"));
    AddExit("este", HAB_PUESTO("establo/establo"));
    SetIntNoise("Puedes escuchar ruido de patadas al este.\n");
    SetIntSmell("Hmm... huele a estiércol.\n");
    SetOutdoors(1);
}