/****************************************************************************
Fichero: pasillo3.c
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
    "bronce iluminan la zona. Junto a la pared hay colocada una vieja armadura.\n");
    AddDetail("antorchas", "Antorchas de gran tamaño permanentemente encendidas.\n");
    AddDetail("soportes", "Antiguos soportes de bronce con el escudo de los Dhes-Bláin "
    "grabado.\n");
    AddDetail(({"pared", "paredes"}), "La piedra de las paredes está cuidadosamente "
    "pulida, ofreciendo un aspecto menos tosco que la cara exterior del muro de la torre.\n");
    AddDetail(({"suelo", "emlosado", "losas"}), "El suelo de la torre está hecho de "
    "losas cuadradas bien pulidas y perfectamente encajadas, denotando la importancia "
    "del edificio en el que habita la nobleza.\n");
    AddDetail("armadura", "Una vieja armadura con algunas manchas de óxido en los "
    "rebordes. Tiene la visera del yelmo bajada y no muestra insignia alguna.\n");
    AddExit("oeste", "./pasillo4");
    AddExit("este", "./pasillo2");
    AddExit("norte", "./silo1");
    AddDoor("norte", "una puerta de madera",
    "Es una puerta vieja de madera para acceder a uno de los silos del castillo.\n",
    ({"puerta", "puerta de madera", "puerta del silo", "puerta vieja", "puerta del norte"}));
    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("sirvientes_castillo"), REFRESH_DESTRUCT);
}


