/****************************************************************************
Fichero: girlak.c
Autor: Ratwor
Fecha: 15/08/2007
Descripción: El jefe de los ogros de las cabernas.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <gremios.h>
#include <combat.h>
inherit CAOSPNJ"ogro_base";

create(){
    ::create();
    SetStandard("Girlak","ogro",([ GC_LUCHADOR:75+d6()]),GENERO_MASCULINO);

    SetShort("Girlak, jefe ogro de las cavernas");
    SetLong("  Girlak es un ogro importante. Por lo menos, esa es la opinión que esta "
    "mole de músculos y grasa compacta de ojos porcinos tiene de si mismo.\n   Las "
    "malas lenguas, no podían ser buenas tratándose de ogros, cuentan que en su "
    "juventud, en un ataque de hambre voraz, llegó a comerse a su propia madre mientras"
    " dormía. El incidente no fue acogido de muy buen grado por Wadrok, el ogro al que "
    "pertenecía la hembra y éste se dispuso a ajusticiar al jóven ogro.  De la "
    "subsiguiente pelea  Girlak escapó con una oreja de menos y mal herido. huyó "
    "de las cavernas de su tribu a las tierras exteriores.  Allí, no tardó en hacerse "
    "una gran reputación como mercenario.\n Tras varios años, habiéndose hecho algo "
    "más poderoso, volvió a sus cavernas y tras acabar con Wadrok se apoderó de sus "
    "hembras y miserables vienes.\n Actualmente reside en sus cavernas, rodeado por sus "
    "fieles secuaces y sus hembras, aunque de vez en cuando sale al exterior a hacer de "
    "las suyas.\n Nunca deja de lado su arma  y jamás se quita la armadura, lo que "
    "trae como consecuencia el hedor que cabe esperar.\n");

    AddId(({"girlak","Girlak","jefe","jefe ogro","ogro","Ogro",
        "ogro de las cavernas"}));
    SetAlign(-600);
    SetGoChance(70);
    AddItem(CAOSARM"mandoble", REFRESH_REMOVE, SF(wieldme));
    AddItem(ARMOUR,REFRESH_REMOVE,SF(wearme),
        ([P_SHORT: "una enorme coraza",
        P_LONG:  "Es una enorme pieza de hierro toscamente forjada  advirtiéndose "
            "las marcas de los martillazos del herrero al forjarla. \n Cubre por "
            "completo el torso y además de diversas marcas, abolladuras y arañazos "
            "presenta grandes manchas de óxido.  Aún así, y pese a su gran peso "
            "debe proporcionar buena protección.\n",
        P_ARMOUR_TYPE:AT_TUNICA,
        P_IDS: ({"coraza", "coraza pesada", "pesada coraza"}),
        P_AC: 11, P_MATERIAL:M_HIERRO,
        P_SIZE:P_SIZE_LARGE,
        P_RESET_QUALITY: 90,
        P_WEIGHT: 11050,
        P_VALUE: 2100]) );


}
