/****************************************************************************
Fichero: perreras.c
Autor: Ratwor
Fecha: 29/12/2007
Descripción: Las perreras del castillo
****************************************************************************/

#include "./path.h"

inherit SIM_ROOM;

create(){
    ::create();
    SetIntShort("las perreras");
    SetIntLong("Te encuentras en las perreras del castillo, un espacio entre el "
    "cobertizo de las pajareras al sur y los establos al norte, cerrado por la "
    "muralla al este y una verja sobre un muro bajo al oeste con una destartalada "
    "puerta de tablas. El suelo de piedra está sucio de excrementos y orines ya "
    "añejos que nadie parece molestarse en limpiar. Un cubo de madera medio lleno de "
    "agua yace en un rincón junto a varios huesos roídos. De anillas clavadas en la "
    "pared cuelgan algunas cadenas. Aquí se encierran tanto los perros de caza del "
    "señor como los feroces guardianes de los que tanto gusta criar la familia "
    "desde hace generaciones.\n");
    AddDetail("verja", "Una verja de barrotes de hierro algo descascarillados por el "
    "óxido, levantada sobre un bajo muro de piedra con una destartalada puerta en la "
    "parte central.\n");
    AddDetail("huesos", "algunos viejos huesos roídos oscurecidos por la suciedad.\n");
    AddDetail("cadenas", "Largas cadenas de hierro a las que se atan los perros.\n");
    AddDetail(({"cubo", "viejo cubo", "cubo viejo"}), "Es un viejo cubo, a medio llenar, "
    "sin ninguna importancia.\n");
    SetIntBright(30);
    AddExit("oeste", "./patio17");
    AddDoor("oeste", "una puerta de madera",
    "Es una puerta de madera para que no se salgan los perros que pudieran quedarse "
    "sueltos. Presenta ciertos arañazos de garras en su parte baja, señal "
    "inequívoca de acciones caninas.\n",
    ({"puerta", "puerta de madera", "puerta del patio", "puerta del oeste"}));
    SetLocate("el castillo de Nandor");
    AddItem(PNJCASTILLO("perro_guardian"), REFRESH_DESTRUCT, d4());
    AddItem(PNJCASTILLO("perro_caza"), REFRESH_DESTRUCT, d4());
}
