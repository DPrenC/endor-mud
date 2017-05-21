/****************************************************************************
Fichero: cam_cortado_base.c
Autor: Ratwor
Fecha: 19/08/2007
Descripción: un archivo base para el camino cortado que va a psionicos y a la cueva
de los trolls.
****************************************************************************/

#include "./path.h"
#include <properties.h>

inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("un encajonado desfiladero");
    SetIndoors(0);
    SetIntSmell("Huele a materia vegetal seca.\n");
    SetIntNoise("Oyes el triste silbido del viento entre las rocas y en la parte "
    "alta de las paredes del desfiladero.\n  A veces, entre la maleza, se oyen "
    "correteos y chasquidos, e incluso, allá en las alturas, la penetrante llamada de "
    "un ave rapaz.\n");
    AddDetail(({"piedras", "piedra", "roca", "cocas", "suelo"}),
    "Las cuestas y la parte baja del desfiladero están sembradas de toda clase de "
    "cantos rodados y piedras sueltas, procedentes, en su mayoría, de derrumbamientos "
    "y pequeñas avalanchas en la parte alta de las paredes.\n");
    AddDetail(({"arbustos", "arbusto"}), "  Una maraña de arbustos silvestres crecen,"
    " apretadamente, sujetándose de forma precaria con las raíces entre las piedras "
    "sueltas de las pendientes del desfiladero. En su mayoría son arbustos espinosos.\n");
    AddDetail("maleza", " Cubriendo la parte baja de las paredes y las empinadas "
    "cuestas, crece una maleza reseca constituida en su mayor parte por zarzas "
    "y plantas rastreras con las que sería muy fácil enrredarse.\n");
    AddDetail(({"pared", "paredes"}), "El  desfiladero  está flanqueado por escarpados "
    "muros de piedra gris que de tan altos parecen inclinarse amenazantes sobre ti "
    "como si estuvieran a punto de derrumbarse y, que serían imposibles de escalar. \n"
    " En su parte baja crece una reseca maleza que ha conseguido sobrevivir en los "
    "intersticios de la roca.\n");
    if(d4()==1)
        AddItem(PNJ("marhalt/cueva/troll_noche"), REFRESH_DESTRUCT, d2());
}
