/****************************************************************************
Fichero: pasillo6.c
Autor: Ratwor
Fecha: 01/01/2008
Descripci�n: El pasillo de la planta baja de la torre del homenaje.
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
SetIntBright(30);
    SetIntShort("un ancho pasillo");
    SetIntLong("Est�s en un amplio pasillo enlosado y de techo alto que recorre la "
    "planta baja de la torre del homenaje. Grandes antorchas colocadas en soportes de "
    "bronce iluminan la zona. Aqu� una gran escalera asciende a la planta superior de "
    "la torre, y frente a ella, en la pared este cuelga un tapiz. Al norte contin�a el "
    "pasillo.\n");
    AddDetail("antorchas", "Antorchas de gran tama�o permanentemente encendidas.\n");
    AddDetail("soportes", "Antiguos soportes de bronce con el escudo de los Dhes-Bl�in "
    "grabado.\n");
    AddDetail(({"pared", "paredes"}), "La piedra de las paredes est� cuidadosamente "
    "pulida, ofreciendo un aspecto menos tosco que la cara exterior del muro de la torre.\n");
    AddDetail(({"suelo", "emlosado", "losas"}), "El suelo de la torre est� hecho de "
    "losas cuadradas bien pulidas y perfectamente encajadas, denotando la importancia "
    "del edificio en el que habita la nobleza.\n");
    AddDetail(({"escaleras", "escalera"}),
    "Una amplia escalera de piedra que asciende en semic�rculo a "
    "la planta superior. Los anchos pasamanos y las columnatas finales con la parte "
    "superior tallada en forma de yelmo cil�ndrico est�n hechas en m�rmol blanco, muy "
    "raro en esta zona del reino.\n");
    AddDetail("tapiz", "Muestra una vista frontal del castillo de Nandor con las "
    "puertas, el puente, la muralla norte, los dos torreones principales, con la torre "
    "del homenaje recort�ndose detr�s. El castillo est� siendo atacado por una hueste de "
    "orcos, que trepan por escalas y disparan proyectiles con toscas catapultas de gran "
    "tama�o. La parte alta del torre�n de la Inmolaci�n est� coronada por las llamas y "
    "atacantes y defensores se arrojan al vac�o. En las murallas, hombres de armas en "
    "cota de malla y arqueros, defienden la posici�n y disparan las peque�as "
    "catapultas instaladas tras las almenas.\n");
    AddExit("norte", "./pasillo5");
    AddExit("arriba", CASTILLO("planta2/pasillo1"));
    SetLocate("el castillo de Nandor");
}


