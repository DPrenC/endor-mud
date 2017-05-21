/****************************************************************************
Fichero: pasillo5.c
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
    "bronce iluminan la zona. Al sur el pasillo termina junto a una ancha escalera de "
    "piedra que asciende a la planta superior de la torre.\n");
    AddDetail("antorchas", "Antorchas de gran tamaño permanentemente encendidas.\n");
    AddDetail("soportes", "Antiguos soportes de bronce con el escudo de los Dhes-Bláin "
    "grabado.\n");
    AddDetail(({"pared", "paredes"}), "La piedra de las paredes está cuidadosamente "
    "pulida, ofreciendo un aspecto menos tosco que la cara exterior del muro de la torre.\n");
    AddDetail(({"suelo", "emlosado", "losas"}), "El suelo de la torre está hecho de "
    "losas cuadradas bien pulidas y perfectamente encajadas, denotando la importancia "
    "del edificio en el que habita la nobleza.\n");
    AddDetail("escalera", "Una amplia escalera de piedra que asciende en semicírculo a "
    "la planta superior. Los anchos pasamanos y las columnatas finales con la parte "
    "superior tallada en forma de yelmo cilíndrico están hechas en mármol blanco, muy "
    "raro en esta zona del reino.\n");
    AddExit("sur", "./pasillo6");
    AddExit("este", "./pasillo4");
    AddExit("oeste", "./armeria");
    AddDoor("oeste", "una puerta de madera",
    "Es una puerta de madera para entrar en la armería.\n",
    ({"puerta", "puerta de madera", "puerta de la armería", "puerta del oeste"}));

    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("sirvientes_castillo"), REFRESH_DESTRUCT);
}


