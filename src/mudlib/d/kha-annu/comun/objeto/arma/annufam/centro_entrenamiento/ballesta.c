/****************************************************************************
Fichero: ballesta.c
Autor: Riberales
Fecha: 09/05/2006
Descripción: Ballesta para los enanos.
****************************************************************************/


#include "path.h"

inherit THING;

public int cmd_apuntar(string str)
{


    string *salidas;

    if (!str) return notify_fail("¿Apuntar hacia dónde?\n",NOTIFY_NOT_VALID);


    if (sscanf(str, "al %s",dir) == 1 || sscanf(str,"hacia %s",dir) == 1 ||
        sscanf(str, "hacia el %s",dir) == 1)
    {
        salidas = m_indices(filter(environment()->QueryExits(),
                                   (:stringp($2[0]):)));
	}
}





create()
{
    if (::create()) return 1;

    SetShort("una ballesta");
    SetLong("Se trata de una ballesta de madera para lanzar birotes.\n");

    SetIds(({"ballesta"}));

    SetWeight(3000);
    SetValue(1200);
}

