/*
DESCRIPCION  : camino a traves del bosque de Morak
FICHERO      : camino02.c
MODIFICACION : 15-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit BOSQUE_MORAK("camino");

create()
{
    ::create();
   SetIntLong("El camino que atraviesa el bosque de Morak describe aqu� una "
        "suave curva a medida que avanza por el interior del bosque. "
        "Observas que en esta zona el bosque es mas denso y que por tanto la "
        "forma m�s f�cil de avanzar por �l es siguiendo el camino ya trazado. "
        "El camino contin�a hacia el oeste y hacia el nordeste.\n");
    AddExit("este",BOSQUE_MORAK("bosque04"));
    AddExit("sur",BOSQUE_MORAK("bosque03"));
    AddExit("nordeste",BOSQUE_MORAK("camino03"));
    AddExit("oeste",BOSQUE_MORAK("camino01"));
}
