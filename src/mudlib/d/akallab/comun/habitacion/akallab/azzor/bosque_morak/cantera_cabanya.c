/*
DESCRIPCION  : cantera al norte del bosque de Morak
FICHERO      : cantera_cabanya.c
MODIFICACION : 16-02-00 [Angor@Simauria] Creacion
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create()
{
    ::create();
   SetIntShort("la cabaña en la cantera del bosque de Morak");
    SetIntLong("El ambiente es agradable en el interior de esta rústica "
        "cabaña de madera gracias al fuego que arde lentamente en la "
        "chimenea. Es ésta una construcción sencilla donde al parecer viven "
        "los canteros que trabajan aquí, y sin más muebles que un par de "
        "taburetes junto a una tosca mesa, un banco adosado a la pared y "
        "varios jergones donde dormir. En una marmita que pende sobre el "
        "fuego de la chimenea, bulle lentamente un hervido.\n");
    AddDetail(({"taburete","taburetes"}),"Junto a la mesa hay un par de "
        "taburetes de madera. Están hechos con una simple plancha de madera "
        "que hace de asiento y tres pequeños troncos como patas.\n");
    AddDetail(({"jergon","jergón","jergones"}),"Hay varios jergones a lo "
        "largo del suelo de la cabaña. Es en esta especie de colchones de "
        "paja, hierba o esparto donde duermen los canteros que habitan este "
        "lugar.\n");
    AddDetail(({"mesa"}),"Junto al banco y enfrente de la chimenea se halla "
        "una tosca mesa de mediano tamaño.\n");
    AddDetail(({"banco"}),"Es un largo banco de madera donde sentarse. Está "
        "colocado junto a la chimenea, al agradable calor del fuego.\n");
    AddDetail(({"chimenea"}),"La chimenea de piedra está adosada a la pared "
        "sur de la cabaña. En ella arde lentamente un agradable fuego que "
        "calienta el lugar y la marmita de metal que cuelga sobre él.\n");
    AddDetail(({"marmita","hervido"}),"Los canteros que viven en esta cabaña "
        "deben estar preparando la comida, ya que en la marmita de metal que "
        "pende sobre el fuego de la chimenea bulle lo que parece ser un "
        "simple hervido.\n");
    SetIntNoise("Oyes el borboteo del hervido en la marmita.\n");
    SetIntSmell("Huele a grasa y a ahumado.\n");
    SetLocate("valle de Azzor");
    SetIndoors(1);
    SetIntBright(50);
    AddExit("este",BOSQUE_MORAK("cantera1"));
}
