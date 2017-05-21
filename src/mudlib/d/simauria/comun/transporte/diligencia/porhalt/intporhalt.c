/****************************************************************************
Fichero: /d/simauria/comun/transporte/diligencia/porhalt/intporhalt.c
Autor: Ratwor
Fecha: 30/03/2008
Descripci�n: Diligencia Enalel-Nandor
****************************************************************************/
#include "./path.h"
inherit ROOM;

create()
{
    ::create();
    SetIntShort("La diligencia Porhalt");
    SetIntLong("Te encuentras en el interior de la diligencia Porhalt, que hace su "
    "trayecto a lo largo de todo el camino del norte de Marhalt, desde Enalel hasta "
    "Nandor.\n Parece algo m�s c�moda que las dem�s que circulan por el dominio de "
    "Simauria, lo cual quiz� sea debido a las costumbres refinadas de los habitantes de "
    "la regi�n del Pomar.\n");
    SetIntBright(40);
    SetIntSmell("El olor es intenso, aunque no desagradable, pero s� algo indefinible.\n");
}

