/****************************************************************************
Fichero: bosque007.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
Orilla norte del río.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/orilla");

create(){
    ::create();
    SetIntShort("la orilla norte del río Kandal");
    SetIntLong(QueryIntLong()+ " En el oeste puedes divisar un ancho camino con su"
        " correspondiente puente para atravesar este río hacia el sur.\n");
    AddDetail("camino", "Se ve al oeste, puedes ir hacia allí para verlo mejor.\n");
    AddDetail("puente", "El puente te ayudará a cruzar el río hacia el sur.\n");
    AddExit("nordeste","./bosque001");
    AddExit("oeste",CNS("cam02"));

}


