/****************************************************************************
Fichero: heritik.c
Autor: Ratwor
Fecha: 15/08/2007
Descripción: Uno de los secuaces de Girlak.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>
inherit CAOSPNJ"ogro_base";

create(){
    ::create();
    SetStandard("Heritik","ogro",([ GC_LUCHADOR:70]),GENERO_MASCULINO);

    SetShort("Heritik, secuaz de Girlak");
    SetLong("Heritik es un ogro, miembro de una raza de grandes humanoides famosos "
    "por  su tendencia a  capturar y devorar todo aquello que se les ponga por "
    "delante.\n A pesar de esto no son especialmente malvados, y por una buena paga "
    "o mejor aún, por grandes cantidades de comida y bebidas fuertes son capaces de "
    "luchar como mercenarios con cualquier raza, sean orcos, humanos o enanos, y "
    "les tienen sin cuidado las causas, los motivos o la justicia de los combates "
    "en los que participan.\n Heritik aparenta ser un gran veterano en tales lides "
    "puesto que muestra gran número de cicatrices que se entrecruzan sobre su musculoso"
    " corpachón, y donde debería tener el ojo izquierdo solo se puede ver una oscura "
    "cuenca vacía sobre cuyos bordes asoman pequeños jirones de piel muerta.\n");

    AddId(({"heritik","Heritik","ogro","Ogro","ogro de las cavernas",
        "secuaz"}));
    SetAlign(-450);
    SetGoChance(60);
    AddItem(CAOSARM"maza",REFRESH_REMOVE,SF(wieldme));
}
