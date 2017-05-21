/*****************************************************************************************
 ARCHIVO:       bosque39.c
 AUTOR:         Ztico
 FECHA:         26-04-2005
 DESCRIPCIÓN:   Bosque de las Hadas.
 COMENTARIOS:
*****************************************************************************************/

#include "./path.h"

inherit BASE_HADAS;

create()
{
    if(::create()) return 1;

    SetIntShort("la cámara de la Princesa");
    SetIntLong("Parece como si hubieras entrado en un nuevo mundo. Nada de lo que hay "
        "en esta habitación te recuerda lo más mínimo que estás dentro de una cueva, "
        "en realidad nada de lo que has recorrido hasta ahora se asemeja a una. El "
        "suelo parece ser de cristal y las paredes son de un mármol fino, con vetas "
        "plateadas. Del techo cuelgan montones de hilos de colores y hay una extraña "
        "nube flotando en el centro de la habitación.\n");
    AddDetail(({"suelo", "cristal"}), "Tiene un aspecto sumamente delicado y "
        "frágil.\n");
    AddDetail(({"pared", "paredes"}), "Obviamente las paredes han sido creadas o "
        "traidas hasta aquí por medio de una extraña magia arcana.\n");
    AddDetail(({"veta", "vetas"}), "Son suaves y sinuosas. Recorren las paredes como "
        "pequeñas culebrillas.\n");
    AddDetail(({"hilo", "hilos"}), "Finos hilos de colores caen casi invisibles desde "
        "las alturas, y dan un aspecto bastante ridículo a la estancia.\n");
    AddDetail(({"nube", "extraña nube", "extranya nube"}), "Seguramente sea una "
        "extravagancia de la princesa. No es una nube cualquiera; es tan densa y "
        "mullida como un cojín de plumas pero al mismo tiempo es muy ligera y flota "
        "mimosamente sobre el suelo.\n");
    SetIndoors(1);
    SetIntBright(50);

    AddExit("sur", HAB_BOSQUE_HADAS("bosque36.c"));

    AddItem(PNJ_VALMAR("princesa_hadas.c"), REFRESH_DESTRUCT, 1);
    AddItem(PNJ_VALMAR("hada_sirviente.c"), REFRESH_DESTRUCT, 3);
}
