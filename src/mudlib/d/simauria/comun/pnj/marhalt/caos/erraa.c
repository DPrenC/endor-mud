/****************************************************************************
Fichero: erraa.c
Autor: Ratwor
Fecha: 15/08/2007
Descripción: Una de las hembras del jefe de los ogros.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>

inherit CAOSPNJ"ogro_base";

create(){
    ::create();
    SetStandard("Erraa", "ogro", ([GC_LUCHADOR:62+d6()]), GENDER_FEMALE);
    SetShort("Erraa, una de las hembras de Girlak");
    SetLong(" Mas pequeña que sus congéneres masculinos, esta  hembra de ogro se cubre "
    "con una maloliente piel de oso, que a causa del mal curtido, tiene zonas sin pelo "
    "y la parte interior recubierta de una sustancia mohosa. \n  Sus piernas arqueadas, "
    "su rostro cubierto por matas de pelo negro,  la nariz chata, y los pechos peludos,"
    " grandes y colgantes no le dan un aspecto precisamente  atractivo. Aunque para "
    "Girlak, su propietario, es  una de las mejores hembras de la banda ya que fue "
    "elegida por él mismo para darle placer.\n");

    AddId(({"erraa","Erraa","hembra","ogro","Ogro", "ogro de las cavernas", "ogra"}));
    SetAlign(-400);
    SetGoChance(40);
}
