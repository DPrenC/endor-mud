/***
Fichero: escaleras_posada.c
Autor: Kastwey, 2simauria
Descripción: 04/12/2004
Descripción: Escaleras que conducen a la planta superior de la posada.
***/

#include "path.h"

inherit STD_FAERIA("posada_base_faeria");

create()
{
    ::create();
    SetIntShort("las escaleras de la posada");
    SetIntLong(W("Te encuentras en las escaleras que comunican el piso inferior con el piso superior de la posada.\n"
    "Hacia el sur puedes ver el vestíbulo, y hacia arriba están las habitaciones de los huéspedes.\n"));
    SetOficina(HAB_PUESTO("posada/posada"));
    SetIndoors(1);
    SetIntBright(25);
    AddExit("sur", HAB_PUESTO("posada/posada"));
    AddExit("arriba", HAB_PUESTO("posada/posada_piso1"));
    AddRoomCmd("reiniciar", "cmd_reiniciar");
}
