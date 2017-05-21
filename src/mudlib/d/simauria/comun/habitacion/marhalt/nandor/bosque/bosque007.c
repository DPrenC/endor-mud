/****************************************************************************
Fichero: bosque007.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
Orilla norte del r�o.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/orilla");

create(){
    ::create();
    SetIntShort("la orilla norte del r�o Kandal");
    SetIntLong(QueryIntLong()+ " En el oeste puedes divisar un ancho camino con su"
        " correspondiente puente para atravesar este r�o hacia el sur.\n");
    AddDetail("camino", "Se ve al oeste, puedes ir hacia all� para verlo mejor.\n");
    AddDetail("puente", "El puente te ayudar� a cruzar el r�o hacia el sur.\n");
    AddExit("nordeste","./bosque001");
    AddExit("oeste",CNS("cam02"));

}


