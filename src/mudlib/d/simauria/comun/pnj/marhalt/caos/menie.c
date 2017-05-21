/****************************************************************************
Fichero: menie.c
Autor: Ratwor
Fecha: 15/08/2007
Descripci�n: Un secuaz del jefe de los ogros.
****************************************************************************/

#include "./path.h"
#include <gremios.h>
#include <properties.h>
#include <combat.h>
inherit CAOSPNJ"ogro_base";

create(){
    ::create();
    SetStandard("Menie","ogro",([ GC_LUCHADOR:63+random(5)]),GENERO_MASCULINO);

    SetShort("Menie, secuaz de Girlak");
    SetLong("Se trata de uno de los secuaces de Girlak, que inconfundiblemente tiene"
    " f�sico de ogro, pues es un humanoide de unos tres metros de altura y aspecto "
    "primitivo: Los anchos hombros, el voluminoso pecho  y los brazos  dotados de "
    "enormes m�sculos y grandes garras hacen juego con el rostro de entrecejo "
    "proeminente, mand�bula sobresaliente y nariz chata.\n  En su mirada se aprecia "
    "que no es un ser con muchas luces, aunque no necesita demasiada inteligencia para "
    "atrapar, matar y devorar todo aquello que se le ponga por delante.\n");
    AddId(({"menie","Menie","ogro","Ogro","ogro de las cavernas", "secuaz"}));
    SetGoChance(70);
    AddItem(CAOSARM"maza",REFRESH_REMOVE,SF(wieldme));
}
