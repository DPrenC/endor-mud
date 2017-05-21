/************************************************************************//****************************************************************************
Fichero: gerli.c
Autor: Ratwor
Fecha: 15/08/2007
Descripción: una de las hembras del jefe de los ogros.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit CAOSPNJ"ogro_base";

create(){
    ::create();
    SetStandard("Gerli","ogro",([ GC_LUCHADOR:60+d6()]),GENERO_FEMENINO);

    SetShort("Gerli, una de las hembras de Girlak");
    SetLong("Una hembra de ogro , de repulsivo aspecto de unos 2 metros de altura. "
    " Su cuerpo es ancho y algo fofo, y su rostro, de toscas facciones, muestra unos "
    "dientes rectangulares y  desparejados como lápidas de un cementerio ruinoso.\n "
    " Va vestida con pieles sin curtir y, un pelo largo y oscuro le cubre casi "
    "todo el cuerpo.\n");

    AddId(({"gerli","Gerli","ogro","Ogro","ogro de las cavernas", "ogra", "hembra"}));
    SetAlign(-300);
    SetGoChance(45);

}
