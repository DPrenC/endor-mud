/***
Fichero: escaleras_posada.c
Autor: Kastwey, 2simauria
Descripci�n: 04/12/2004
Descripci�n: Escaleras que conducen a la planta superior de la posada.
***/

#include "path.h"

inherit STD_FAERIA("posada_base_faeria");

create()
{
    ::create();
    SetIntShort("las escaleras de la posada");
    SetIntLong(W("Te encuentras en las escaleras que comunican el piso inferior con el piso superior de la posada.\n"
    "Hacia el sur puedes ver el vest�bulo, y hacia arriba est�n las habitaciones de los hu�spedes.\n"));
    SetOficina(HAB_PUESTO("posada/posada"));
    SetIndoors(1);
    SetIntBright(25);
    AddExit("sur", HAB_PUESTO("posada/posada"));
    AddExit("arriba", HAB_PUESTO("posada/posada_piso1"));
    AddRoomCmd("reiniciar", "cmd_reiniciar");
}
