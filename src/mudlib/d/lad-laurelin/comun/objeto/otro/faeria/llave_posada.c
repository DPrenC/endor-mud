/***
Fichero: llave1.c
Autor: kastwey
Descripci�n: Una llave para la habitaci�n de la posada.
Creaci�n: 04/12/2004
***/

#include "path.h"
#include <properties.h>

inherit THING;

create()
{
    ::create();
    SetShort("una llave");
    SetLong("Es una llave met�lica, enganchada a un grueso llavero.\n");
    SetValue(2000);
    SetWeight(30);
  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
    AddId("llave");
    AddId("llave_posada_faeria");
}
