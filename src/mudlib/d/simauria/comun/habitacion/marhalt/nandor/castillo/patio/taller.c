/****************************************************************************
Fichero: taller.c
Autor: Ratwor
Fecha: 29/12/2007
Descripción: Un taller donde se hacen y arreglan las armas de los soldados.
****************************************************************************/

#include "./path.h"
#include "/guilds/guerreros/wguild.h"
#include <skills.h>
inherit SIM_ROOM;

public int IsSmithy()
{
    return 1;
}

public int cmd_repair(string str)
{
    if (TP&&TP->QueryAttr(HAB_REPARAR,1)) return 0;
    return notify_fail("El martillo es demasiado pesado para tí.\n");
}

create(){
    ::create();
    SetIntShort("un taller de herrería");
    SetIntLong("La herrería es un cobertizo cuya pared oeste está formada por la misma "
    "muralla con la puerta al este. El interior del edificio es todo de piedra, "
    "evitando la madera que podría incendiarse con la actividad casi continua de la "
    "fragua. Un pesado yunque junto a dos fuelles grandes completan el taller en donde "
    "el herrero del castillo secundado por algún aprendiz repara y forja las armas y "
    "armaduras de la guarnición y su señor. A un lado se alza una pila de carbón "
    "para alimentar la fragua. En un rincón un pequeño montón de lingotes de hierro "
    "forman la provisión de mineral de la herrería. Sobre un banco de trabajo se "
    "amontonan puntas de flecha y  lanza sin pulir ni afilar junto a hojas de espada y "
    "hacha y bandas de hierro curvadas para formar cascos o armazones de escudos.\n");
    AddDetail("fuelles", "Dos fuelles hechos con la piel de algún animal utilizados para "
    "reavivar el fuego de la fragua.\n");
    AddDetail(({"lingotes", "hierro"}), "Lingotes de hierro en bruto utilizado en la "
    "fabricación de herramientas y armas.\n");
    AddDetail("banco", "Un banco que ocupa toda una pared, confeccionado con la mitad de "
    "un tronco. A un extremo tiene acoplado un torno y al otro una piedra de amolar.\n");
    AddDetail("torno", "Un sencillo torno usado para sujetar piezas de metal mientras se "
    "pulen o afilan.\n");
    AddDetail("piedra", "Una piedra cilíndrica fijada a un extremo del banco de trabajo "
    " para afilar las armas girando una manivela situada a un extremo.\n");
    SetIntBright(30);
    SetLocate("el castillo de Nandor");
    AddRoomCmd("repair",SF(cmd_repair));
    AddExit("este", "./patio09");
    AddDoor("este", "una puerta de madera",
    "Es una vieja puerta de madera maltratada por el tiempo y, seguramente, por "
    "ciertos malos modales de los guardias del castillo.\n",
    ({"puerta", "puerta de madera", "puerta vieja", "puerta vieja de madera",
    "puerta del patio", "puerta del este"}));
    SetIntSmell("Hay un olor a carbón quemado que proviene de la fragua.\n");
    AddDetail("fragua", "De ella emana un calor insoportable.\n");
    AddDetail("herrero", "No se le ve por aquí...\n");
    AddDetail("yunque",
        "Es un enorme yunque de hierro, el herrero da forma a sus trabajos sobre él.\n");
}
