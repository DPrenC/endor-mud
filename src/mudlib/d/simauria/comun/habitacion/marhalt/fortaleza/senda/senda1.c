/*
DESCRIPCION  : Senda por el bosque alrededor de la fortaleza de nandor
FICHERO      : senda1.c
Creacion	 : 5-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFS("senda");

create(){
    ::create();
    SetIntLong("Te encuentras en una senda através del bosque.\n Justo en este punto "
        "se ensancha dando paso a la fortaleza de Cored, donde un poco más al norte "
        "puedes ver el foso y la muralla en todo su explendor.\n Aunque parece "
        "abandonada, y que seguro ha visto tiempos mejores, se conserva en buen estado.\n"
        " Al noroeste puedes ver como el bosque te deja un hueco para internarse en "
        "él.\n");
    AddDetail(({"muralla", "foso"}), "Al norte de tu posición se encuentra la fortaleza "
        "propiamente dicha, con su foso lleno de agua y su muralla que resguarda lo que"
        " en su interior se encuentra.\n Dirijiéndote más hacia allí te metes "
        "directamente en el portón sobre el foso.\n");

    AddExit("noroeste",ROOMFB("bosq107"));
    AddExit("suroeste",ROOMFS("senda2"));
    AddExit("norte",ROOMFF("puente"));
    AnyadirPnjs();
}
