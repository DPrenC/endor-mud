/****************************************************************************
Fichero:
Autor: Kastwey
Creación: 24/07/2005
Descripción:
****************************************************************************/

#include "./path.h"

inherit HAB_SENDERO_ANNUFAM("sendero_base");

public void create()
{
    ::create();
    SetIntShort("un pequeño sendero");
    SetIntLong(W("te encuentras en un sendero en las montañas de Kha-annu. "
                 "Esta parte del camino tiene bastante vegetación, pero nada "
                 "comparado con lo que ves al este, donde se hace muy "
                 "frondosa. Al noroeste, sin embargo, parece que se despeja.\n"));
    AddExit("este",HAB_SENDERO_ANNUFAM("sendero2"));
    AddExit("noroeste",HAB_SENDERO_ANNUFAM("explanada"));
}
