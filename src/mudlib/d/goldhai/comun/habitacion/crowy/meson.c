/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 21-10-97                |
 |                                                             |
 *=============================================================*/

#include "./path.h"
inherit PUB;

create(){
    ::create();
    SetIntShort("el mesón 'cuervo negro'");
    SetIntLong(
        "Te encuentras en el mesón 'cuervo negro', uno de los lugares más conocidos "
        "de toda la isla Goldhai y el sitio preferido de los crowianos para degustar sus"
        " platos preferidos. En ningún otro lugar de esta isla se puede comer tan a gusto"
        " como aquí.\n  El cocinero es un viejo humano que en su juventud "
        "estuvo al servicio de importantes reyes y terratenientes. Su especialidad "
        "es el Kribbat, carne de cerdo empanada con arroz y que ha conseguido que sea "
        "la comida típica de Crowy bañada con una botella de Yith-pen, la bebida "
        "local.\n");
    SetIndoors(1);
    SetIntBright(30);
    SetIntNoise("Apenas oyes nada, la gente degusta sus platos sin hacer ruido.\n");
    SetIntSmell("Huele a carne recien guisada.\n");
    AddDetail(({"meson","restaurante","garito","habitacion", "mesón", "habitación"}),
        "Se trata de un sitio muy acogedor y limpio. Las paredes están pintadas de un"
        " color verdoso y con decoraciones murales en tonos rojos. Un par de decenas de"
        " mesas cuadradas con 4 sillas a su alrededor ocupan toda la estancia, la cual"
        " está ligeramente alumbrada por unas velas situadas en el centro de las mesas.\n");
    AddDetail(({"paredes","pared"}),
        "Destacan por su contraste de color verde y rojo.\n");

    AddFood("kribbat con patatas","un plato de",8,14,0);
    AddFood("kribbat al vino","un plato de",7,13,0);
    AddFood("kribbat estofado","un plato de",8,12,0);
    AddFood("souffle de kribbat","un cuenco de",9,13,0);
    AddFood("kribbat con especias","un plato de",8,13,0);     AddFood("kribbat cuervo negro","un plato de",10,14,0);

    AddExit("norte",CROWY("calle17"));
    SetLocate("Crowy");
    SetKeeper(PNJ_CROWY("mesonero_crowy"));
}
