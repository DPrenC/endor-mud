/****************************************************************************
Fichero: /d/kha-annu/comun/objeto/otro/lavecel.c
Autor: Yalin
Fecha: 10/05/2007
Descripci�n: Llave de la celda de seguridad de las mazmorras de Kha-annu.
****************************************************************************/

#include "path.h"
inherit THING;

create()
{
    ::create();
    SetShort("una llave de hierro");
    SetLong("Una gran llave de hierro, bastante oxidada, por cierto.\n");
    AddId(({"cdpnmpgs","llave","llave de hierro","llave oxidada"}));
    SetNoDrop("Si no la quer�as, �para qu� la has cogido?\n");
}
