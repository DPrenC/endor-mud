/****************************************************************************
Fichero: pasillo6.c
Autor: Ratwor
Fecha: 01/01/2008
Descripción: El pasillo de la planta baja de la torre del homenaje.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
SetIntBright(30);
    SetIntShort("un ancho pasillo");
    SetIntLong("Estás en un amplio pasillo enlosado y de techo alto que recorre la "
    "planta baja de la torre del homenaje. Grandes antorchas colocadas en soportes de "
    "bronce iluminan la zona. Aquí una gran escalera asciende a la planta superior de "
    "la torre, y frente a ella, en la pared este cuelga un tapiz. Al norte continúa el "
    "pasillo.\n");
    AddDetail("antorchas", "Antorchas de gran tamaño permanentemente encendidas.\n");
    AddDetail("soportes", "Antiguos soportes de bronce con el escudo de los Dhes-Bláin "
    "grabado.\n");
    AddDetail(({"pared", "paredes"}), "La piedra de las paredes está cuidadosamente "
    "pulida, ofreciendo un aspecto menos tosco que la cara exterior del muro de la torre.\n");
    AddDetail(({"suelo", "emlosado", "losas"}), "El suelo de la torre está hecho de "
    "losas cuadradas bien pulidas y perfectamente encajadas, denotando la importancia "
    "del edificio en el que habita la nobleza.\n");
    AddDetail(({"escaleras", "escalera"}),
    "Una amplia escalera de piedra que asciende en semicírculo a "
    "la planta superior. Los anchos pasamanos y las columnatas finales con la parte "
    "superior tallada en forma de yelmo cilíndrico están hechas en mármol blanco, muy "
    "raro en esta zona del reino.\n");
    AddDetail("tapiz", "Muestra una vista frontal del castillo de Nandor con las "
    "puertas, el puente, la muralla norte, los dos torreones principales, con la torre "
    "del homenaje recortándose detrás. El castillo está siendo atacado por una hueste de "
    "orcos, que trepan por escalas y disparan proyectiles con toscas catapultas de gran "
    "tamaño. La parte alta del torreón de la Inmolación está coronada por las llamas y "
    "atacantes y defensores se arrojan al vacío. En las murallas, hombres de armas en "
    "cota de malla y arqueros, defienden la posición y disparan las pequeñas "
    "catapultas instaladas tras las almenas.\n");
    AddExit("norte", "./pasillo5");
    AddExit("arriba", CASTILLO("planta2/pasillo1"));
    SetLocate("el castillo de Nandor");
}


