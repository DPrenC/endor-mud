/****************************************************************************
Fichero: explanada.c
Autor: Kastwey
Creación: 24/07/2005
Descripción: explanada del sendero de entrada a Annufam
****************************************************************************/

#include "./path.h"

inherit BASE_CIUDAD_ANNUFAM;

public void create()
{
    ::create();
    SetIntShort("una pequeña explanada");
    SetIntLong(W("Has llegado a una pequeña explanada aquí en las montañas "
      "de Kha-annu. Un sendero parece introducirse en un bosquecillo de pinos "
      "y hayas. Al norte, divisas lo que parece una ciudad o poblado.\n"));
    AddDetail("bosque","Al sudeste puedes observar un bosque de pinos y "
              "hayas, y una pequeña senda que se introduce en él.\n");
    AddExit("sudeste",HAB_SENDERO_ANNUFAM("sendero3"));
    AddExit("norte",HAB_CIUDAD_ANNUFAM("entrada"));
}


