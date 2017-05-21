/****************************************************************************
Fichero: pasillo1.c
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
    "bronce iluminan la zona. Al sur se encuentra el vest�bulo de entrada a la torre y "
    "al oeste contin�a el pasillo.\n");
    AddDetail("antorchas", "Antorchas de gran tama�o permanentemente encendidas.\n");
    AddDetail("soportes", "Antiguos soportes de bronce con el escudo de los Dhes-Bl�in "
    "grabado.\n");
    AddDetail(({"pared", "paredes"}), "La piedra de las paredes est� cuidadosamente "
    "pulida, ofreciendo un aspecto menos tosco que la cara exterior del muro de la torre.\n");
    AddDetail(({"suelo", "emlosado", "losas"}), "El suelo de la torre est� hecho de "
    "losas cuadradas bien pulidas y perfectamente encajadas, denotando la importancia "
    "del edificio en el que habita la nobleza.\n");
    AddExit("oeste", "./pasillo2");
    AddExit("norte", "./cuarto");
    AddExit("sur", "./vestibulo");
    AddDoor("norte", "una puerta de madera",
    "Es una tosca puerta de madera sin ning�n grabado en su superficie.\n",
    ({"puerta", "puerta de madera", "puerta tosca", "puerta del norte"}));
    SetLocate("el castillo de Nandor");
}


